#include "communicatewithserver.h"

QJsonArray CovertToJsonFormat(const QString& data) {   // return ARRAY!
    QJsonDocument jResponseDocument = QJsonDocument::fromJson(data.toLatin1());
    QJsonArray jResponseArray  = jResponseDocument.array();
    return jResponseArray;
}

QString GetFileNameFromPath(const QString& path) {
    QString resultFileName;

    for (int i = (int)path.size() - 1; i >= 0 && path[i] != '/'; --i) {
        resultFileName += path[i];
    }

    std::reverse(resultFileName.begin(), resultFileName.end());
    return resultFileName;
}

template <class T>
void RemoveAllSpaceSymbols(T& file_name) {
    auto check_symbol = [&](char symbol) {
        return (symbol >= 'a' && symbol <= 'z' ||
                symbol >= 'A' && symbol <= 'Z' ||
                symbol >= '0' && symbol <= '9' ||
                symbol == '!');
    };

    for (auto& symbol : file_name) {
        if (!check_symbol(symbol)) {
            symbol = '#';
        }
    }
}

CommunicateWithServer::CommunicateWithServer() {
    socket = new QTcpSocket(this);

    working_dir_path = QApplication::applicationDirPath() + "/saved-tracks/";
    // if something in the stream of socket -> this how socket will react
    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));

    // if we disconnect -> this how socket will react
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

    socket->connectToHost(kIpAddress, kPort);
    socket->waitForConnected(100);
    isConnected = (socket->state() == QTcpSocket::ConnectedState);

    if (!isConnected) {
        throw std::runtime_error("not connected to the server");
    }
}

void CommunicateWithServer::sockReady() {
    data.clear();
    while (socket->bytesAvailable()) {
        data.append(socket->readAll());
        socket->waitForReadyRead(100);
    }
}

void CommunicateWithServer::sockDisc() {
    socket->deleteLater();
}

QPair<bool, Existance> CommunicateWithServer::CheckAccount(const QString& username, const QString& password) {
    // Check for existance of this user_name
    const QString sql_field_nickname = "user_nickname";
    const QString sql_field_password = "user_password";

    std::string sql_query = QString(
                "SELECT %1, %2 FROM users WHERE %1 ='%3';"
    ).arg(sql_field_nickname, sql_field_password, username).toStdString();

    socket->write(sql_query.c_str());
    socket->waitForReadyRead(500);
    QJsonObject json_response = CovertToJsonFormat(QString(data))[0].toObject();
    QString response_nickname = json_response.value(sql_field_nickname).toString();
    QString response_password = json_response.value(sql_field_password).toString();

    if (response_nickname == username &&
        response_password == password) {
        return {true, Existance::Exist_And_Password_Correct};
    } else {
        return {false, Existance::NotExist};
    }
}

// TODO:
bool CommunicateWithServer::isPasswordContainWrongSymbols(const QString& password) {
    for (const auto& symbol : password) {
        if (wrongSymbols.contains(symbol)) {
            return true;
        }
    }
    return false;
}


void CommunicateWithServer::CreateAccount(const QString& username, const QString& password) {
    const std::string sql_query = QString(
                "INSERT INTO users (user_nickname, user_password) VALUES ('%1', '%2');"
    ).arg(username, password).toStdString();

    socket->write(sql_query.c_str());
}

QStringList CommunicateWithServer::GetUserLikedTracks(const QString& username) {
    // Check for existance of this user_name
    const QString sql_field_song_title= "song_title";
    std::string sql_query = QString(
        "SELECT %1 FROM songs WHERE id_user = (SELECT id FROM users WHERE user_nickname = '%2');"
    ).arg(sql_field_song_title, username).toStdString();

    socket->write(sql_query.c_str());
    socket->waitForReadyRead(500);
    QStringList response_list;
    QJsonArray received_array = CovertToJsonFormat(QString(data));

    for (int i = 0; i < (int)received_array.size(); ++i) {
        QJsonObject j_rsp_object = CovertToJsonFormat(QString(data))[i].toObject();
        response_list.push_back(j_rsp_object.value(sql_field_song_title).toString());
    }

    return response_list;
}

QString CommunicateWithServer::GetFilePathFromServer(const QString & file_name, const QString& dir_path) {
    if (!dir_path.isEmpty()) {
        working_dir_path = dir_path;
    }

    const auto& file_path = working_dir_path + file_name;
    QFile source_file(file_path);

    if (!source_file.exists()) {    // if file already exist -> dont need to download file
        const std::string& request("PLAY: " + file_name.toStdString());
        socket->write(request.c_str());
        socket->waitForReadyRead(1000);
        if (source_file.open(QIODevice::WriteOnly)) {
            source_file.write(data);
        }
    }

    return file_path;
}

bool CommunicateWithServer::UploadFiles(const QStringList& file_pathes, QString account_name) {
    std::string flag = "UPLOAD:";
    std::string std_account_name = account_name.toStdString();
    for (auto& file_path : file_pathes) {
        QFile file(file_path);
        if (file.open(QIODevice::ReadOnly)) {
            std::string file_name = GetFileNameFromPath(file_path).toStdString();
            RemoveAllSpaceSymbols(file_name);
            QByteArray information_to_write = (flag + ' ' + std_account_name + ' ' + file_name + ' ').c_str();
            information_to_write.append(file.readAll());

            qint64 current_progress = 0;
            while (current_progress < information_to_write.size()) {
                current_progress += socket->write(information_to_write);
            }
        }
    }
    socket->waitForReadyRead(1000);

    return false;
}

char* GetCurrentTime() {
    auto current_seconds = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(current_seconds);

    return std::ctime(&current_time);
}

QString TimeConvertFromMiliseconds(qint64 miliseconds) {
    std::stringstream ss;
    const int total_seconds = miliseconds / 1000;
    const int seconds = total_seconds % 60, minutes = total_seconds / 60;
    const int kMaxWidth = 2;

    ss << std::setw(kMaxWidth) << std::setfill('0') << minutes;
    ss << ':';
    ss << std::setw(kMaxWidth) << std::setfill('0') << seconds;
    return QString::fromStdString(ss.str());
}

#include "communicatewithserver.h"

QJsonArray CovertToJsonFormat(const QString& data) {   // return ARRAY!
    QJsonDocument jResponseDocument = QJsonDocument::fromJson(data.toLatin1());
    QJsonArray jResponseArray  = jResponseDocument.array();
    return jResponseArray;
}

CommunicateWithServer::CommunicateWithServer() {
    socket = new QTcpSocket(this);

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
    data = socket->readAll();
}

void CommunicateWithServer::sockDisc() {
    socket->deleteLater();
}

QPair<bool, Existance> CommunicateWithServer::CheckAccount(const QString& username, const QString& password) {
    // Check for existance of this user_name
    const QString sql_field_nickname = "user_nickname";
    const QString sql_field_password = "user_password";


    std::string sql_query = "SELECT " + sql_field_nickname.toStdString() + " FROM users WHERE " +
             sql_field_nickname.toStdString() + " ='" + username.toStdString() + "';";

    socket->write(sql_query.c_str());
    socket->waitForReadyRead(100);
    QJsonObject json_response = CovertToJsonFormat(QString(data))[0].toObject();
    QString response = json_response.value(sql_field_nickname).toString();

    if (!response.isEmpty()) {
        // Check for password correctness
        sql_query = "SELECT " + sql_field_password.toStdString() + " FROM users WHERE " +
                 sql_field_nickname.toStdString() + " ='" + username.toStdString() + "';";

        socket->write(sql_query.c_str());
        socket->waitForReadyRead(100);
        json_response = CovertToJsonFormat(QString(data))[0].toObject();
        response = json_response.value(sql_field_password).toString();

        return {true, (response == password ?
                        Existance::Exist_And_Password_Correct :
                        Existance::Exist)
        };
    } else {
        return {false, Existance::NotExist};
    }
}

bool CommunicateWithServer::isPasswordContainWrongSymbols(const QString& password) {
    for (const auto& symbol : password) {
        if (wrongSymbols.contains(symbol)) {
            return true;
        }
    }
    return false;
}


void CommunicateWithServer::CreateAccount(const QString& username, const QString& password) {
    const std::string sql_query = QString("INSERT INTO users (user_nickname, user_password) "
                                    "VALUES ('%1', '%2');").arg(username, password).toStdString();

    socket->write(sql_query.c_str());
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

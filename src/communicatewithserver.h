#pragma once

// Qt modules
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

// STL lib
#include <sstream>
#include <iomanip>
#include <memory>

enum class Existance {
    NotExist, Exist, Exist_And_Password_Correct
};

class CommunicateWithServer : public QObject {
    Q_OBJECT
public:
    explicit CommunicateWithServer();
    ~CommunicateWithServer() = default;

public slots:
    void sockReady();
    void sockDisc();
    QPair<bool, Existance>  CheckAccount(const QString&, const QString&);
    void CreateAccount(const QString&, const QString&);
    QStringList GetUserLikedTracks(const QString&);
    QString GetFilePathFromServer(const QString&);  // if file with this name does not exist in working_dir -> return new file name
                                       // else return old file name
    bool UploadFiles(const QStringList&, QString);
private: // Private Functions
    bool isPasswordContainWrongSymbols(const QString&);

private: // Private Variables
    QTcpSocket* socket = nullptr;
    const QHostAddress kIpAddress = QHostAddress(QHostAddress::LocalHost);
    const int kPort = 9999;
    QByteArray data;
    bool isConnected = false;

    QString working_dir_path{};
    const QString wrongSymbols = "*/\\.-+,@#№$%^&";
    const int kMinPasswordSize = 8;
};

QJsonArray CovertToJsonFormat(const QString& data);

char* GetCurrentTime();

QString TimeConvertFromMiliseconds(qint64);

QString GetFileNameFromPath(const QString&);

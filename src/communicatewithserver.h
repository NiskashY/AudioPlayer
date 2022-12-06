#pragma once

// Qt modules
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

// shared ptr
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
    void CreateAccount(const QString& username, const QString& password);

private: // Private Functions
    bool isPasswordContainWrongSymbols(const QString&);

private: // Private Variables
    QTcpSocket* socket = nullptr;
    const QHostAddress kIpAddress = QHostAddress(QHostAddress::LocalHost);
    const int kPort = 9999;
    QByteArray data;
    bool isConnected = false;

    const QString wrongSymbols = "*/\\.-+,@#№$%^&";
    const int kMinPasswordSize = 8;
};

QJsonArray CovertToJsonFormat(const QString& data);

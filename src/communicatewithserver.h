#pragma once

#include <QTcpSocket>
#include <QTcpServer>

class CommunicateWithServer : public QObject {
    Q_OBJECT
public:
    explicit CommunicateWithServer();
    ~CommunicateWithServer();

public slots:
    void sockReady();
    void sockDisc();
    bool CheckAccount(const QString&, const QString&);
    void CreateAccount();

private: // Private Functions
    bool isPasswordContainWrongSymbols(const QString&);

private: // Private Variables
    QTcpSocket* socket = nullptr;
    const QHostAddress kIpAddress = QHostAddress(QHostAddress::LocalHost);
    const int kPort = 9999;

    const QString wrongSymbols = "*/\\.-+,@#№$%^&";
    const int kMinPasswordSize = 8;
};

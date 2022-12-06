#include "communicatewithserver.h"

CommunicateWithServer::CommunicateWithServer() {
    socket = new QTcpSocket(this);

    // if something in the stream of socket -> this how socket will react
    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));

    // if we disconnect -> this how socket will react
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

    socket->connectToHost(kIpAddress, kPort);
}


void CommunicateWithServer::sockReady() {

}

void CommunicateWithServer::sockDisc() {

}

bool CommunicateWithServer::CheckAccount(const QString& username, const QString& password) {
    const QString msg_box_error_title = "Registration failed";
    const QString msg_box_success_title = "Cheers!";

    bool isOk = false;
    // паттерн цепочка обязанностей может быть?

    if (username.isEmpty() || password.isEmpty()) {
        //QMessageBox::critical(this, msg_box_error_title, "All fields must be non-empty");
    }
    else if (password.size() < kMinPasswordSize) {
        //QMessageBox::warning(this, msg_box_error_title, QString("Minimal password size is %1").arg(kMinPasswordSize));
    }
    else if (isPasswordContainWrongSymbols(password)) {
        //QMessageBox::warning(this, msg_box_error_title, "Password can't contain " + wrongSymbols);
    } else {
       // QMessageBox::information(this, msg_box_success_title, "You have successfully registered");
        // Push to database
        isOk = true;
    }

    return isOk;
}


bool CommunicateWithServer::isPasswordContainWrongSymbols(const QString& password) {
    for (const auto& symbol : password) {
        if (wrongSymbols.contains(symbol)) {
            return true;
        }
    }
    return false;
}

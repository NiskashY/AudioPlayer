#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QtSql>
#include <QFile>

#include <iostream>
#include <fstream>
#include <string>

#include "loginwindow.h"
#include "mainwindow.h"
#include "mainsss.h"
#include "signupwindow.h"


extern "C" {
#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

int connect(int socket, const struct sockaddr *address, socklen_t address_len);
}

#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Start of Application == Login

    LoginWindow login_window;
    login_window.show();
    SignUpWindow signUp_window;
    signUp_window.show();

    MainWindow mw;
    mw.show();
    mw.close();

    const int& kPort = 9999;
    int sock = 0, valread = 0, client_fd = 0;
    sockaddr_in serv_addr;


    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        int line = __LINE__ + 1;
        std::cout << line << '\n';
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(kPort);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        int line = __LINE__ + 1;
        std::cout << line << '\n';
        return 0;
    }


    client_fd = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if (client_fd < 0) {
        int line = __LINE__ + 1;
        std::cout << line << '\n';
        return 0;
    }

    std::cout << "????????";

    mainsss dw(sock);
    dw.show();

    return a.exec();
}

#ifndef MAINSSS_H
#define MAINSSS_H

#include <QMainWindow>

extern "C" {
#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

int connect(int socket, const struct sockaddr *address, socklen_t address_len);
}


namespace Ui {
class mainsss;
}

class mainsss : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainsss(int sock_, QWidget *parent = nullptr);

    ~mainsss();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mainsss *ui;
    int sock = 0, valread = 0, client_fd = 0;
    sockaddr_in serv_addr;
};

#endif // MAINSSS_H

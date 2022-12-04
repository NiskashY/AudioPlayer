#include "mainsss.h"
#include "ui_mainsss.h"

mainsss::mainsss(int sock_, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainsss)
{
    ui->setupUi(this);
    sock = sock_;
}

mainsss::~mainsss()
{
    delete ui;
}

void mainsss::on_pushButton_clicked()
{
    const std::string& query = "SELECT * FROM users;";
    send(sock, query.c_str(), query.size(), 0);
}


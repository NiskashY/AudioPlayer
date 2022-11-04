#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_signUpButton_clicked()
{
    hide();
    QMessageBox::about(this, "NNN???", "are you participated in NNN ??");
    show();
}


void LoginWindow::on_signInButton_clicked()
{
    QString username_input_value = ui->usernameEditLine->text();
    QString password_input_value = ui->passwordEditLine->text();


}


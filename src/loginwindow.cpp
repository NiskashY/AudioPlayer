#include <QMessageBox>

#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "mainmenu.h"
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Login page");

//    QPixmap pix(":/resourses/songsCovers/sound.jpg");
//    int width  = ui->appCover->width();
//    int height = ui->appCover->height();

//    ui->appCover->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));
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
/*
    QString username_input_value = ui->usernameEditLine->text();
    QString password_input_value = ui->passwordEditLine->text();

    if (username_input_value == "admin" && password_input_value == "admin") {
        hide();
        MainMenu main_menu;
        main_menu.setModal(true);
        main_menu.exec();
        show();
    } else {
        QMessageBox::critical(this, "Authorisation failed", "Wrong username or password");
        // Сообщить о том, что нет такого пользователя
        // или
        // Сообщить, что введенный пароль не верен
    }
*/
}


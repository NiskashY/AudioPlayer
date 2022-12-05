#include <QMessageBox>

#include "loginwindow.h"
#include "ui_loginwindow.h"

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


void LoginWindow::on_SignUpButton_clicked()
{
    this->hide();

    SignUpWindow signUp_form;
    signUp_form.setModal(true);
    signUp_form.exec();

    this->show();
}


void LoginWindow::on_SignInButton_clicked()
{
    QString username_input_value = ui->usernameInput->text();
    QString password_input_value = ui->passwordInput->text();

    if (username_input_value == "admin" && password_input_value == "admin") {
        this->hide();

        MainPage main_page;
        main_page.setModal(true);
        main_page.exec();

        this->show();
    } else {
        QMessageBox::critical(this, "Authorisation failed", "Wrong username or password");
    }
}


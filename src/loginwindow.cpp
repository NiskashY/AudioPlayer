#include <QMessageBox>

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "communicatewithserver.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Login page");
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
    QString username_input_value = "repkep2018";//ui->usernameInput->text();
    QString password_input_value = "repkep2018";//ui->passwordInput->text();

    try {
        CommunicateWithServer server;
        auto result = server.CheckAccount(username_input_value, password_input_value);
        if (result.second == Existance::Exist_And_Password_Correct) {
            this->hide();

            MainPage main_page;
            main_page.setModal(true);
            main_page.exec();

            this->show();
        } else {
            QMessageBox::critical(this, "Authorisation failed", "Wrong username or password");
        }
    } catch (std::runtime_error& e) {
        QMessageBox::critical(this, "Server Problem", e.what());
    }
}


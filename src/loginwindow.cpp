#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(Account*& account, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    main_page_account = account;
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
    QString username_input_value = ui->usernameInput->text();
    QString password_input_value = ui->passwordInput->text();

    try {
        CommunicateWithServer server;
        auto result = server.CheckAccount(username_input_value, password_input_value);
        if (result.second == Existance::Exist_And_Password_Correct) {
            main_page_account->setupAccount(username_input_value, password_input_value);
            this->close();
        } else {
            QMessageBox::critical(this, "Authorisation failed", "Wrong username or password");
        }
    } catch (std::runtime_error& e) {
        QMessageBox::critical(this, "Server Problem", e.what());
    }
}

bool StartLoginProccess(QMainWindow* parent, Account*& account) {
    if (account == nullptr) {
        account = new Account();

        parent->hide();
        LoginWindow lw(account);
        lw.setModal(true);
        lw.exec();
        parent->show();

        if (account->getPassword().isEmpty() || account->getUsername().isEmpty()) {
            delete account;
            return false;
        }
    }
    return true;
}

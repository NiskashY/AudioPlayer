#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign Up page");
}

SignUpWindow::~SignUpWindow() {
    delete ui;
}

void SignUpWindow::on_BackButton_clicked() {
    this->close();
}

bool SignUpWindow::isPasswordContainWrongSymbols(const QString& password) {
    for (const QChar& symbol : password) {
        if (wrongSymbols.contains(symbol)) {
            return true;
        }
    }
    return false;
}

void SignUpWindow::on_RegistreButton_clicked() {
    const QString msg_box_error_title = "Registration failed";
    const QString msg_box_success_title = "Cheers!";

    const QString username_input_value = ui->usernameInput->text();
    const QString password_input_value = ui->passwordInput->text();
    const QString confirm_password_input_value = ui->confirmPasswordInput->text();


    // паттерн цепочка обязанностей может быть?

    if (username_input_value.isEmpty() || password_input_value.isEmpty() || confirm_password_input_value.isEmpty()) {
        QMessageBox::critical(this, msg_box_error_title, "All fields must be non-empty");
    }
    else if (password_input_value.size() < kMinPasswordSize) {
        QMessageBox::warning(this, msg_box_error_title, QString("Minimal password size is %1").arg(kMinPasswordSize));
    }
    else if (isPasswordContainWrongSymbols(password_input_value)) {
        QMessageBox::warning(this, msg_box_error_title, "Password can't contain " + wrongSymbols);
    }
    else if (password_input_value != confirm_password_input_value) {
        QMessageBox::warning(this, msg_box_error_title, "Password and confirmation must match");
    } else {
        QMessageBox::information(this, msg_box_success_title, "You have successfully registered");
        // Push to database
        SignUpWindow::on_BackButton_clicked();
    }
}

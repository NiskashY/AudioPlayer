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

void SignUpWindow::on_RegistreButton_clicked() {
    const QString msg_box_error_title = "Registration failed";
    const QString msg_box_success_title = "Cheers!";
    const QString msg_box_success = "You have successfully registered";

    const QString username_input_value = ui->usernameInput->text();
    const QString password_input_value = ui->passwordInput->text();
    const QString confirm_password_input_value = ui->confirmPasswordInput->text();

    if (confirm_password_input_value.isEmpty()) {
        QMessageBox::warning(this, msg_box_error_title, "All fields must be non-empty");
        return;
    } else if (password_input_value != confirm_password_input_value) {
        QMessageBox::warning(this, msg_box_error_title, "Password and confirmation must match");
        return;
    }

    std::shared_ptr<Checker> wrongSymbolsChecker = std::make_shared<WrongSymbolsChecker>(nullptr);
    std::shared_ptr<Checker> minSizeChecker = std::make_shared<PasswordSizeChecker>(wrongSymbolsChecker);
    std::shared_ptr<Checker> emptyChecker = std::make_shared<EmptyChecker>(minSizeChecker);

    auto [isFieldsOk, error_msg] = emptyChecker->doFilter(username_input_value, password_input_value);

    if (isFieldsOk) {
        QMessageBox::information(this, msg_box_success_title, msg_box_success);
    } else {
        QMessageBox::warning(this, msg_box_error_title, error_msg);
    }

    if (isFieldsOk) {
        SignUpWindow::on_BackButton_clicked();
    }
}

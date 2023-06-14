#pragma once

// Qt modules
#include <QMainWindow>
#include <QMessageBox>

// Custom flies
#include "communicatewithserver.h"
#include "signupwindow.h"
#include "account.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(Account*& account, QWidget *parent = nullptr);
    ~LoginWindow();

private slots:

    void on_SignInButton_clicked();
    void on_SignUpButton_clicked();

private:
    Ui::LoginWindow *ui;
    Account* main_page_account = nullptr;
};

bool StartLoginProccess(QMainWindow* parent, Account*& account);

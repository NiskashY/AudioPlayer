#include "account.h"

void Account::setupAccount(QString username, QString password) {
    this->username = username;
    this->password = password;
}

QString Account::getUsername() const {
    return username;
}

QString Account::getPassword() const {
    return password;
}

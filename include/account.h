#pragma once
#include <QString>

class Account {
public:
    Account() = default;

    void setupAccount(QString username, QString password);
    QString getUsername() const;
    QString getPassword() const;

private:
    QString username;
    QString password;
};

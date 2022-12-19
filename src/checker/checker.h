#pragma once
#include <QPair>
#include <QString>
#include <memory>

class Checker {
public:
    explicit Checker(std::shared_ptr<Checker> next_) :
        next(next_) {}

    virtual QPair<bool, QString> doFilter(const QString&, const QString&) = 0;

    std::shared_ptr<Checker> getNext() const {
        return next;
    }

    virtual ~Checker() {}

protected:
    const int kMinPasswordSize = 8;
    const QString wrongSymbols = "*/\\.-+,@#№$%^& ";
    // Msg for output
    const QString emptyMsg = "Fields must be non-empty";
    const QString minPasswordSizeMsg = QString("Minimal password size is %1").arg(kMinPasswordSize);
    const QString wrongSymbolsMsg = "Password can't contain " + wrongSymbols + "or space";
    const QString successMsg = "All ok";

private:
    std::shared_ptr<Checker> next;
};

class EmptyChecker : public Checker {
public:
    EmptyChecker(std::shared_ptr<Checker> next) : Checker(next) {

    }

    virtual QPair<bool, QString> doFilter(const QString& username, const QString& password);
};


class PasswordSizeChecker : public Checker {
public:
    PasswordSizeChecker(std::shared_ptr<Checker> next) : Checker(next) {

    }

    virtual QPair<bool, QString> doFilter(const QString& username, const QString& password);
};

class WrongSymbolsChecker : public Checker {
public:
    WrongSymbolsChecker(std::shared_ptr<Checker> next) : Checker(next) {

    }

    virtual QPair<bool, QString> doFilter(const QString& username, const QString& password);
};

#include "checker.h"

QPair<bool, QString> EmptyChecker::doFilter(const QString& username, const QString& password) {
    if (username.isEmpty() || password.isEmpty()) {
        return {false, emptyMsg};
    }

    if (getNext() != nullptr) {
        return getNext()->doFilter(username, password);
    } else {
        return {true, successMsg};
    }
}

QPair<bool, QString> PasswordSizeChecker::doFilter(const QString& username, const QString& password) {
    if (password.size() < kMinPasswordSize){
        return {false, minPasswordSizeMsg};
    }

    if (getNext() != nullptr) {
        return getNext()->doFilter(username, password);
    } else {
        return {true, successMsg};
    }
}

QPair<bool, QString> WrongSymbolsChecker::doFilter(const QString& username, const QString& password) {
    for (const auto& symbol : password) {
        if (wrongSymbols.contains(symbol)) {
            return {false, wrongSymbolsMsg};
        }
    }

    if (getNext() != nullptr) {
        return getNext()->doFilter(username, password);
    } else {
        return {true, successMsg};
    }
}

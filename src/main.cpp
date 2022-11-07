#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QtSql>
#include <QFile>

#include <iostream>
#include <fstream>
#include <string>

#include "loginwindow.h"
#include "startwindow.h"

int main(int argc, char *argv[])
{
    const QString& file_with_db_parametrs= ".db_parametrs";
    QFile file_stream(file_with_db_parametrs);
    if (!file_stream.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Cant Open database parametrs file!" << std::endl;
    } else {

        // ReadToList because file_stream.readline() returns "<some strin>\n"
        // because of \n symbol i cant get correct string
        QList wholeFile = file_stream.readLine().split(' ');
        QString driver_name = wholeFile[0];
        QString db_name = wholeFile[1];
        QString user_name = wholeFile[2];
        QString pass = wholeFile[3];
        QString host_name = wholeFile[4];


        QSqlDatabase db = QSqlDatabase::addDatabase(driver_name);
        db.setDatabaseName(db_name);
        db.setHostName(host_name);
        db.setUserName(user_name);
        db.setPassword(pass);

        if (db.open()) {
            QApplication a(argc, argv);
            // Start of Application == Login
            LoginWindow login_window;
            login_window.show();
            return a.exec();
        }
    }


}

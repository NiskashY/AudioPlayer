/********************************************************************************
** Form generated from reading UI file 'mainsss.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSSS_H
#define UI_MAINSSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainsss
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainsss)
    {
        if (mainsss->objectName().isEmpty())
            mainsss->setObjectName(QString::fromUtf8("mainsss"));
        mainsss->resize(800, 600);
        centralwidget = new QWidget(mainsss);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 180, 371, 191));
        mainsss->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainsss);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        mainsss->setMenuBar(menubar);
        statusbar = new QStatusBar(mainsss);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainsss->setStatusBar(statusbar);

        retranslateUi(mainsss);

        QMetaObject::connectSlotsByName(mainsss);
    } // setupUi

    void retranslateUi(QMainWindow *mainsss)
    {
        mainsss->setWindowTitle(QCoreApplication::translate("mainsss", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("mainsss", "SELECT * FROM users;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainsss: public Ui_mainsss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSSS_H

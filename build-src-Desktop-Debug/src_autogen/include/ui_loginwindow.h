/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameEditLine;
    QLabel *passwordLabel;
    QLineEdit *passwordEditLine;
    QPushButton *signUpButton;
    QPushButton *signInButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(837, 600);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 120, 361, 281));
        groupBox->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 40, 331, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(formLayoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameEditLine = new QLineEdit(formLayoutWidget);
        usernameEditLine->setObjectName(QString::fromUtf8("usernameEditLine"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameEditLine);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordEditLine = new QLineEdit(formLayoutWidget);
        passwordEditLine->setObjectName(QString::fromUtf8("passwordEditLine"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEditLine);

        signUpButton = new QPushButton(formLayoutWidget);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));

        formLayout->setWidget(3, QFormLayout::LabelRole, signUpButton);

        signInButton = new QPushButton(formLayoutWidget);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, signInButton);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 60, 251, 421));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Pictures/sound.jpg")));
        label_3->setAlignment(Qt::AlignCenter);
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 837, 23));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginWindow", "Authorization", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        signUpButton->setText(QCoreApplication::translate("LoginWindow", "SignUp", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginWindow", "SignIn", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

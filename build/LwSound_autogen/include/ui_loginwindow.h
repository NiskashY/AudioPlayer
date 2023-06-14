/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *MainForm;
    QHBoxLayout *LogoLayout;
    QLabel *Logo;
    QVBoxLayout *UserNameLayout;
    QHBoxLayout *TextLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *InputLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *usernameInput;
    QVBoxLayout *PasswordLayout;
    QHBoxLayout *TextLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *InputLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *passwordInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *SignInButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *SignUpButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(508, 522);
        horizontalLayout = new QHBoxLayout(LoginWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        MainForm = new QVBoxLayout();
        MainForm->setObjectName(QString::fromUtf8("MainForm"));
        LogoLayout = new QHBoxLayout();
        LogoLayout->setObjectName(QString::fromUtf8("LogoLayout"));
        Logo = new QLabel(LoginWindow);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/resourses/songsCovers/app_logo.png")));
        Logo->setScaledContents(true);
        Logo->setAlignment(Qt::AlignCenter);

        LogoLayout->addWidget(Logo);


        MainForm->addLayout(LogoLayout);

        UserNameLayout = new QVBoxLayout();
        UserNameLayout->setObjectName(QString::fromUtf8("UserNameLayout"));
        TextLayout = new QHBoxLayout();
        TextLayout->setObjectName(QString::fromUtf8("TextLayout"));
        label = new QLabel(LoginWindow);
        label->setObjectName(QString::fromUtf8("label"));

        TextLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout->addItem(horizontalSpacer_2);


        UserNameLayout->addLayout(TextLayout);

        InputLayout = new QHBoxLayout();
        InputLayout->setObjectName(QString::fromUtf8("InputLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout->addItem(horizontalSpacer);

        usernameInput = new QLineEdit(LoginWindow);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));
        usernameInput->setEchoMode(QLineEdit::Normal);

        InputLayout->addWidget(usernameInput);

        InputLayout->setStretch(0, 1);
        InputLayout->setStretch(1, 9);

        UserNameLayout->addLayout(InputLayout);

        UserNameLayout->setStretch(0, 12345);
        UserNameLayout->setStretch(1, 1);

        MainForm->addLayout(UserNameLayout);

        PasswordLayout = new QVBoxLayout();
        PasswordLayout->setObjectName(QString::fromUtf8("PasswordLayout"));
        TextLayout_2 = new QHBoxLayout();
        TextLayout_2->setObjectName(QString::fromUtf8("TextLayout_2"));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        TextLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout_2->addItem(horizontalSpacer_3);


        PasswordLayout->addLayout(TextLayout_2);

        InputLayout_2 = new QHBoxLayout();
        InputLayout_2->setObjectName(QString::fromUtf8("InputLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout_2->addItem(horizontalSpacer_4);

        passwordInput = new QLineEdit(LoginWindow);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);

        InputLayout_2->addWidget(passwordInput);

        InputLayout_2->setStretch(0, 1);
        InputLayout_2->setStretch(1, 9);

        PasswordLayout->addLayout(InputLayout_2);

        PasswordLayout->setStretch(0, 1);
        PasswordLayout->setStretch(1, 1);

        MainForm->addLayout(PasswordLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        MainForm->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        SignInButton = new QPushButton(LoginWindow);
        SignInButton->setObjectName(QString::fromUtf8("SignInButton"));
        SignInButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(SignInButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);

        SignUpButton = new QPushButton(LoginWindow);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));

        horizontalLayout_2->addWidget(SignUpButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(3, 2);
        horizontalLayout_2->setStretch(4, 1);

        MainForm->addLayout(horizontalLayout_2);

        MainForm->setStretch(0, 3);
        MainForm->setStretch(1, 2);
        MainForm->setStretch(2, 2);
        MainForm->setStretch(3, 1);
        MainForm->setStretch(4, 2);

        horizontalLayout->addLayout(MainForm);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        Logo->setText(QString());
        label->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        SignInButton->setText(QCoreApplication::translate("LoginWindow", "Sign IN", nullptr));
        SignUpButton->setText(QCoreApplication::translate("LoginWindow", "Sign UP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

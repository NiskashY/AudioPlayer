/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *MainForm;
    QHBoxLayout *LogoLayout;
    QLabel *Logo;
    QVBoxLayout *UserNameLayout;
    QHBoxLayout *TextLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *InputLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_2;
    QVBoxLayout *PasswordLayout;
    QHBoxLayout *TextLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *InputLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *SignUpButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *SignInButton;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(508, 456);
        LoginWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        MainForm = new QVBoxLayout();
        MainForm->setObjectName(QString::fromUtf8("MainForm"));
        LogoLayout = new QHBoxLayout();
        LogoLayout->setObjectName(QString::fromUtf8("LogoLayout"));
        Logo = new QLabel(centralwidget);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/resourses/songsCovers/sound.jpg")));
        Logo->setAlignment(Qt::AlignCenter);

        LogoLayout->addWidget(Logo);


        MainForm->addLayout(LogoLayout);

        UserNameLayout = new QVBoxLayout();
        UserNameLayout->setObjectName(QString::fromUtf8("UserNameLayout"));
        TextLayout = new QHBoxLayout();
        TextLayout->setObjectName(QString::fromUtf8("TextLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        TextLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout->addItem(horizontalSpacer_2);


        UserNameLayout->addLayout(TextLayout);

        InputLayout = new QHBoxLayout();
        InputLayout->setObjectName(QString::fromUtf8("InputLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout->addItem(horizontalSpacer);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Normal);

        InputLayout->addWidget(lineEdit_2);

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
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        TextLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout_2->addItem(horizontalSpacer_3);


        PasswordLayout->addLayout(TextLayout_2);

        InputLayout_2 = new QHBoxLayout();
        InputLayout_2->setObjectName(QString::fromUtf8("InputLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout_2->addItem(horizontalSpacer_4);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Password);

        InputLayout_2->addWidget(lineEdit);

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
        SignUpButton = new QPushButton(centralwidget);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));

        horizontalLayout_2->addWidget(SignUpButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);

        SignInButton = new QPushButton(centralwidget);
        SignInButton->setObjectName(QString::fromUtf8("SignInButton"));

        horizontalLayout_2->addWidget(SignInButton);


        MainForm->addLayout(horizontalLayout_2);

        MainForm->setStretch(0, 3);
        MainForm->setStretch(1, 1);
        MainForm->setStretch(2, 1);
        MainForm->setStretch(3, 1);
        MainForm->setStretch(4, 1);

        horizontalLayout->addLayout(MainForm);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        Logo->setText(QString());
        label->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        SignUpButton->setText(QCoreApplication::translate("LoginWindow", "Sign IN", nullptr));
        SignInButton->setText(QCoreApplication::translate("LoginWindow", "Sign UP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

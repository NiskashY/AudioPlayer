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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *AuthorizationLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameEditLine;
    QLabel *passwordLabel;
    QLineEdit *passwordEditLine;
    QPushButton *signInButton;
    QPushButton *signUpButton;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *appCoverLayout;
    QLabel *appCover;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(908, 600);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(420, 120, 381, 241));
        AuthorizationLayout = new QVBoxLayout(verticalLayoutWidget);
        AuthorizationLayout->setObjectName(QString::fromUtf8("AuthorizationLayout"));
        AuthorizationLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        usernameLabel = new QLabel(groupBox);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameEditLine = new QLineEdit(groupBox);
        usernameEditLine->setObjectName(QString::fromUtf8("usernameEditLine"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameEditLine);

        passwordLabel = new QLabel(groupBox);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordEditLine = new QLineEdit(groupBox);
        passwordEditLine->setObjectName(QString::fromUtf8("passwordEditLine"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEditLine);

        signInButton = new QPushButton(groupBox);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));
        signInButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(90);
        sizePolicy.setVerticalStretch(90);
        sizePolicy.setHeightForWidth(signInButton->sizePolicy().hasHeightForWidth());
        signInButton->setSizePolicy(sizePolicy);
        signInButton->setIconSize(QSize(40, 16));

        formLayout->setWidget(3, QFormLayout::FieldRole, signInButton);

        signUpButton = new QPushButton(groupBox);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
        signUpButton->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(signUpButton->sizePolicy().hasHeightForWidth());
        signUpButton->setSizePolicy(sizePolicy1);
        signUpButton->setLayoutDirection(Qt::LeftToRight);

        formLayout->setWidget(4, QFormLayout::FieldRole, signUpButton);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer);


        horizontalLayout_2->addLayout(formLayout);


        AuthorizationLayout->addWidget(groupBox);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(90, 120, 311, 241));
        appCoverLayout = new QVBoxLayout(verticalLayoutWidget_2);
        appCoverLayout->setObjectName(QString::fromUtf8("appCoverLayout"));
        appCoverLayout->setContentsMargins(0, 0, 0, 0);
        appCover = new QLabel(verticalLayoutWidget_2);
        appCover->setObjectName(QString::fromUtf8("appCover"));
        appCover->setScaledContents(true);
        appCover->setAlignment(Qt::AlignCenter);

        appCoverLayout->addWidget(appCover);

        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginWindow", "Authorization", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginWindow", "SignIn", nullptr));
        signUpButton->setText(QCoreApplication::translate("LoginWindow", "SignUp", nullptr));
        appCover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

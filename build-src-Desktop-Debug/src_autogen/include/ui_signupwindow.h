/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

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

class Ui_SignUpWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacer_left;
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
    QVBoxLayout *ConfirmLayout;
    QHBoxLayout *TextLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *InputLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_3;
    QHBoxLayout *ButtonsLayout;
    QPushButton *SignUpButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *BackButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *spacer_right;

    void setupUi(QDialog *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName(QString::fromUtf8("SignUpWindow"));
        SignUpWindow->resize(508, 520);
        horizontalLayout = new QHBoxLayout(SignUpWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_left);

        MainForm = new QVBoxLayout();
        MainForm->setObjectName(QString::fromUtf8("MainForm"));
        LogoLayout = new QHBoxLayout();
        LogoLayout->setObjectName(QString::fromUtf8("LogoLayout"));
        Logo = new QLabel(SignUpWindow);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/resourses/songsCovers/sound.jpg")));
        Logo->setAlignment(Qt::AlignCenter);

        LogoLayout->addWidget(Logo);


        MainForm->addLayout(LogoLayout);

        UserNameLayout = new QVBoxLayout();
        UserNameLayout->setObjectName(QString::fromUtf8("UserNameLayout"));
        TextLayout = new QHBoxLayout();
        TextLayout->setObjectName(QString::fromUtf8("TextLayout"));
        label = new QLabel(SignUpWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setScaledContents(true);

        TextLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout->addItem(horizontalSpacer_2);


        UserNameLayout->addLayout(TextLayout);

        InputLayout = new QHBoxLayout();
        InputLayout->setObjectName(QString::fromUtf8("InputLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout->addItem(horizontalSpacer);

        lineEdit_2 = new QLineEdit(SignUpWindow);
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
        label_2 = new QLabel(SignUpWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setScaledContents(true);

        TextLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout_2->addItem(horizontalSpacer_3);


        PasswordLayout->addLayout(TextLayout_2);

        InputLayout_2 = new QHBoxLayout();
        InputLayout_2->setObjectName(QString::fromUtf8("InputLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout_2->addItem(horizontalSpacer_4);

        lineEdit = new QLineEdit(SignUpWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Password);

        InputLayout_2->addWidget(lineEdit);

        InputLayout_2->setStretch(0, 1);
        InputLayout_2->setStretch(1, 9);

        PasswordLayout->addLayout(InputLayout_2);

        PasswordLayout->setStretch(0, 1);
        PasswordLayout->setStretch(1, 1);

        MainForm->addLayout(PasswordLayout);

        ConfirmLayout = new QVBoxLayout();
        ConfirmLayout->setObjectName(QString::fromUtf8("ConfirmLayout"));
        TextLayout_3 = new QHBoxLayout();
        TextLayout_3->setObjectName(QString::fromUtf8("TextLayout_3"));
        label_3 = new QLabel(SignUpWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setScaledContents(true);

        TextLayout_3->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TextLayout_3->addItem(horizontalSpacer_5);


        ConfirmLayout->addLayout(TextLayout_3);

        InputLayout_3 = new QHBoxLayout();
        InputLayout_3->setObjectName(QString::fromUtf8("InputLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InputLayout_3->addItem(horizontalSpacer_6);

        lineEdit_3 = new QLineEdit(SignUpWindow);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEchoMode(QLineEdit::Password);

        InputLayout_3->addWidget(lineEdit_3);

        InputLayout_3->setStretch(0, 1);
        InputLayout_3->setStretch(1, 9);

        ConfirmLayout->addLayout(InputLayout_3);

        ConfirmLayout->setStretch(0, 1);
        ConfirmLayout->setStretch(1, 1);

        MainForm->addLayout(ConfirmLayout);

        ButtonsLayout = new QHBoxLayout();
        ButtonsLayout->setObjectName(QString::fromUtf8("ButtonsLayout"));
        SignUpButton = new QPushButton(SignUpWindow);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));

        ButtonsLayout->addWidget(SignUpButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ButtonsLayout->addItem(verticalSpacer_2);

        BackButton = new QPushButton(SignUpWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        ButtonsLayout->addWidget(BackButton);


        MainForm->addLayout(ButtonsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainForm->addItem(verticalSpacer);

        MainForm->setStretch(0, 3);
        MainForm->setStretch(1, 2);
        MainForm->setStretch(2, 2);
        MainForm->setStretch(3, 2);
        MainForm->setStretch(4, 1);
        MainForm->setStretch(5, 1);

        horizontalLayout->addLayout(MainForm);

        spacer_right = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_right);


        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QDialog *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "Dialog", nullptr));
        Logo->setText(QString());
        label->setText(QCoreApplication::translate("SignUpWindow", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("SignUpWindow", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("SignUpWindow", "Confirm Password:", nullptr));
        SignUpButton->setText(QCoreApplication::translate("SignUpWindow", "Back", nullptr));
        BackButton->setText(QCoreApplication::translate("SignUpWindow", "Sign UP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H

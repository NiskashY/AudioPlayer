/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_26;
    QPushButton *pushButton_25;
    QPushButton *pushButton_24;
    QPushButton *pushButton_23;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_29;
    QPushButton *pushButton_28;
    QPushButton *pushButton_30;
    QPushButton *pushButton_27;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(1309, 674);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_3->addWidget(plainTextEdit);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_26 = new QPushButton(centralwidget);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));

        horizontalLayout_6->addWidget(pushButton_26);

        pushButton_25 = new QPushButton(centralwidget);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));

        horizontalLayout_6->addWidget(pushButton_25);

        pushButton_24 = new QPushButton(centralwidget);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));

        horizontalLayout_6->addWidget(pushButton_24);

        pushButton_23 = new QPushButton(centralwidget);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));

        horizontalLayout_6->addWidget(pushButton_23);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_29 = new QPushButton(centralwidget);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

        horizontalLayout_7->addWidget(pushButton_29);

        pushButton_28 = new QPushButton(centralwidget);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));

        horizontalLayout_7->addWidget(pushButton_28);

        pushButton_30 = new QPushButton(centralwidget);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));

        horizontalLayout_7->addWidget(pushButton_30);

        pushButton_27 = new QPushButton(centralwidget);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

        horizontalLayout_7->addWidget(pushButton_27);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(verticalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 1, 1, 1);

        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 0, 3, 1, 1);

        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout->addWidget(pushButton_17, 1, 2, 1, 1);

        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout->addWidget(pushButton_18, 1, 3, 1, 1);

        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

        gridLayout->addWidget(pushButton_19, 2, 2, 1, 1);

        pushButton_20 = new QPushButton(centralwidget);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));

        gridLayout->addWidget(pushButton_20, 2, 3, 1, 1);

        pushButton_21 = new QPushButton(centralwidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

        gridLayout->addWidget(pushButton_21, 3, 2, 1, 1);

        pushButton_22 = new QPushButton(centralwidget);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));

        gridLayout->addWidget(pushButton_22, 3, 3, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalLayout_5->setStretch(0, 3);
        verticalLayout_5->setStretch(1, 9);
        verticalLayout_5->setStretch(2, 18);

        horizontalLayout_8->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1309, 23));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "MainWindow", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("StartWindow", "0", nullptr));
        pushButton_26->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_25->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_24->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_23->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_29->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_28->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_30->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_27->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_17->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_18->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_19->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_20->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_21->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
        pushButton_22->setText(QCoreApplication::translate("StartWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H

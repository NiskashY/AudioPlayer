/********************************************************************************
** Form generated from reading UI file 'ensuremessagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENSUREMESSAGEBOX_H
#define UI_ENSUREMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EnsureMessageBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *EnsureMessageBox)
    {
        if (EnsureMessageBox->objectName().isEmpty())
            EnsureMessageBox->setObjectName(QString::fromUtf8("EnsureMessageBox"));
        EnsureMessageBox->resize(419, 211);
        verticalLayout_2 = new QVBoxLayout(EnsureMessageBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(EnsureMessageBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(EnsureMessageBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(EnsureMessageBox);

        QMetaObject::connectSlotsByName(EnsureMessageBox);
    } // setupUi

    void retranslateUi(QDialog *EnsureMessageBox)
    {
        EnsureMessageBox->setWindowTitle(QCoreApplication::translate("EnsureMessageBox", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EnsureMessageBox", "Are you sure you want to log out?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnsureMessageBox: public Ui_EnsureMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENSUREMESSAGEBOX_H

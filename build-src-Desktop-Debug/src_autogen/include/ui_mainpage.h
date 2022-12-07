/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *MainWindowLayout;
    QHBoxLayout *TopWindowLayout;
    QVBoxLayout *SidePannelLayout;
    QVBoxLayout *AppLogo;
    QPushButton *backLogo;
    QVBoxLayout *SideMenuLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *SearchLayout;
    QPushButton *addFromDeviceButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *tabsLayout;
    QVBoxLayout *vertLayout;
    QTabWidget *tabWidget;
    QWidget *likedTracks;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *downloadedTracks;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *downVLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *BottomWindowLayout;
    QHBoxLayout *SettingsLayout;
    QVBoxLayout *SongPlayerLayout;
    QHBoxLayout *SliderLayout;
    QSpacerItem *horizontalSpacer_11;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *TrackControllLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *ShuffleButton;
    QPushButton *PrevButton;
    QPushButton *PauseButton;
    QPushButton *NextButton;
    QPushButton *RepeatButton;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QDialog *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QString::fromUtf8("MainPage"));
        MainPage->resize(791, 583);
        verticalLayout = new QVBoxLayout(MainPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MainWindowLayout = new QVBoxLayout();
        MainWindowLayout->setObjectName(QString::fromUtf8("MainWindowLayout"));
        TopWindowLayout = new QHBoxLayout();
        TopWindowLayout->setObjectName(QString::fromUtf8("TopWindowLayout"));
        SidePannelLayout = new QVBoxLayout();
        SidePannelLayout->setSpacing(0);
        SidePannelLayout->setObjectName(QString::fromUtf8("SidePannelLayout"));
        AppLogo = new QVBoxLayout();
        AppLogo->setObjectName(QString::fromUtf8("AppLogo"));
        AppLogo->setSizeConstraint(QLayout::SetMaximumSize);
        AppLogo->setContentsMargins(0, 0, 0, 0);
        backLogo = new QPushButton(MainPage);
        backLogo->setObjectName(QString::fromUtf8("backLogo"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(backLogo->sizePolicy().hasHeightForWidth());
        backLogo->setSizePolicy(sizePolicy);
        backLogo->setMaximumSize(QSize(10000, 10000));

        AppLogo->addWidget(backLogo);


        SidePannelLayout->addLayout(AppLogo);

        SideMenuLayout = new QVBoxLayout();
        SideMenuLayout->setObjectName(QString::fromUtf8("SideMenuLayout"));
        SideMenuLayout->setContentsMargins(0, -1, 0, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SideMenuLayout->addItem(verticalSpacer);

        SearchLayout = new QHBoxLayout();
        SearchLayout->setObjectName(QString::fromUtf8("SearchLayout"));
        SearchLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        addFromDeviceButton = new QPushButton(MainPage);
        addFromDeviceButton->setObjectName(QString::fromUtf8("addFromDeviceButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addFromDeviceButton->sizePolicy().hasHeightForWidth());
        addFromDeviceButton->setSizePolicy(sizePolicy1);

        SearchLayout->addWidget(addFromDeviceButton);

        SearchLayout->setStretch(0, 3);

        SideMenuLayout->addLayout(SearchLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SideMenuLayout->addItem(verticalSpacer_2);


        SidePannelLayout->addLayout(SideMenuLayout);

        SidePannelLayout->setStretch(0, 1);
        SidePannelLayout->setStretch(1, 5);

        TopWindowLayout->addLayout(SidePannelLayout);

        tabsLayout = new QHBoxLayout();
        tabsLayout->setObjectName(QString::fromUtf8("tabsLayout"));
        tabsLayout->setContentsMargins(-1, 0, 0, 0);
        vertLayout = new QVBoxLayout();
        vertLayout->setObjectName(QString::fromUtf8("vertLayout"));
        tabWidget = new QTabWidget(MainPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        likedTracks = new QWidget();
        likedTracks->setObjectName(QString::fromUtf8("likedTracks"));
        horizontalLayout = new QHBoxLayout(likedTracks);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        tabWidget->addTab(likedTracks, QString());
        downloadedTracks = new QWidget();
        downloadedTracks->setObjectName(QString::fromUtf8("downloadedTracks"));
        horizontalLayout_2 = new QHBoxLayout(downloadedTracks);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(downloadedTracks);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 590, 439));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        downVLayout = new QVBoxLayout();
        downVLayout->setObjectName(QString::fromUtf8("downVLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        downVLayout->addItem(verticalSpacer_4);


        verticalLayout_4->addLayout(downVLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        tabWidget->addTab(downloadedTracks, QString());

        vertLayout->addWidget(tabWidget);


        tabsLayout->addLayout(vertLayout);


        TopWindowLayout->addLayout(tabsLayout);

        TopWindowLayout->setStretch(0, 2);
        TopWindowLayout->setStretch(1, 10);

        MainWindowLayout->addLayout(TopWindowLayout);

        BottomWindowLayout = new QHBoxLayout();
        BottomWindowLayout->setObjectName(QString::fromUtf8("BottomWindowLayout"));
        SettingsLayout = new QHBoxLayout();
        SettingsLayout->setObjectName(QString::fromUtf8("SettingsLayout"));

        BottomWindowLayout->addLayout(SettingsLayout);

        SongPlayerLayout = new QVBoxLayout();
        SongPlayerLayout->setObjectName(QString::fromUtf8("SongPlayerLayout"));
        SliderLayout = new QHBoxLayout();
        SliderLayout->setObjectName(QString::fromUtf8("SliderLayout"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SliderLayout->addItem(horizontalSpacer_11);

        horizontalSlider = new QSlider(MainPage);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        SliderLayout->addWidget(horizontalSlider);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SliderLayout->addItem(horizontalSpacer_12);

        SliderLayout->setStretch(0, 1);
        SliderLayout->setStretch(1, 3);
        SliderLayout->setStretch(2, 1);

        SongPlayerLayout->addLayout(SliderLayout);

        TrackControllLayout = new QHBoxLayout();
        TrackControllLayout->setSpacing(20);
        TrackControllLayout->setObjectName(QString::fromUtf8("TrackControllLayout"));
        TrackControllLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TrackControllLayout->addItem(horizontalSpacer_9);

        ShuffleButton = new QPushButton(MainPage);
        ShuffleButton->setObjectName(QString::fromUtf8("ShuffleButton"));

        TrackControllLayout->addWidget(ShuffleButton);

        PrevButton = new QPushButton(MainPage);
        PrevButton->setObjectName(QString::fromUtf8("PrevButton"));

        TrackControllLayout->addWidget(PrevButton);

        PauseButton = new QPushButton(MainPage);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        PauseButton->setIconSize(QSize(5, 5));

        TrackControllLayout->addWidget(PauseButton);

        NextButton = new QPushButton(MainPage);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));

        TrackControllLayout->addWidget(NextButton);

        RepeatButton = new QPushButton(MainPage);
        RepeatButton->setObjectName(QString::fromUtf8("RepeatButton"));

        TrackControllLayout->addWidget(RepeatButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TrackControllLayout->addItem(horizontalSpacer_10);


        SongPlayerLayout->addLayout(TrackControllLayout);


        BottomWindowLayout->addLayout(SongPlayerLayout);

        BottomWindowLayout->setStretch(0, 1);
        BottomWindowLayout->setStretch(1, 10);

        MainWindowLayout->addLayout(BottomWindowLayout);


        verticalLayout->addLayout(MainWindowLayout);


        retranslateUi(MainPage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QDialog *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Dialog", nullptr));
        backLogo->setText(QString());
        addFromDeviceButton->setText(QCoreApplication::translate("MainPage", "Add Track From Device", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(likedTracks), QCoreApplication::translate("MainPage", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(downloadedTracks), QCoreApplication::translate("MainPage", "Tab 2", nullptr));
        ShuffleButton->setText(QCoreApplication::translate("MainPage", "SHUFFLE", nullptr));
        PrevButton->setText(QCoreApplication::translate("MainPage", "PREV", nullptr));
        PauseButton->setText(QCoreApplication::translate("MainPage", "PAUSE", nullptr));
        NextButton->setText(QCoreApplication::translate("MainPage", "NEXT", nullptr));
        RepeatButton->setText(QCoreApplication::translate("MainPage", "REPEAT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H

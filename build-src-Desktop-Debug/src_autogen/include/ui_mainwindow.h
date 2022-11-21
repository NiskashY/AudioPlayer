/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *MainWindowLayout;
    QHBoxLayout *TopWindowLayout;
    QVBoxLayout *SidePannelLayout;
    QVBoxLayout *AppLogo;
    QLabel *Logo;
    QVBoxLayout *SideMenuLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *LikesLayout;
    QPushButton *DownloadedTracksButton;
    QHBoxLayout *DownloadedLayout;
    QPushButton *SearchTracksButton;
    QHBoxLayout *SearchLayout;
    QPushButton *LikedTracksButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *SongInfoLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *vertLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *SongCover;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(885, 553);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MainWindowLayout = new QVBoxLayout();
        MainWindowLayout->setObjectName(QString::fromUtf8("MainWindowLayout"));
        TopWindowLayout = new QHBoxLayout();
        TopWindowLayout->setObjectName(QString::fromUtf8("TopWindowLayout"));
        SidePannelLayout = new QVBoxLayout();
        SidePannelLayout->setSpacing(0);
        SidePannelLayout->setObjectName(QString::fromUtf8("SidePannelLayout"));
        AppLogo = new QVBoxLayout();
        AppLogo->setObjectName(QString::fromUtf8("AppLogo"));
        AppLogo->setSizeConstraint(QLayout::SetMinimumSize);
        AppLogo->setContentsMargins(20, 20, 20, 20);
        Logo = new QLabel(centralwidget);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Logo->sizePolicy().hasHeightForWidth());
        Logo->setSizePolicy(sizePolicy);
        Logo->setMinimumSize(QSize(20, 40));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/resourses/songsCovers/sound.jpg")));
        Logo->setScaledContents(true);

        AppLogo->addWidget(Logo);


        SidePannelLayout->addLayout(AppLogo);

        SideMenuLayout = new QVBoxLayout();
        SideMenuLayout->setObjectName(QString::fromUtf8("SideMenuLayout"));
        SideMenuLayout->setContentsMargins(0, -1, 0, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SideMenuLayout->addItem(verticalSpacer);

        LikesLayout = new QHBoxLayout();
        LikesLayout->setObjectName(QString::fromUtf8("LikesLayout"));
        LikesLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        DownloadedTracksButton = new QPushButton(centralwidget);
        DownloadedTracksButton->setObjectName(QString::fromUtf8("DownloadedTracksButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DownloadedTracksButton->sizePolicy().hasHeightForWidth());
        DownloadedTracksButton->setSizePolicy(sizePolicy1);

        LikesLayout->addWidget(DownloadedTracksButton);

        LikesLayout->setStretch(0, 3);

        SideMenuLayout->addLayout(LikesLayout);

        DownloadedLayout = new QHBoxLayout();
        DownloadedLayout->setSpacing(0);
        DownloadedLayout->setObjectName(QString::fromUtf8("DownloadedLayout"));
        DownloadedLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        DownloadedLayout->setContentsMargins(0, -1, -1, -1);
        SearchTracksButton = new QPushButton(centralwidget);
        SearchTracksButton->setObjectName(QString::fromUtf8("SearchTracksButton"));
        sizePolicy1.setHeightForWidth(SearchTracksButton->sizePolicy().hasHeightForWidth());
        SearchTracksButton->setSizePolicy(sizePolicy1);

        DownloadedLayout->addWidget(SearchTracksButton);


        SideMenuLayout->addLayout(DownloadedLayout);

        SearchLayout = new QHBoxLayout();
        SearchLayout->setObjectName(QString::fromUtf8("SearchLayout"));
        SearchLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        LikedTracksButton = new QPushButton(centralwidget);
        LikedTracksButton->setObjectName(QString::fromUtf8("LikedTracksButton"));
        sizePolicy1.setHeightForWidth(LikedTracksButton->sizePolicy().hasHeightForWidth());
        LikedTracksButton->setSizePolicy(sizePolicy1);

        SearchLayout->addWidget(LikedTracksButton);

        SearchLayout->setStretch(0, 3);

        SideMenuLayout->addLayout(SearchLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SideMenuLayout->addItem(verticalSpacer_2);


        SidePannelLayout->addLayout(SideMenuLayout);

        SidePannelLayout->setStretch(0, 1);
        SidePannelLayout->setStretch(1, 5);

        TopWindowLayout->addLayout(SidePannelLayout);

        SongInfoLayout = new QHBoxLayout();
        SongInfoLayout->setObjectName(QString::fromUtf8("SongInfoLayout"));
        SongInfoLayout->setContentsMargins(-1, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SongInfoLayout->addItem(horizontalSpacer);

        vertLayout = new QVBoxLayout();
        vertLayout->setObjectName(QString::fromUtf8("vertLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertLayout->addItem(verticalSpacer_4);

        SongCover = new QLabel(centralwidget);
        SongCover->setObjectName(QString::fromUtf8("SongCover"));
        SongCover->setPixmap(QPixmap(QString::fromUtf8(":/resourses/songsCovers/default_song_cover.jpg")));
        SongCover->setScaledContents(true);
        SongCover->setAlignment(Qt::AlignCenter);
        SongCover->setMargin(0);
        SongCover->setIndent(0);

        vertLayout->addWidget(SongCover);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertLayout->addItem(verticalSpacer_3);


        SongInfoLayout->addLayout(vertLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SongInfoLayout->addItem(horizontalSpacer_2);

        SongInfoLayout->setStretch(0, 1);
        SongInfoLayout->setStretch(2, 1);

        TopWindowLayout->addLayout(SongInfoLayout);

        TopWindowLayout->setStretch(0, 1);
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

        horizontalSlider = new QSlider(centralwidget);
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

        ShuffleButton = new QPushButton(centralwidget);
        ShuffleButton->setObjectName(QString::fromUtf8("ShuffleButton"));

        TrackControllLayout->addWidget(ShuffleButton);

        PrevButton = new QPushButton(centralwidget);
        PrevButton->setObjectName(QString::fromUtf8("PrevButton"));

        TrackControllLayout->addWidget(PrevButton);

        PauseButton = new QPushButton(centralwidget);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        PauseButton->setIconSize(QSize(5, 5));

        TrackControllLayout->addWidget(PauseButton);

        NextButton = new QPushButton(centralwidget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));

        TrackControllLayout->addWidget(NextButton);

        RepeatButton = new QPushButton(centralwidget);
        RepeatButton->setObjectName(QString::fromUtf8("RepeatButton"));

        TrackControllLayout->addWidget(RepeatButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TrackControllLayout->addItem(horizontalSpacer_10);


        SongPlayerLayout->addLayout(TrackControllLayout);


        BottomWindowLayout->addLayout(SongPlayerLayout);

        BottomWindowLayout->setStretch(0, 1);
        BottomWindowLayout->setStretch(1, 10);

        MainWindowLayout->addLayout(BottomWindowLayout);


        horizontalLayout_2->addLayout(MainWindowLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 885, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Logo->setText(QString());
        DownloadedTracksButton->setText(QCoreApplication::translate("MainWindow", "Likes", nullptr));
        SearchTracksButton->setText(QCoreApplication::translate("MainWindow", "Donwloaded", nullptr));
        LikedTracksButton->setText(QCoreApplication::translate("MainWindow", "SearchEngine", nullptr));
        SongCover->setText(QString());
        ShuffleButton->setText(QCoreApplication::translate("MainWindow", "SHUFFLE", nullptr));
        PrevButton->setText(QCoreApplication::translate("MainWindow", "PREV", nullptr));
        PauseButton->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        NextButton->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        RepeatButton->setText(QCoreApplication::translate("MainWindow", "REPEAT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

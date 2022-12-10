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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *MainWindowLayout;
    QHBoxLayout *TopWindowLayout;
    QVBoxLayout *SidePannelLayout;
    QVBoxLayout *AppLogo;
    QPushButton *exitAccountButton;
    QVBoxLayout *SideMenuLayout;
    QLabel *timeInfoLabel;
    QLabel *lastUpdateTimeLabel;
    QSpacerItem *verticalSpacer;
    QLabel *accountLabel;
    QSpacerItem *verticalSpacer_3;
    QPushButton *changeDirButton;
    QHBoxLayout *SearchLayout;
    QPushButton *addFromDeviceButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *tabsLayout;
    QVBoxLayout *vertLayout;
    QTabWidget *tabWidget;
    QWidget *likedTracks;
    QHBoxLayout *horizontalLayout_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContentsLikes;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *likesVLayout;
    QWidget *downloadedTracks;
    QHBoxLayout *horizontalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContentsDownload;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *downVLayout;
    QHBoxLayout *BottomWindowLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *volumeLayout;
    QLabel *label;
    QHBoxLayout *volumeSliderLayout;
    QSlider *verticalSlider;
    QVBoxLayout *SongPlayerLayout;
    QHBoxLayout *SongNameLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *songNameLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *SliderLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QLabel *currentTimeLabel;
    QSlider *songSlider;
    QLabel *totalTimeLabel;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *TrackControllLayout;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *shuffleButton;
    QPushButton *prevButton;
    QPushButton *pauseButton;
    QPushButton *nextButton;
    QPushButton *repeatButton;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QMainWindow *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QString::fromUtf8("MainPage"));
        MainPage->resize(946, 600);
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_7 = new QHBoxLayout(centralwidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
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
        exitAccountButton = new QPushButton(centralwidget);
        exitAccountButton->setObjectName(QString::fromUtf8("exitAccountButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(exitAccountButton->sizePolicy().hasHeightForWidth());
        exitAccountButton->setSizePolicy(sizePolicy);
        exitAccountButton->setMaximumSize(QSize(10000, 10000));

        AppLogo->addWidget(exitAccountButton);


        SidePannelLayout->addLayout(AppLogo);

        SideMenuLayout = new QVBoxLayout();
        SideMenuLayout->setObjectName(QString::fromUtf8("SideMenuLayout"));
        SideMenuLayout->setContentsMargins(0, -1, 0, -1);
        timeInfoLabel = new QLabel(centralwidget);
        timeInfoLabel->setObjectName(QString::fromUtf8("timeInfoLabel"));

        SideMenuLayout->addWidget(timeInfoLabel);

        lastUpdateTimeLabel = new QLabel(centralwidget);
        lastUpdateTimeLabel->setObjectName(QString::fromUtf8("lastUpdateTimeLabel"));

        SideMenuLayout->addWidget(lastUpdateTimeLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SideMenuLayout->addItem(verticalSpacer);

        accountLabel = new QLabel(centralwidget);
        accountLabel->setObjectName(QString::fromUtf8("accountLabel"));
        accountLabel->setAlignment(Qt::AlignCenter);

        SideMenuLayout->addWidget(accountLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SideMenuLayout->addItem(verticalSpacer_3);

        changeDirButton = new QPushButton(centralwidget);
        changeDirButton->setObjectName(QString::fromUtf8("changeDirButton"));

        SideMenuLayout->addWidget(changeDirButton);

        SearchLayout = new QHBoxLayout();
        SearchLayout->setObjectName(QString::fromUtf8("SearchLayout"));
        SearchLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        addFromDeviceButton = new QPushButton(centralwidget);
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        likedTracks = new QWidget();
        likedTracks->setObjectName(QString::fromUtf8("likedTracks"));
        horizontalLayout_5 = new QHBoxLayout(likedTracks);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        scrollArea_2 = new QScrollArea(likedTracks);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContentsLikes = new QWidget();
        scrollAreaWidgetContentsLikes->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsLikes"));
        scrollAreaWidgetContentsLikes->setGeometry(QRect(0, 0, 723, 428));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContentsLikes);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        likesVLayout = new QVBoxLayout();
        likesVLayout->setObjectName(QString::fromUtf8("likesVLayout"));

        verticalLayout_7->addLayout(likesVLayout);

        scrollArea_2->setWidget(scrollAreaWidgetContentsLikes);

        horizontalLayout_5->addWidget(scrollArea_2);

        tabWidget->addTab(likedTracks, QString());
        downloadedTracks = new QWidget();
        downloadedTracks->setObjectName(QString::fromUtf8("downloadedTracks"));
        horizontalLayout_6 = new QHBoxLayout(downloadedTracks);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        scrollArea = new QScrollArea(downloadedTracks);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContentsDownload = new QWidget();
        scrollAreaWidgetContentsDownload->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsDownload"));
        scrollAreaWidgetContentsDownload->setGeometry(QRect(0, 0, 723, 428));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContentsDownload);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        downVLayout = new QVBoxLayout();
        downVLayout->setObjectName(QString::fromUtf8("downVLayout"));

        verticalLayout_8->addLayout(downVLayout);

        scrollArea->setWidget(scrollAreaWidgetContentsDownload);

        horizontalLayout_6->addWidget(scrollArea);

        tabWidget->addTab(downloadedTracks, QString());

        vertLayout->addWidget(tabWidget);


        tabsLayout->addLayout(vertLayout);


        TopWindowLayout->addLayout(tabsLayout);

        TopWindowLayout->setStretch(0, 2);
        TopWindowLayout->setStretch(1, 9);

        MainWindowLayout->addLayout(TopWindowLayout);

        BottomWindowLayout = new QHBoxLayout();
        BottomWindowLayout->setObjectName(QString::fromUtf8("BottomWindowLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BottomWindowLayout->addItem(horizontalSpacer_3);

        volumeLayout = new QVBoxLayout();
        volumeLayout->setObjectName(QString::fromUtf8("volumeLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        volumeLayout->addWidget(label);

        volumeSliderLayout = new QHBoxLayout();
        volumeSliderLayout->setObjectName(QString::fromUtf8("volumeSliderLayout"));
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMaximum(100);
        verticalSlider->setOrientation(Qt::Vertical);

        volumeSliderLayout->addWidget(verticalSlider);


        volumeLayout->addLayout(volumeSliderLayout);


        BottomWindowLayout->addLayout(volumeLayout);

        SongPlayerLayout = new QVBoxLayout();
        SongPlayerLayout->setObjectName(QString::fromUtf8("SongPlayerLayout"));
        SongNameLayout = new QHBoxLayout();
        SongNameLayout->setObjectName(QString::fromUtf8("SongNameLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SongNameLayout->addItem(horizontalSpacer);

        songNameLabel = new QLabel(centralwidget);
        songNameLabel->setObjectName(QString::fromUtf8("songNameLabel"));

        SongNameLayout->addWidget(songNameLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SongNameLayout->addItem(horizontalSpacer_2);


        SongPlayerLayout->addLayout(SongNameLayout);

        SliderLayout_3 = new QHBoxLayout();
        SliderLayout_3->setObjectName(QString::fromUtf8("SliderLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SliderLayout_3->addItem(horizontalSpacer_11);

        currentTimeLabel = new QLabel(centralwidget);
        currentTimeLabel->setObjectName(QString::fromUtf8("currentTimeLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(currentTimeLabel->sizePolicy().hasHeightForWidth());
        currentTimeLabel->setSizePolicy(sizePolicy2);

        SliderLayout_3->addWidget(currentTimeLabel);

        songSlider = new QSlider(centralwidget);
        songSlider->setObjectName(QString::fromUtf8("songSlider"));
        songSlider->setOrientation(Qt::Horizontal);

        SliderLayout_3->addWidget(songSlider);

        totalTimeLabel = new QLabel(centralwidget);
        totalTimeLabel->setObjectName(QString::fromUtf8("totalTimeLabel"));
        sizePolicy2.setHeightForWidth(totalTimeLabel->sizePolicy().hasHeightForWidth());
        totalTimeLabel->setSizePolicy(sizePolicy2);

        SliderLayout_3->addWidget(totalTimeLabel);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SliderLayout_3->addItem(horizontalSpacer_12);

        SliderLayout_3->setStretch(0, 1);
        SliderLayout_3->setStretch(2, 3);
        SliderLayout_3->setStretch(4, 1);

        SongPlayerLayout->addLayout(SliderLayout_3);

        TrackControllLayout = new QHBoxLayout();
        TrackControllLayout->setSpacing(20);
        TrackControllLayout->setObjectName(QString::fromUtf8("TrackControllLayout"));
        TrackControllLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TrackControllLayout->addItem(horizontalSpacer_10);

        shuffleButton = new QPushButton(centralwidget);
        shuffleButton->setObjectName(QString::fromUtf8("shuffleButton"));
        sizePolicy2.setHeightForWidth(shuffleButton->sizePolicy().hasHeightForWidth());
        shuffleButton->setSizePolicy(sizePolicy2);

        TrackControllLayout->addWidget(shuffleButton);

        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        sizePolicy2.setHeightForWidth(prevButton->sizePolicy().hasHeightForWidth());
        prevButton->setSizePolicy(sizePolicy2);

        TrackControllLayout->addWidget(prevButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        sizePolicy2.setHeightForWidth(pauseButton->sizePolicy().hasHeightForWidth());
        pauseButton->setSizePolicy(sizePolicy2);
        pauseButton->setIconSize(QSize(5, 5));

        TrackControllLayout->addWidget(pauseButton);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        sizePolicy2.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy2);

        TrackControllLayout->addWidget(nextButton);

        repeatButton = new QPushButton(centralwidget);
        repeatButton->setObjectName(QString::fromUtf8("repeatButton"));
        sizePolicy2.setHeightForWidth(repeatButton->sizePolicy().hasHeightForWidth());
        repeatButton->setSizePolicy(sizePolicy2);

        TrackControllLayout->addWidget(repeatButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TrackControllLayout->addItem(horizontalSpacer_9);

        TrackControllLayout->setStretch(0, 2);
        TrackControllLayout->setStretch(1, 2);
        TrackControllLayout->setStretch(2, 2);
        TrackControllLayout->setStretch(3, 2);
        TrackControllLayout->setStretch(4, 2);
        TrackControllLayout->setStretch(5, 2);
        TrackControllLayout->setStretch(6, 2);

        SongPlayerLayout->addLayout(TrackControllLayout);

        SongPlayerLayout->setStretch(0, 1);
        SongPlayerLayout->setStretch(1, 1);
        SongPlayerLayout->setStretch(2, 2);

        BottomWindowLayout->addLayout(SongPlayerLayout);

        BottomWindowLayout->setStretch(1, 1);
        BottomWindowLayout->setStretch(2, 10);

        MainWindowLayout->addLayout(BottomWindowLayout);

        MainWindowLayout->setStretch(0, 6);
        MainWindowLayout->setStretch(1, 1);

        horizontalLayout_7->addLayout(MainWindowLayout);

        MainPage->setCentralWidget(centralwidget);

        retranslateUi(MainPage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QMainWindow *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "MainWindow", nullptr));
        exitAccountButton->setText(QString());
        timeInfoLabel->setText(QCoreApplication::translate("MainPage", "Last Update Time:", nullptr));
        lastUpdateTimeLabel->setText(QString());
        accountLabel->setText(QString());
        changeDirButton->setText(QCoreApplication::translate("MainPage", "Change Standard Dir", nullptr));
        addFromDeviceButton->setText(QCoreApplication::translate("MainPage", " Add From Device ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(likedTracks), QCoreApplication::translate("MainPage", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(downloadedTracks), QCoreApplication::translate("MainPage", "Tab 2", nullptr));
        label->setText(QCoreApplication::translate("MainPage", "Volume", nullptr));
        songNameLabel->setText(QString());
        currentTimeLabel->setText(QCoreApplication::translate("MainPage", "00:00", nullptr));
        totalTimeLabel->setText(QCoreApplication::translate("MainPage", "00:00", nullptr));
        shuffleButton->setText(QString());
        prevButton->setText(QString());
        pauseButton->setText(QString());
        nextButton->setText(QString());
        repeatButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H

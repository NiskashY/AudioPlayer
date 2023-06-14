#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScreen>
#include <QApplication>

namespace {     

void centreWidget(QWidget* w) {
    int width = w->frameGeometry().width();
    int height = w->frameGeometry().height();

    auto screen = QApplication::primaryScreen();

    int screenWidth = screen->geometry().width();
    int screenHeight = screen->geometry().height();

    w->setGeometry((screenWidth/2)-(width/2), (screenHeight/2)-(height/2), width, height);
}

void uiSetImagesToButtons(Ui::MainWindow* ui) {
    // Set Images To Buttons on Main Page
    const QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);";

    ui->exitAccountButton->setStyleSheet(style_sheet_parametr.arg("exit_account.png"));
    ui->shuffleButton->setStyleSheet(style_sheet_parametr.arg("shuffle_song.png"));
    ui->prevButton->setStyleSheet(style_sheet_parametr.arg("prev_song.png"));
    ui->pauseButton->setStyleSheet(style_sheet_parametr.arg("query_song.png"));
    ui->nextButton->setStyleSheet(style_sheet_parametr.arg("next_song.png"));
    ui->repeatButton->setStyleSheet(style_sheet_parametr.arg("repeat_song.png"));
}

void uiSetLabels(Ui::MainWindow* ui) {
    // Setting Up labels for tabs
    const int kLikedTracksPos = 0, kDownloadedTracksPos = 1;
    ui->tabWidget->setTabText(kLikedTracksPos, "Liked Tracks");
    ui->tabWidget->setTabText(kDownloadedTracksPos, "Downloaded Tracks");

    // Set Account Label
    ui->accountLabel->setText("Account is not selected");
    ui->standardDirLabel->setText(".../saved-tracks/");
    ui->standardDirLabel->setStyleSheet("QLabel { color : orange; }");
}

void uiInitializeTab(Ui::MainWindow* ui) {
    // Initialize layout with spacer
    const int kNeededPosOfLayout = 1;
    auto current_tab = qobject_cast<QWidget*>(ui->tabWidget->currentWidget());
    const auto& current_tab_layouts  = current_tab->findChildren<QVBoxLayout*>();
    auto current_tab_layout = current_tab_layouts.at(kNeededPosOfLayout);
    current_tab_layout->addStretch(2);
}

void initializePlayer(auto ui, auto& player, auto& active, auto& received) {
    // Initialize player
    player = new QMediaPlayer();
    active = new QMediaPlaylist();
    received = new QMediaPlaylist();
    player->setPlaylist(active);
    player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
    
    // Setup Volume of sound and ui elements for this
    const int& kSoundVolume = 10;
    ui->verticalSlider->setSliderPosition(kSoundVolume);
    player->setVolume(kSoundVolume);
}

QString getWorkingDir() {
    auto path = QApplication::applicationDirPath() + "/saved-tracks/";
    QDir dir(path);
    if (!dir.exists())
        dir.mkpath("."); 
    return path;
}

}   // end anonymous namespace

void MainWindow::ConnectionHandler(bool isConnect) {
    if (isConnect) {
            // Connect Sound Signals for player and UI
            connect (
                    player, &QMediaPlayer::positionChanged,
                    this, &MainWindow::SetCurrentSliderPosition
            ); // song 'progress bar' update

            connect (
                    player, &QMediaPlayer::durationChanged,
                    this, &MainWindow::SetMaxSliderPosition
            ); // song time update
            connect (
                    player, &QMediaPlayer::currentMediaChanged,
                    this, &MainWindow::SetSongNameLabel
            ); // song name update
            connect (
                    ui->songSlider, &QSlider::sliderMoved,
                    this, &MainWindow::SliderPositionMoved
            ); // slider moved -> change position in the soundtrack
            connect (
                    ui->songSlider, &QSlider::sliderPressed,
                    this, &MainWindow::PauseFromSLider
            ); // slider pause -> avoid sound interferences
            connect (
                    ui->songSlider, &QSlider::sliderReleased,
                    this, &MainWindow::PlayFromSLider
            ); // slider released -> continue playing
        } else {
            // Disconnect  Sound Signals for player and UI
            disconnect (
                    player, &QMediaPlayer::positionChanged,
                    this, &MainWindow::SetCurrentSliderPosition
            ); // song 'progress bar' update

            disconnect (
                    player, &QMediaPlayer::durationChanged,
                    this, &MainWindow::SetMaxSliderPosition
            ); // song time update
            disconnect (
                    player, &QMediaPlayer::currentMediaChanged,
                    this, &MainWindow::SetSongNameLabel
            ); // song name update
            disconnect (
                    ui->songSlider, &QSlider::sliderMoved,
                    this, &MainWindow::SliderPositionMoved
            ); // slider moved -> change position in the soundtrack
            disconnect (
                    ui->songSlider, &QSlider::sliderPressed,
                    this, &MainWindow::PauseFromSLider
            ); // slider pause -> avoid sound interferences
            disconnect (
                    ui->songSlider, &QSlider::sliderReleased,
                    this, &MainWindow::PlayFromSLider
            ); // slider released -> continue playing
        }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Main Page");

    // Center current window
    centreWidget(this);

    uiSetImagesToButtons(ui);
    uiSetLabels(ui);
    uiInitializeTab(ui);
    initializePlayer(ui, player, active_playlist, received_playlist);

    // Initialise current working_dir with application folder
    working_dir_path = getWorkingDir();

    // Refresh Page
    Q_EMIT ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());

    // Connect Sound Signals for player and UI
    MainWindow::ConnectionHandler(true); // connect slots
}

MainWindow::~MainWindow() {
    MainWindow::ConnectionHandler(false); // disconnect slots
    delete ui;
    player->stop();
    player->playlist()->clear();
    delete received_playlist;
    delete active_playlist;
    delete player;
}


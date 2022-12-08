#include "mainpage.h"
#include "ui_mainpage.h"

#include <QSpacerItem>

QString GetFileNameFromPath(const QString& path) {
    QString resultFileName;

    for (int i = (int)path.size() - 1; i >= 0 && path[i] != '/'; --i) {
        resultFileName += path[i];
    }

    std::reverse(resultFileName.begin(), resultFileName.end());
    return resultFileName;
}


MainPage::MainPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Page");

    // Set Images To Buttons on Main Page
    QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);";
    ui->backLogo->setStyleSheet(style_sheet_parametr.arg("sound.jpg"));
    ui->shuffleButton->setStyleSheet(style_sheet_parametr.arg("shuffle_song.png"));
    ui->prevButton->setStyleSheet(style_sheet_parametr.arg("prev_song.png"));
    ui->pauseButton->setStyleSheet(style_sheet_parametr.arg("query_song.png"));
    ui->nextButton->setStyleSheet(style_sheet_parametr.arg("next_song.png"));
    ui->repeatButton->setStyleSheet(style_sheet_parametr.arg("repeat_song.png"));

    // Setting Up labels for tabs
    const int kLikedTracksPos = 0, kDownloadedTracksPos = 1;
    ui->tabWidget->setTabText(kLikedTracksPos, "Liked Tracks");
    ui->tabWidget->setTabText(kDownloadedTracksPos, "Downloaded sTracks");

    // Initialize layout with spacer
    const int kNeededPosOfLayout = 1;
    auto current_tab = qobject_cast<QWidget*>(ui->tabWidget->currentWidget());
    auto current_tab_layouts = current_tab->findChildren<QVBoxLayout*>();
    auto current_tab_layout = current_tab_layouts.at(kNeededPosOfLayout);
    current_tab_layout->addStretch(2);

    ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());  // Refresh likes page

    player = new QMediaPlayer();
    active_playlist = new QMediaPlaylist();
    received_playlist = new QMediaPlaylist();
    player->setPlaylist(active_playlist);
}

MainPage::~MainPage()
{
    delete ui;
    player->stop();
    delete player;
}

void MainPage::on_backLogo_clicked()
{
    this->close();
}

void MainPage::on_addFromDeviceButton_clicked() {
    QFileDialog dirWindow(this);
    dirWindow.setWindowTitle("Select Music File");
    dirWindow.setFileMode(QFileDialog::ExistingFile);
    dirWindow.setNameFilter("Audio files (*.mp3 *.wav)");
    dirWindow.setDirectory(QApplication::applicationDirPath());

    if (dirWindow.exec()) {
        QStringList selectedFiles = dirWindow.selectedFiles();

        // Copying Files if they not in ..../Audioplayer/*
        for (const auto& file_path : selectedFiles) {
            QString file_name = GetFileNameFromPath(file_path);
            QFile::copy(file_path, working_dir_path + file_name);
        }

        ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());
    }
}

QHBoxLayout* MainPage::CreateSongLayout(QWidget*& parent_widget,
                                        const QString& file_name,
                                        bool isDownloaded = false)
{
    QHBoxLayout* song_layout = new QHBoxLayout(parent_widget);
    QPushButton* play_button = new QPushButton("", parent_widget);
    play_button->setStyleSheet("border-image:url(:/resourses/songsCovers/query_song.png);");
    song_layout->addWidget(play_button);
    song_layout->addStretch(2);     // Add Stretchable Spacer Item

    QLabel* song_label = new QLabel(file_name, parent_widget);
    song_layout->addWidget(song_label);
    song_layout->addStretch(2);     // Add Stretchable Spacer Item

    QCheckBox* checkBoxDownloaded = new QCheckBox("download", parent_widget);
    checkBoxDownloaded->setChecked(Qt::CheckState(downloadedFiles.contains(file_name)));
    checkBoxDownloaded->setEnabled(Qt::CheckState(!isDownloaded));

    song_layout->addWidget(checkBoxDownloaded);
    QObject::connect(play_button, &QPushButton::clicked,
                     this, &MainPage::PlaySong);

    mButtonToLayoutMap.insert(play_button, song_layout);

    return song_layout;
}

void MainPage::AddTrackToDownloadedTab(const QString& file_name) {
    QHBoxLayout* song_layout = MainPage::CreateSongLayout(
                ui->scrollAreaWidgetContentsDownload, file_name, true);

    if (ui->downVLayout->count() == 0) {
        //ui->downVLayout->insertSpacerItem(0, new QSpacerItem(1, 100, QSizePolicy::Maximum));
        ui->downVLayout->addStretch(2);
    }
    ui->downVLayout->insertLayout(0, song_layout);
}

void MainPage::on_tabWidget_tabBarClicked(int index) {
    const int kRefreshLikes = 0, kRefreshDownload = 1;

    // Delete old layouts.
    DeleteLayout(ui->downVLayout);
    DeleteLayout(ui->likesVLayout);

    tracks_list.clear();
    downloadedFiles.clear();

    if (kRefreshDownload == index) {
        // Get all files with file extension = {.mp3, .wav}
        // from current folder to QHas mButtonToLayoutMap
        QDir working_directory(working_dir_path);
        working_directory.setFilter(QDir::Files | QDir::NoSymLinks);
        working_directory.setNameFilters(QStringList{"*.mp3", "*.wav"});

        tracks_list = std::move(working_directory.entryList());

        received_playlist->clear();
        //player->setPlaylist(received_playlist);
        // Go from behind -> i want to add
        for (int track_index = 0; track_index < (int)tracks_list.size(); ++track_index) {
            QString file_name = tracks_list[track_index];
            downloadedFiles[file_name] = {working_dir_path + file_name, track_index};
            AddTrackToDownloadedTab(file_name);
            received_playlist->addMedia(QUrl::fromLocalFile(working_dir_path + file_name));
        }

    } else {

    }

    ui->lastUpdateTimeLabel->setText(GetCurrentTime()); // set last update time
}

void MainPage::ChangeState(SetPlayerState player_state) {
    QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);";
    QString button_cover_image = "pause_song.png";

    if ((player->state() == QMediaPlayer::PausedState
        && player_state == SetPlayerState::Default) ||
        player_state == SetPlayerState::ForcePlay) {
            player->play();
    } else {
        player->pause();
        button_cover_image = "query_song.png";
    }
    ui->pauseButton->setStyleSheet(style_sheet_parametr.arg(std::move(button_cover_image)));
}

void MainPage::PlaySong() {
    QPushButton* play_button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* song_layout = mButtonToLayoutMap.value(play_button);

    const int kFileNamePos = 2;
    // Get QLabel of layout -> then get text from label
    QString file_name = qobject_cast<QLabel*>(
                song_layout->itemAt(kFileNamePos)->widget()
    )->text();

    if (!received_playlist->isEmpty()) {
        delete active_playlist; // delete pointer to old_playlist
        active_playlist = received_playlist;    // copy pointer (that pointer will be deleted on next playlist change)
        received_playlist = new QMediaPlaylist(); // disconnect received_playlist ptr from memory,
                                              // that now belongs to active_playlist
    }
    player->setVolume(30);
    player->setPlaylist(active_playlist);
    player->playlist()->setCurrentIndex(downloadedFiles[file_name].second);
    MainPage::ChangeState(SetPlayerState::ForcePlay);
}

void MainPage::on_pauseButton_clicked()
{
    const int kNeededPosOfLayout = 1;
    auto current_tab = qobject_cast<QWidget*>(ui->tabWidget->currentWidget());
    auto current_tab_layouts = current_tab->findChildren<QVBoxLayout*>();
    auto current_tab_layout = current_tab_layouts.at(kNeededPosOfLayout);

    if (current_tab_layout== nullptr) {
        QMessageBox::critical(this, "FFF", "SegFault");
        return;
    }

    QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);";
    if (player->state() == QMediaPlayer::StoppedState) {
        const int kMinCount = 1;    // 1 -> because downVLayout by default have spacer
        const int kMinItemPos =                                                     0;  // 0 -> because i want to play track from top of the list
        if (current_tab_layout->count() > kMinCount) {
            qobject_cast<QPushButton*>(current_tab_layout->itemAt(kMinItemPos)->
                                       layout()->itemAt(kMinItemPos)->widget()
            )->click(); // activate button
            ui->pauseButton->setStyleSheet(style_sheet_parametr.arg("pause_song.png"));
        }
    } else {
        MainPage::ChangeState();
    }
}

void MainPage::on_nextButton_clicked()
{
    // In my layout view i have reversed view of track list
    // Therefore i need to swap buttons =>  next = prev; prev = next
    const int kCurrentPosInPlaylist = player->playlist()->currentIndex();
    const int kBeginPos = (int)player->playlist()->mediaCount() - 1, kEndPos = 0;
    int kNextPos = player->playlist()->previousIndex(); // swapped
    if (kCurrentPosInPlaylist == kEndPos) {
        kNextPos = kBeginPos;
    }
    player->playlist()->setCurrentIndex(kNextPos);
}


void MainPage::on_prevButton_clicked()
{
    // In my layout view i have reversed view of track list
    // Therefore i need to swap buttons =>  next = prev; prev = next
    const int kCurrentPosInPlaylist = player->playlist()->currentIndex();
    const int kBeginPos = 0, kEndPos = (int)player->playlist()->mediaCount() - 1;
    int kNextPos = player->playlist()->nextIndex(); // swapped
    if (kCurrentPosInPlaylist == kEndPos) {
        kNextPos = kBeginPos;
    }
    player->playlist()->setCurrentIndex(kNextPos);
}


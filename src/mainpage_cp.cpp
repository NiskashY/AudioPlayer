#include "mainpage.h"
#include "ui_mainpage.h"

#define cnct connect
#define disct disconnect
#define CUSTOM_CONNECTION(connection_handler) (connection_handler == "connect" ? cnct : disct)

#include <QSpacerItem>

QString GetFileNameFromPath(const QString& path) {
    QString resultFileName;

    for (int i = (int)path.size() - 1; i >= 0 && path[i] != '/'; --i) {
        resultFileName += path[i];
    }

    std::reverse(resultFileName.begin(), resultFileName.end());
    return resultFileName;
}

void MainPage::ConnectionManipulation(bool isConnect)
{
    if (isConnect) {
        // Connect Sound Signals for player and UI
        connect (
                player, &QMediaPlayer::positionChanged,
                this, &MainPage::SetCurrentSliderPosition
        ); // song 'progress bar' update

        connect (
                player, &QMediaPlayer::durationChanged,
                this, &MainPage::SetMaxSliderPosition
        ); // song time update
        connect (
                player, &QMediaPlayer::currentMediaChanged,
                this, &MainPage::SetSongNameLabel
        ); // song name update
        connect (
                ui->songSlider, &QSlider::sliderMoved,
                this, &MainPage::SliderPositionMoved
        ); // slider moved -> change position in the soundtrack
    } else {
        // Disconnect  Sound Signals for player and UI
        disconnect (
                player, &QMediaPlayer::positionChanged,
                this, &MainPage::SetCurrentSliderPosition
        ); // song 'progress bar' update

        disconnect (
                player, &QMediaPlayer::durationChanged,
                this, &MainPage::SetMaxSliderPosition
        ); // song time update
        disconnect (
                player, &QMediaPlayer::currentMediaChanged,
                this, &MainPage::SetSongNameLabel
        ); // song name update
        disconnect (
                ui->songSlider, &QSlider::sliderMoved,
                this, &MainPage::SliderPositionMoved
        ); // slider moved -> change position in the soundtrack
    }
}

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Page");

    // Set Images To Buttons on Main Page
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

    Q_EMIT ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());  // Refresh likes page

    // Initialize player
    player = new QMediaPlayer();
    active_playlist = new QMediaPlaylist();
    received_playlist = new QMediaPlaylist();
    player->setPlaylist(active_playlist);
    player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);

    // Setup Volume of sound and ui elements for this
    const int& kSoundVolume = 30;
    ui->verticalSlider->setSliderPosition(kSoundVolume);
    player->setVolume(kSoundVolume);

    // Connect Sound Signals for player and UI
    MainPage::ConnectionManipulation(true); // connect slots
}

MainPage::~MainPage()
{
    MainPage::ConnectionManipulation(false);    // disconnect slots
    delete ui;
    player->stop();
    player->playlist()->clear();
    delete received_playlist;
    delete active_playlist;
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

void MainPage::on_tabWidget_tabBarClicked(int index) {
    const int kRefreshLikes = 0, kRefreshDownload = 1;

    // Delete old layouts.
    DeleteLayout(ui->downVLayout);
    DeleteLayout(ui->likesVLayout);

    tracks_list.clear();
    downloadedFiles.clear();
    mButtonToLayoutMap.clear();

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
    int kNextPos = player->playlist()->previousIndex(); // swapped

    // Check if i need to shuffle tracks
    if (player->playlist()->playbackMode() == QMediaPlaylist::Random) {
        srand(time(0));
        const int totalMediaCount = (player->playlist()->mediaCount());
        do {
            kNextPos = rand() % totalMediaCount;
        } while (kNextPos == kCurrentPosInPlaylist && totalMediaCount > 1);
    }
    player->playlist()->setCurrentIndex(kNextPos);
}

void MainPage::on_prevButton_clicked()
{
    // In my layout view i have reversed view of track list
    // Therefore i need to swap buttons =>  next = prev; prev = next
    const int kCurrentPosInPlaylist = player->playlist()->currentIndex();
    int kNextPos = player->playlist()->nextIndex(); // swapped

    if (player->playlist()->playbackMode() == QMediaPlaylist::Random) {
        srand(time(0));
        const int totalMediaCount = (player->playlist()->mediaCount());
        do {
            kNextPos = rand() % totalMediaCount;
        } while (kNextPos == kCurrentPosInPlaylist && totalMediaCount > 1);
    }
    player->playlist()->setCurrentIndex(kNextPos);
}

void MainPage::on_shuffleButton_clicked()
{
    if (player->playlist()->playbackMode() != QMediaPlaylist::PlaybackMode::Random) {
        if (player->playlist()->playbackMode() == QMediaPlaylist::PlaybackMode::CurrentItemInLoop) {
            ui->repeatButton->click();
        }
        ui->shuffleButton->setStyleSheet(style_sheet_parametr.arg("shuffle_on_song.png"));
        player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::Random);
    } else {
        ui->shuffleButton->setStyleSheet(style_sheet_parametr.arg("shuffle_song.png"));
        player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
    }
}

void MainPage::on_repeatButton_clicked()
{
    if (player->playlist()->playbackMode() != QMediaPlaylist::PlaybackMode::CurrentItemInLoop) {
        if (player->playlist()->playbackMode() == QMediaPlaylist::PlaybackMode::Random) {
            ui->shuffleButton->click();
        }
        player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::CurrentItemInLoop);
        ui->repeatButton->setStyleSheet(style_sheet_parametr.arg("repeat_on_song.png"));
    } else {
        player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
        ui->repeatButton->setStyleSheet(style_sheet_parametr.arg("repeat_song.png"));
    }
}

QHBoxLayout* MainPage::CreateSongLayout(QWidget*& parent_widget,
                                        const QString& file_name,
                                        bool isDownloaded = false)
{
    QHBoxLayout* song_layout = new QHBoxLayout(parent_widget);
    QPushButton* play_button = new QPushButton("", parent_widget);
    play_button->setStyleSheet(style_sheet_parametr.arg("query_song.png"));
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
        ui->downVLayout->addStretch(2);
    }
    ui->downVLayout->insertLayout(0, song_layout);
}

void MainPage::ChangeState(SetPlayerState player_state) {
    QString button_cover_image = "pause_song.png";

    if ((player->state() == QMediaPlayer::PausedState &&
        player_state == SetPlayerState::Default) ||
        player_state == SetPlayerState::ForcePlay)
    {
        player->play();
        MainPage::SetSongNameLabel();
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

    player->stop();

    if (!received_playlist->isEmpty()) {
        QMediaPlaylist::PlaybackMode prev_playback_mode_state
                = player->playlist()->playbackMode();
        disconnect(
                player, &QMediaPlayer::currentMediaChanged,
                this, &MainPage::SetSongNameLabel
        );                                        // disconnect slot to prevent asking from deleted area

        delete active_playlist;                   // delete pointer to old_playlist
        active_playlist = received_playlist;      // copy pointer (that pointer will be deleted on next playlist change)
        received_playlist = new QMediaPlaylist(); // disconnect received_playlist ptr from memory,
                                                  // that now belongs to active_playlist
        std::swap(final_tracks_list, tracks_list);// swap to avoid copying

        connect(
                player, &QMediaPlayer::currentMediaChanged,
                this, &MainPage::SetSongNameLabel
        );                                        // connect again to change song name label

        player->setPlaylist(active_playlist);
        player->playlist()->setPlaybackMode(prev_playback_mode_state);
    }

    player->playlist()->setCurrentIndex(downloadedFiles[file_name].second);
    MainPage::ChangeState(SetPlayerState::ForcePlay);
}

void MainPage::SetCurrentSliderPosition() {
    const int current_player_position= player->position();
    ui->songSlider->setValue(current_player_position);
    ui->currentTimeLabel->setText(TimeConvertFromMiliseconds(current_player_position));
}

void MainPage::SetMaxSliderPosition() {
    const int current_duration = player->duration();
    ui->songSlider->setMaximum(current_duration );
    ui->totalTimeLabel->setText(TimeConvertFromMiliseconds(current_duration));
}

void MainPage::SetSongNameLabel() {
    auto cur_index = player->playlist()->currentIndex();
    ui->songNameLabel->setText(
        final_tracks_list.at(cur_index)
    );
}

void MainPage::SliderPositionMoved() {
    player->setPosition(ui->songSlider->sliderPosition());
}

void MainPage::on_changeDirButton_clicked()
{
    QFileDialog dirWindow(this);
    dirWindow.setWindowTitle("Select Folder To Save Files");
    dirWindow.setFileMode(QFileDialog::Directory);

    if (dirWindow.exec()) {
        QStringList selectedDirectories = dirWindow.selectedFiles();
        working_dir_path = selectedDirectories[0] + "/";
        Q_EMIT ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());
    }
}

void MainPage::on_verticalSlider_sliderMoved(int position) {
    player->setVolume(ui->verticalSlider->sliderPosition());
}


#include "mainpage.h"
#include "ui_mainpage.h"

void MainPage::ConnectionHandler(bool isConnect) {
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
            connect (
                    ui->songSlider, &QSlider::sliderPressed,
                    this, &MainPage::PauseFromSLider
            ); // slider pause -> avoid sound interferences
            connect (
                    ui->songSlider, &QSlider::sliderReleased,
                    this, &MainPage::PlayFromSLider
            ); // slider released -> continue playing
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
            disconnect (
                    ui->songSlider, &QSlider::sliderPressed,
                    this, &MainPage::PauseFromSLider
            ); // slider pause -> avoid sound interferences
            disconnect (
                    ui->songSlider, &QSlider::sliderReleased,
                    this, &MainPage::PlayFromSLider
            ); // slider released -> continue playing
        }
}

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                )
    );

    this->setWindowTitle("Main Page");

    // Set Images To Buttons on Main Page
    ui->exitAccountButton->setStyleSheet(style_sheet_parametr.arg("exit_account.png"));
    ui->shuffleButton->setStyleSheet(style_sheet_parametr.arg("shuffle_song.png"));
    ui->prevButton->setStyleSheet(style_sheet_parametr.arg("prev_song.png"));
    ui->pauseButton->setStyleSheet(style_sheet_parametr.arg("query_song.png"));
    ui->nextButton->setStyleSheet(style_sheet_parametr.arg("next_song.png"));
    ui->repeatButton->setStyleSheet(style_sheet_parametr.arg("repeat_song.png"));

    // Setting Up labels for tabs
    const int kLikedTracksPos = 0, kDownloadedTracksPos = 1;
    ui->tabWidget->setTabText(kLikedTracksPos, "Liked Tracks");
    ui->tabWidget->setTabText(kDownloadedTracksPos, "Downloaded Tracks");

    // Initialize layout with spacer
    const int kNeededPosOfLayout = 1;
    auto current_tab = qobject_cast<QWidget*>(ui->tabWidget->currentWidget());
    const auto& current_tab_layouts  = current_tab->findChildren<QVBoxLayout*>();
    auto current_tab_layout = current_tab_layouts.at(kNeededPosOfLayout);
    current_tab_layout->addStretch(2);

    // Initialize player
    player = new QMediaPlayer();
    active_playlist = new QMediaPlaylist();
    received_playlist = new QMediaPlaylist();
    player->setPlaylist(active_playlist);
    player->playlist()->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);

    // Initialise current working_dir with application folder
    working_dir_path = QApplication::applicationDirPath() + "/saved-tracks/";
    // Refresh Page
    Q_EMIT ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());

    // Setup Volume of sound and ui elements for this
    const int& kSoundVolume = 10;
    ui->verticalSlider->setSliderPosition(kSoundVolume);
    player->setVolume(kSoundVolume);

    // Connect Sound Signals for player and UI
    MainPage::ConnectionHandler(true); // connect slots

    // Set Account Label
    ui->accountLabel->setText("Account is not selected");
    ui->standardDirLabel->setText(".../saved-tracks/");
    ui->standardDirLabel->setStyleSheet("QLabel { color : orange; }");
}

MainPage::~MainPage()
{
    MainPage::ConnectionHandler(false); // disconnect slots
    delete ui;
    player->stop();
    player->playlist()->clear();
    delete received_playlist;
    delete active_playlist;
    delete player;
}

QHBoxLayout* MainPage::CreateSongLayout(QWidget*& parent_widget,
                                        const QString& file_name,
                                        bool isDownload = false)
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
    checkBoxDownloaded->setEnabled(Qt::CheckState(!isDownload));

    song_layout->addWidget(checkBoxDownloaded);
    QObject::connect(play_button, &QPushButton::clicked,
                     this, (isDownload ? &MainPage::PlaySong :
                                           &MainPage::PlayLikedSong)
    );

    if (!isDownload) {
        QObject::connect(checkBoxDownloaded, &QCheckBox::clicked,
                         this, &MainPage::CheckBoxClicked
        );
        mButtonToLayoutMap.insert(checkBoxDownloaded, song_layout);
        QFile source_file(working_dir_path + file_name);
        if (source_file.exists()) {
            checkBoxDownloaded->click();
        }
    }

    mButtonToLayoutMap.insert(play_button, song_layout);

    return song_layout;
}

QHBoxLayout *MainPage::CreateEmptyPage(QWidget *&parent_widget) {
    QHBoxLayout* empty_notifer_layout = new QHBoxLayout(parent_widget);
    empty_notifer_layout->addStretch(2);     // Add Stretchable Spacer Item

    QLabel* empty_notifer_label = new QLabel("Current track list is empty", parent_widget);
    empty_notifer_label->setStyleSheet("QLabel { color : orange; }");
    empty_notifer_layout->addWidget(empty_notifer_label);
    empty_notifer_layout ->addStretch(2);     // Add Stretchable Spacer Item

    return empty_notifer_layout;
}

void MainPage::AddLayoutToTab(QVBoxLayout* const v_layout,
                             const QString& file_name,
                             bool isCheckBoxEnabled) {
    QHBoxLayout* song_layout = MainPage::CreateSongLayout(
                ui->scrollAreaWidgetContentsDownload, file_name, isCheckBoxEnabled);

    if (v_layout->count() == 0) {
        v_layout->addStretch(2);
    }
    v_layout->insertLayout(0, song_layout);
}

void MainPage::AddLayoutToTab(QVBoxLayout* const v_layout) {
    QHBoxLayout* song_layout = MainPage::CreateEmptyPage(
                ui->scrollAreaWidgetContentsDownload);

    if (v_layout->count() == 0) {
        v_layout->addStretch(2);
    }
    v_layout->insertLayout(0, song_layout);
    v_layout->insertStretch(0, 2);
}

void MainPage::ChangeState(SetPlayerState player_state) {
    QString button_cover_image = "pause_song.png";

    if ((player->state() == QMediaPlayer::PausedState &&
        player_state == SetPlayerState::Default) ||
        player_state == SetPlayerState::ForcePlay)
    {
        if (!player->currentMedia().isNull()) {
            player->play();
            MainPage::SetSongNameLabel();
        } else {
            button_cover_image = "query_song.png";
        }
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
        player->setPlaylist(active_playlist);

        connect(
                player, &QMediaPlayer::currentMediaChanged,
                this, &MainPage::SetSongNameLabel
        );                                        // connect again to change song name label
        player->playlist()->setPlaybackMode(prev_playback_mode_state);
    }

    player->playlist()->setCurrentIndex(downloadedFiles[file_name].second);
    MainPage::ChangeState(SetPlayerState::ForcePlay);
}

void MainPage::PlayLikedSong()
{
    QPushButton* play_button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* song_layout = mButtonToLayoutMap.value(play_button);

    const int kFileNamePos = 2;
    // Get QLabel of layout -> then get text from label
    QString file_name = qobject_cast<QLabel*>(
                song_layout->itemAt(kFileNamePos)->widget()
    )->text();

    QString file_path;
    try {
        CommunicateWithServer server;
        file_path = server.GetFilePathFromServer(file_name);
    }  catch(std::runtime_error e) {
        QMessageBox::critical(this, "Server Problem", e.what());
        return;
    }

    player->stop();
    tracks_list.clear();
    received_playlist->clear();

    const int kCheckBoxPos = 4;
    qobject_cast<QCheckBox*>(
            song_layout->itemAt(kCheckBoxPos)->widget()
    )->click();

    tracks_list.append(file_name);
    bool isAdded = received_playlist->addMedia(QUrl::fromLocalFile(file_path));
    if (!isAdded) {
        QMessageBox::critical(this, "f", "f");
        return;
    }

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
        player->setPlaylist(active_playlist);

        connect(
                player, &QMediaPlayer::currentMediaChanged,
                this, &MainPage::SetSongNameLabel
        );                                        // connect again to change song name label

        player->playlist()->setPlaybackMode(prev_playback_mode_state);
    }

    player->playlist()->setCurrentIndex(0);
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

void MainPage::ChangeTitleColor(QString color) {
    int total_items = player->playlist()->mediaCount();
    int index = total_items - prev_index - 1;
    if (ui->tabWidget->currentIndex() == 1) {
        QVBoxLayout* cur_layout = ui->downVLayout;
        if (index >= 0 && index < cur_layout->count()) {
            QHBoxLayout* cur_song_layout = qobject_cast<QHBoxLayout*>(
                 cur_layout->itemAt(index)->layout()
            );
            const int kSongNamePos = 2;
            qobject_cast<QLabel*>(
                cur_song_layout->itemAt(kSongNamePos)->widget()
            )->setStyleSheet(QString("QLabel { color : %1}").arg(color));
        }
    }
}

void MainPage::SetSongNameLabel() {
    if (prev_index != -1) {
        MainPage::ChangeTitleColor("white");
    }
    auto cur_index = player->playlist()->currentIndex();
    prev_index = cur_index;
    MainPage::ChangeTitleColor("orange");

    ui->songNameLabel->setText(
        final_tracks_list.at(cur_index)
    );
}

void MainPage::SliderPositionMoved() {
    player->setPosition(ui->songSlider->sliderPosition());
}

void MainPage::PauseFromSLider() {
    MainPage::ChangeState(SetPlayerState::ForcePause);
}

void MainPage::PlayFromSLider() {
    MainPage::ChangeState(SetPlayerState::ForcePlay);
}

void MainPage::CheckBoxClicked() {
    QCheckBox* clicked_check_box = qobject_cast<QCheckBox*>(sender());
    QHBoxLayout* song_layout = mButtonToLayoutMap.value(clicked_check_box);

    const int kFileNamePos = 2;
    QString file_name = qobject_cast<QLabel*>(
                song_layout->itemAt(kFileNamePos)->widget()
    )->text();
    try {
        CommunicateWithServer server;
        server.GetFilePathFromServer(file_name, working_dir_path);
    }  catch(std::runtime_error e) {
        QMessageBox::critical(this, "Server Problem", e.what());
        return;
    }

    clicked_check_box->setChecked(true);
    clicked_check_box->setEnabled(false); // cancel redownload
}

#include "mainpage.h"
#include "ui_mainpage.h"

void MainPage::on_exitAccountButton_clicked() {
    if (account != nullptr) {
        EnsureMessageBox* ensure = new EnsureMessageBox;
        ensure->setModal(true);
        ensure->exec();

        if (ensure->getIsNeedToExist()) {
            DeleteLayout(ui->likesVLayout);
            ui->accountLabel->setText("Account is not selected");
            ui->accountLabel->setStyleSheet("QLabel { color : red; }");
            delete account;
            account = nullptr;
        }
        delete ensure;
    }
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

        const int kLikesPage = 0;
        if (ui->tabWidget->currentIndex() == kLikesPage) {
            try {
                CommunicateWithServer server;
                server.UploadFiles(selectedFiles, account->getUsername());
            }  catch(std::runtime_error e) {
                QMessageBox::critical(this, "Server Problem", e.what());
                return;
            }
        }

        Q_EMIT ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());
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
    received_playlist->clear();

    if (kRefreshDownload == index) {
        // Get all files with file extension = {.mp3, .wav}
        // from current folder to QHas mButtonToLayoutMap
        QDir working_directory(working_dir_path);
        working_directory.setFilter(QDir::Files | QDir::NoSymLinks);
        working_directory.setNameFilters(QStringList{"*.mp3", "*.wav"});

        tracks_list = std::move(working_directory.entryList());


        //player->setPlaylist(received_playlist);
        // Go from behind -> i want to add
        for (int track_index = 0; track_index < (int)tracks_list.size(); ++track_index) {
            QString file_name = tracks_list[track_index];
            downloadedFiles[file_name] = {working_dir_path + file_name, track_index};
            AddTrackToTab(ui->downVLayout, file_name, true);
            received_playlist->addMedia(QUrl::fromLocalFile(working_dir_path + file_name));
        }
    } else {
        bool isLogged = StartLoginProccess(this, account);
        if (isLogged) {
            ui->accountLabel->setText("Account: " + account->getUsername());
            ui->accountLabel->setStyleSheet("QLabel { color : green; }");
            QStringList getted_tracks;
            try {
                CommunicateWithServer server;
                getted_tracks = server.GetUserLikedTracks(account->getUsername());
            } catch(std::runtime_error e) {
                QMessageBox::critical(this, "Server Problem", e.what());
            }

            for (const auto& file_name : getted_tracks) {
                AddTrackToTab(ui->likesVLayout, file_name, false);
                tracks_list.append(file_name);
            }
        } else {
            account = nullptr;
        }
    }

    ui->lastUpdateTimeLabel->setText(GetCurrentTime()); // set last update time
}

void MainPage::on_pauseButton_clicked()
{
    const int kNeededPosOfLayout = 1;
    auto current_tab = qobject_cast<QWidget*>(ui->tabWidget->currentWidget());
    auto current_tab_layouts = current_tab->findChildren<QVBoxLayout*>();
    auto current_tab_layout = current_tab_layouts.at(kNeededPosOfLayout);

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

void MainPage::on_changeDirButton_clicked() {
    QFileDialog dirWindow(this);
    dirWindow.setWindowTitle("Select Folder To Save Files");
    dirWindow.setFileMode(QFileDialog::Directory);

    if (dirWindow.exec()) {
        QStringList selectedDirectories = dirWindow.selectedFiles();
        working_dir_path = selectedDirectories[0] + "/";
        QString dir_name = GetFileNameFromPath(selectedDirectories[0]);
        ui->standardDirLabel->setText(".../" + dir_name + "/");
        ui->standardDirLabel->setStyleSheet("QLabel { color : orange; }");
        Q_EMIT ui->tabWidget->tabBarClicked(ui->tabWidget->currentIndex());
    }
}

void MainPage::on_verticalSlider_sliderMoved(int position) {
    player->setVolume(ui->verticalSlider->sliderPosition());
}

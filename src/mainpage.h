#pragma once

// Qt headers
#include <QDialog>
#include <QFileDialog>
#include <QMap>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QSlider>

// Custom headers
#include "layoutsdeleter.h"
#include "communicatewithserver.h"

namespace Ui {
class MainPage;
}

enum class SetPlayerState {
    Default, ForcePlay, ForcePause
};


class MainPage : public QDialog
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    // Buttons clicked
    void on_backLogo_clicked();
    void on_addFromDeviceButton_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_pauseButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_shuffleButton_clicked();
    void on_repeatButton_clicked();

    // Sound Manipulation
    void PlaySong();
    void SetMaxSliderDuration();

private:
    void AddTrackToDownloadedTab(const QString& file_name);
    QHBoxLayout* CreateSongLayout(QWidget*& parent_widget,
                                  const QString& file_name,
                                  bool isDownloaded);
    void ChangeState(SetPlayerState player_state = SetPlayerState::Default);

    Ui::MainPage *ui;
    QMediaPlayer* player = nullptr;
    QMediaPlaylist* active_playlist = nullptr;
    QMediaPlaylist* received_playlist = nullptr;

    // TODO: пусть пользователь сам меняет свою рабочую директорию
    const QString working_dir_path = "/home/mint/GitRepos/AudioPlayer/build-src-Desktop-Debug/saved-tracks/";
    const QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);"; // for setting up buttons images

    QMap<QString, std::pair<QString, int>> downloadedFiles; // first -> file_name, second -> file_path
    QHash<QPushButton*, QHBoxLayout*> mButtonToLayoutMap;
    QStringList tracks_list;
};


QString GetFileNameFromPath(const QString&);

#pragma once

// Qt headers
#include <QMainWindow>
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


class MainPage : public QMainWindow
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
    void PlaySong();                 // start song & change elements of ui for that
    void SetCurrentSliderPosition(); // get player_position and set ui_slider position
    void SetMaxSliderPosition();     // get max player position set ui_slider max position
    void SetSongNameLabel();         // set ui current song name
    void SliderPositionMoved();      // move soundtrack player to new position

    void on_changeDirButton_clicked();

    void on_verticalSlider_sliderMoved(int position);

private:
    void AddTrackToDownloadedTab(const QString& file_name);
    QHBoxLayout* CreateSongLayout(QWidget*& parent_widget,
                                  const QString& file_name,
                                  bool isDownloaded);
    void ChangeState(SetPlayerState player_state = SetPlayerState::Default);
    void ConnectionManipulation(bool isConnect);

    Ui::MainPage *ui;
    QMediaPlayer* player = nullptr;
    QMediaPlaylist* active_playlist = nullptr;
    QMediaPlaylist* received_playlist = nullptr;

    // TODO: пусть пользователь сам меняет свою рабочую директорию
    QString working_dir_path = "/home/mint/GitRepos/AudioPlayer/build-src-Desktop-Debug/saved-tracks/";
    const QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);"; // for setting up buttons images

    QMap<QString, std::pair<QString, int>> downloadedFiles; // first -> file_name, second -> file_path
    QHash<QPushButton*, QHBoxLayout*> mButtonToLayoutMap;
    QStringList tracks_list, final_tracks_list;
};


QString GetFileNameFromPath(const QString&);

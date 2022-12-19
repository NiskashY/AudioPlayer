#pragma once

// Qt headers
#include <QStyle>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMap>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpacerItem>

// Custom headers
#include "checker/ensuremessagebox.h"
#include "layoutsdeleter.h"
#include "communicatewithserver.h"
#include "account.h"
#include "loginwindow.h"

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
    void on_exitAccountButton_clicked();
    void on_addFromDeviceButton_clicked();
    void on_tabWidget_tabBarClicked(int);
    void on_pauseButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_shuffleButton_clicked();
    void on_repeatButton_clicked();
    void on_changeDirButton_clicked();
    void on_verticalSlider_sliderMoved(int);

    // Sound Manipulation
    void PlaySong();                 // start song & change elements of ui for that
    void PlayLikedSong();
    void SetCurrentSliderPosition(); // get player_position and set ui_slider position
    void SetMaxSliderPosition();     // get max player position set ui_slider max position
    void SetSongNameLabel();         // set ui current song name
    void SliderPositionMoved();      // move soundtrack player to new position
    void pauseFromSLider();
    void playFromSLider();

private:
    void AddTrackToTab(QVBoxLayout*const, const QString&, bool);
    QHBoxLayout* CreateSongLayout(QWidget*& parent_widget,
                                  const QString& file_name,
                                  bool isDownloaded);
    void ChangeState(SetPlayerState player_state = SetPlayerState::Default);
    void ConnectionHandler(bool);

    Account* account = nullptr;         // account for network operations
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


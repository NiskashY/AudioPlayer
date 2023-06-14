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
#include "ensuremessagebox.h"
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
    // Buttons clicked - definition in mainpage_buttons.cpp
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
    void PauseFromSLider();
    void PlayFromSLider();
    void CheckBoxClicked();
private:
    void ChangeTitleColor(QString color);
    void AddLayoutToTab(QVBoxLayout*const, const QString&, bool); // for filled pages
    void AddLayoutToTab(QVBoxLayout*const); // for empty pages
    QHBoxLayout* CreateSongLayout(QWidget*& parent_widget,
                                  const QString& file_name,
                                  bool isDownloaded);
    QHBoxLayout* CreateEmptyPage(QWidget*& parent_widget);

    void ChangeState(SetPlayerState player_state = SetPlayerState::Default);
    void ConnectionHandler(bool);

    Account* account = nullptr;         // account for network operations
    Ui::MainPage *ui;
    QMediaPlayer* player = nullptr;
    QMediaPlaylist* active_playlist = nullptr;
    QMediaPlaylist* received_playlist = nullptr;

    QString working_dir_path;
    const QString style_sheet_parametr = "border-image:url(:/resourses/songsCovers/%1);"; // for setting up buttons images

    QMap<QString, std::pair<QString, int>> downloadedFiles; // first -> file_name, second -> file_path
    QHash<QAbstractButton*, QHBoxLayout*> mButtonToLayoutMap;
    QStringList tracks_list, final_tracks_list;

    int prev_index = -1;
};


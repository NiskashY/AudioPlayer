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
    void on_backLogo_clicked();
    void on_addFromDeviceButton_clicked();
    void PlaySong();
    void on_tabWidget_tabBarClicked(int index);
    void on_pauseButton_clicked();
    void on_nextButton_clicked();

    void on_prevButton_clicked();

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
    QString working_dir_path = "/home/mint/GitRepos/AudioPlayer/build-src-Desktop-Debug/saved-tracks/";

    QMap<QString, std::pair<QString, int>> downloadedFiles; // first -> file_name, second -> file_path
    QHash<QPushButton*, QHBoxLayout*> mButtonToLayoutMap;
    QStringList tracks_list;
};


QString GetFileNameFromPath(const QString&);

#pragma once

// Qt headers
#include <QDialog>
#include <QFileDialog>
#include <QMap>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QMediaPlayer>

namespace Ui {
class MainPage;
}

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

private:
    void AddTrackToDownloadedTab(const QString& file_name);
    QHBoxLayout* CreateSongLayout(QWidget*& parent_widget,
                                  const QString& file_name,
                                  bool isDownloaded);

    Ui::MainPage *ui;

    QMap<QString, QString> downloadedFiles; // first -> file_path, second -> file_name
    QHash<QPushButton*, QHBoxLayout*> mButtonToLayoutMap;
};


QString GetFileNameFromPath(const QString&);

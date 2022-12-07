#include "mainpage.h"
#include "ui_mainpage.h"

#include <QSpacerItem>

MainPage::MainPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Page");
    ui->backLogo->setStyleSheet("border-image:url(:/resourses/songsCovers/sound.jpg);");

    const int kLikedTracksPos = 0, kDownloadedTracksPos = 1;
    ui->tabWidget->setTabText(kLikedTracksPos, "Liked Tracks");
    ui->tabWidget->setTabText(kDownloadedTracksPos, "Downloaded sTracks");
}

MainPage::~MainPage()
{
    delete ui;
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
        QString dir_path = QApplication::applicationDirPath() + "/saved-tracks/";
        for (const auto& file_path : selectedFiles) {
            QString file_name = GetFileNameFromPath(file_path);
            QFile::copy(file_path, dir_path + file_name);

            bool isExisted = downloadedFiles.contains(file_name);
            downloadedFiles[file_name] = file_path;
            if (!isExisted) {
                AddTrackToDownloadedTab(file_name);
            }
        }
    }
}

QHBoxLayout* MainPage::CreateSongLayout(QWidget*& parent_widget,
                                        const QString& file_name,
                                        bool isDownloaded = false)
{
    QHBoxLayout* song_layout = new QHBoxLayout();
    QPushButton* play_button = new QPushButton("", parent_widget);
    song_layout->addWidget(play_button);

    song_layout->addSpacerItem(new QSpacerItem(
                                   100, /*max w size*/
                                   1, /*max h size */
                                   QSizePolicy::Expanding,
                                   QSizePolicy::Fixed));


    QLabel* song_label = new QLabel(file_name, parent_widget);
    song_layout->addWidget(song_label);

    song_layout->addSpacerItem(new QSpacerItem(
                                   100, /*max w size*/
                                   1, /*max h size */
                                   QSizePolicy::Expanding,
                                   QSizePolicy::Fixed));


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
                ui->scrollAreaWidgetContents, file_name, true);

    ui->downVLayout->insertLayout(0, song_layout);
}


void MainPage::PlaySong() {
    QPushButton* play_button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* song_layout = mButtonToLayoutMap.value(play_button);

    // Get QLabel of layout -> then get text from label
    QString file_name = qobject_cast<QLabel*>(song_layout->itemAt(1)->widget())->text();

    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(downloadedFiles[file_name]));
    player->setVolume(30);
    player->play();
}

QString GetFileNameFromPath(const QString& path) {
    QString resultFileName;

    for (int i = (int)path.size() - 1; i >= 0 && path[i] != '/'; --i) {
        resultFileName += path[i];
    }

    std::reverse(resultFileName.begin(), resultFileName.end());
    return resultFileName;
}



#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Page");
    ui->backLogo->setStyleSheet("border-image:url(:/resourses/songsCovers/sound.jpg);");
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_backLogo_clicked()
{
    this->close();
}


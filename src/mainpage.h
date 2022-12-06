#pragma once

#include <QDialog>

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

private:
    Ui::MainPage *ui;
};

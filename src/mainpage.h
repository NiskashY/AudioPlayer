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

private:
    Ui::MainPage *ui;
};

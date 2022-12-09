#pragma once

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class EnsureMessageBox;
}

class EnsureMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit EnsureMessageBox(QWidget *parent = nullptr);
    ~EnsureMessageBox();

    bool getIsNeedToExist() const;
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::EnsureMessageBox *ui;
    bool isNeedToExist = false;
};

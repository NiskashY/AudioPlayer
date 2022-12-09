#include "ensuremessagebox.h"
#include "ui_ensuremessagebox.h"

EnsureMessageBox::EnsureMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnsureMessageBox)
{
    ui->setupUi(this);
    this->setWindowTitle("Ensure Window");
}

EnsureMessageBox::~EnsureMessageBox()
{
    delete ui;
}

void EnsureMessageBox::on_buttonBox_clicked(QAbstractButton *button) {
    isNeedToExist = (ui->buttonBox->standardButton(button) == QDialogButtonBox::Yes);
    this->close();
}

bool EnsureMessageBox::getIsNeedToExist() const {
    return isNeedToExist;
}

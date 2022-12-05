#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:
    void on_BackButton_clicked();
    void on_RegistreButton_clicked();

private: // Private Funcitons
    bool isPasswordContainWrongSymbols(const QString&);

private: // Private variables;
    Ui::SignUpWindow *ui;
    const QString wrongSymbols = "*/\\.-+,@#№$%^&";
    const int kMinPasswordSize = 8;
};

#endif // SIGNUPWINDOW_H

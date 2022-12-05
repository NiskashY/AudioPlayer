#include <QApplication>
#include <QFile>

// Include fiels with information about windows
#include "loginwindow.h"

void SetAppStyleSheet(QApplication&);


int main(int argc, char *argv[])
{    
    QApplication app(argc, argv);
    // Setting up style sheet of buttons, font, background etc...
    SetAppStyleSheet(app);

    LoginWindow lw;
    lw.show();

    return QApplication::exec();
}

void SetAppStyleSheet(QApplication& app) {
    const QString& kFileName = ":/styleSheets/Combinear.qss";
    QFile styleSheetFile(kFileName);
    styleSheetFile.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);
}

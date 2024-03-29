#include <QApplication>
#include <QFile>

// Include fiels with information about windows
#include "mainwindow.h"

void SetAppStyleSheet(QApplication&);

int main(int argc, char *argv[])
{    
    QApplication app(argc, argv);
    // Setting up style sheet of buttons, font, background etc...
    SetAppStyleSheet(app);

    MainWindow main_page;
    main_page.show();

    return QApplication::exec();
}

void SetAppStyleSheet(QApplication& app) {
    app.setWindowIcon(QPixmap(":/resourses/songsCovers/icon_app_logo.svg"));
    const QString& kFileName = ":/styleSheets/Combinear.qss";
    QFile styleSheetFile(kFileName);
    styleSheetFile.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);
}

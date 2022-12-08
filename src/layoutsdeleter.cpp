#include "layoutsdeleter.h"

void DeleteLayout(QBoxLayout* layout) {
    const int kFirstElementPos = 0;
    while(layout->count() > 0) {
        QLayoutItem* item = layout->takeAt(kFirstElementPos);
        if (item->layout() != nullptr) {
            QBoxLayout* childer_layout = qobject_cast<QBoxLayout*>(item->layout());
            DeleteLayout(childer_layout);
        }
        delete item->widget();
        delete item;
    }
}

/*
void DeleteLayout(QBoxLayout* layout) {
    const int kFirstElementPos = 0;
    while(layout->count() > 1) {
        QHBoxLayout* song_layout = qobject_cast<QHBoxLayout*>(
                    layout->takeAt(kFirstElementPos)->layout()
        );
        while (song_layout->count() > 0) {
            QLayoutItem* item = song_layout->takeAt(kFirstElementPos);
            delete item->widget();
            delete item;
        }
        delete song_layout;
    }
}
*/

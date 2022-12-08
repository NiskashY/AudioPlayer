#ifndef SONGPLAYER_H
#define SONGPLAYER_H

#include <QMediaPlayer>
#include "qobjectdefs.h"


class SongPlayer
{
public:
    SongPlayer();

public slots:
    void PlaySong();
/*
    void StopSong();
    void NextSong();
    void PrevSong();
    void ShuffleSongs();
    void RepeatSong();
*/
private:
    QMediaPlayer* player = nullptr;
};

#endif // SONGPLAYER_H

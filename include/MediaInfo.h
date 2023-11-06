//
// Created by 13918 on 2023/9/3.
//

#ifndef MYPLAYER_MEDIAINFO_H
#define MYPLAYER_MEDIAINFO_H

#include <QString>
#include <QTime>

class MediaInfo {
public:
    const QTime &getDuration() const;

    void setDuration(const QTime &duration);

private:
    QString filePath;
    QTime duration;
};


#endif //MYPLAYER_MEDIAINFO_H

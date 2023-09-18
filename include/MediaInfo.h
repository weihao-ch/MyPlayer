//
// Created by 13918 on 2023/9/3.
//

#ifndef MEDIAPLAYER_MEDIAINFO_H
#define MEDIAPLAYER_MEDIAINFO_H

#include <QString>
#include <QTime>

class MediaInfo {
public:
    const QTime &getDuration() const;

    void setDuration(const QTime &duration);

    int getVideoIdx() const;

    void setVideoIdx(int videoIdx);

    int getAudioIdx() const;

    void setAudioIdx(int audioIdx);

    int getSubtitleIdx() const;

    void setSubtitleIdx(int subtitleIdx);

private:
    QString filePath;
    QTime duration;

    int videoIdx;
    int audioIdx;
    int subtitleIdx;

};


#endif //MEDIAPLAYER_MEDIAINFO_H

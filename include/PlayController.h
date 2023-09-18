//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_PLAYCONTROLLER_H
#define MYPLAYER_PLAYCONTROLLER_H

#include "Demuxer.h"
#include "PktQueue.h"

class PlayController : public QObject {
Q_OBJECT
private:
    AVFormatContext *fmtCtx;
    AVCodecContext *videoDecCtx;
    AVCodecContext *audioDecCtx;

    Parser *parser;
    Demuxer *demuxer;
    MediaInfo *mediaInfo;
    PktQueue *videoPktQueue;
    PktQueue *audioPktQueue;
    PktQueue *videoFrameQueue;
    PktQueue *audioFrameQueue;

public:
    explicit PlayController(QObject *parent);

    ~PlayController() override;

public slots:

    void startPlay(const QString &filePath);

};


#endif //MYPLAYER_PLAYCONTROLLER_H

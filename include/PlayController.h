//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_PLAYCONTROLLER_H
#define MYPLAYER_PLAYCONTROLLER_H

#include "Demuxer.h"
#include "Queue.h"
#include "Decoder.h"

class PlayController : public QObject {
Q_OBJECT

public:
    explicit PlayController(QObject *parent);

    ~PlayController() override;

public slots:

    void startPlay(const QString &filePath);

private:
    AVFormatContext *fmtCtx;
    AVCodecContext *videoDecCtx;
    AVCodecContext *audioDecCtx;

    MediaParser *parser;
    Demuxer *demuxer;
    Decoder *decoder;
    MediaInfo *mediaInfo;
    Queue<AVPacket> *pktQueue;
    Queue<AVFrame> *videoFrameQueue;
    Queue<AVFrame> *audioFrameQueue;

};


#endif //MYPLAYER_PLAYCONTROLLER_H

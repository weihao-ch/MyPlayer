//
// Created by 13918 on 2023/9/3.
//

#ifndef MYPLAYER_DEMUXER_H
#define MYPLAYER_DEMUXER_H

#include <QThread>
#include "Queue.h"
#include "MediaParser.h"

class Demuxer : public QThread {
public:
    Demuxer(AVFormatContext *ctx, MediaInfo *info, Queue<AVPacket> *pktQueue);

    void run() override;

    void demux();

private:
    MediaInfo *mediaInfo;
    AVFormatContext *fmtCtx;
    AVPacket *pkt;
    Queue<AVPacket> *pktQueue;
};


#endif //MYPLAYER_DEMUXER_H

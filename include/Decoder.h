//
// Created by 13918 on 2023/9/19.
//

#ifndef MYPLAYER_DECODER_H
#define MYPLAYER_DECODER_H

#include <QThread>
#include "Queue.h"
#include "MediaInfo.h"

extern "C" {
#include "libavcodec/avcodec.h"
}

class Decoder : public QThread {
public:
    explicit Decoder(AVCodecContext *vDecCtx, AVCodecContext *aDecCtx, MediaInfo *info,
                     Queue<AVPacket> *pktQueue, Queue<AVFrame> *vFrameQueue, Queue<AVFrame> *aFrameQueue);

    void run() override;

    void decode();

private:
    AVFrame *frame;
    MediaInfo *mediaInfo;
    AVCodecContext *videoDecCtx;
    AVCodecContext *audioDecCtx;
    Queue<AVPacket> *pktQueue;
    Queue<AVFrame> *videoFrameQueue;
    Queue<AVFrame> *audioFrameQueue;
};


#endif //MYPLAYER_DECODER_H

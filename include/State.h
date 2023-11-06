//
// Created by 13918 on 2023/9/20.
//

#ifndef MYPLAYER_STATE_H
#define MYPLAYER_STATE_H

#include "Queue.h"

extern "C" {
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
}

struct State {
    int videoIdx;
    int audioIdx;
    int subtitleIdx;

    AVFormatContext *fmtCtx;
    AVCodecContext *videoDecCtx;
    AVCodecContext *audioDecCtx;
    Queue<AVPacket> *pktQueue;
    Queue<AVFrame> *videoFrameQueue;
    Queue<AVFrame> *audioFrameQueue;

    explicit State();
    ~State();
};

#endif //MYPLAYER_STATE_H

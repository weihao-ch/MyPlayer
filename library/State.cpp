//
// Created by 13918 on 2023/9/20.
//

#include "State.h"

State::State()
{
    videoIdx = -1;
    audioIdx = -1;
    subtitleIdx = -1;

    auto unrefPkt = [](AVPacket *pkt) { av_packet_unref(pkt); };
    auto unrefFrame = [](AVFrame *frame) { av_frame_unref(frame); };

    fmtCtx = avformat_alloc_context();
    pktQueue = new Queue<AVPacket>(unrefPkt);
    videoFrameQueue = new Queue<AVFrame>(unrefFrame);
    audioFrameQueue = new Queue<AVFrame>(unrefFrame);
    videoDecCtx = nullptr;
    audioDecCtx = nullptr;
}

State::~State()
{
    avformat_free_context(fmtCtx);
    avcodec_free_context(&videoDecCtx);
    avcodec_free_context(&audioDecCtx);

    delete pktQueue;
    delete videoFrameQueue;
    delete audioDecCtx;
}
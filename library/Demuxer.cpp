//
// Created by 13918 on 2023/9/3.
//

#include "Demuxer.h"

Demuxer::Demuxer(AVFormatContext *ctx, MediaInfo *info, Queue<AVPacket> *pktQueue)
    : fmtCtx(ctx), mediaInfo(info), pktQueue(pktQueue)
{
    pkt = av_packet_alloc();
}

void Demuxer::run()
{
    while (av_read_frame(fmtCtx, pkt) >= 0) {
        pktQueue->push(pkt);
    }
}

void Demuxer::demux()
{
    this->start();
}

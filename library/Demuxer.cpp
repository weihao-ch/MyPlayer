//
// Created by 13918 on 2023/9/3.
//

#include "Demuxer.h"

Demuxer::Demuxer(State *state)
        : state(state)
{}

void Demuxer::run()
{
    AVPacket *pkt = av_packet_alloc();
    while (av_read_frame(state->fmtCtx, pkt) >= 0) {
        state->pktQueue->push(pkt);
        pkt = av_packet_alloc();
    }

    av_packet_free(&pkt);
}

void Demuxer::demux()
{
    this->start();
}

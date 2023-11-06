//
// Created by 13918 on 2023/9/3.
//

#include "Demuxer.h"

Demuxer::Demuxer(State *state)
    : state(state)
{
    pkt = av_packet_alloc();
}

void Demuxer::run()
{
    while (av_read_frame(state->fmtCtx, pkt) >= 0) {
        state->pktQueue->push(*pkt);
    }
}

void Demuxer::demux()
{
    this->start();
}

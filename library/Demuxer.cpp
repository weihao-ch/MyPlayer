//
// Created by 13918 on 2023/9/3.
//

#include "Demuxer.h"

Demuxer::Demuxer(AVFormatContext *ctx, MediaInfo *info, PktQueue *vQueue, PktQueue *aQueue)
        : fmtCtx(ctx), mediaInfo(info), videoQueue(vQueue), audioQueue(aQueue)
{

}

void Demuxer::run()
{

}

void Demuxer::demux()
{

}

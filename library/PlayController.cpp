//
// Created by LiuWeihao on 2023/9/4.
//

#include "PlayController.h"

PlayController::PlayController(QObject *parent)
{
    mediaInfo = new MediaInfo();
    fmtCtx = avformat_alloc_context();
    videoFrameQueue = new PktQueue();
    audioFrameQueue = new PktQueue();
    parser = new Parser(fmtCtx, mediaInfo, videoDecCtx, audioDecCtx);
    demuxer = new Demuxer(fmtCtx, mediaInfo, videoPktQueue, audioPktQueue);
}

PlayController::~PlayController()
{
    delete mediaInfo;
    mediaInfo = nullptr;
    avformat_free_context(fmtCtx);
    fmtCtx = nullptr;
}

void PlayController::startPlay(const QString &filePath)
{
    parser->parse(filePath);
    demuxer->demux();
}

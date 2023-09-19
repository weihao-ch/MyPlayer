//
// Created by LiuWeihao on 2023/9/4.
//

#include "PlayController.h"

PlayController::PlayController(QObject *parent)
{
    mediaInfo = new MediaInfo();
    fmtCtx = avformat_alloc_context();
    pktQueue = new Queue<AVPacket>();
    videoFrameQueue = new Queue<AVFrame>();
    audioFrameQueue = new Queue<AVFrame>();

    parser = new MediaParser(fmtCtx, mediaInfo, videoDecCtx, audioDecCtx);
    demuxer = new Demuxer(fmtCtx, mediaInfo, pktQueue);
    decoder = new Decoder(videoDecCtx,
                          audioDecCtx, mediaInfo, pktQueue,
                          videoFrameQueue, audioFrameQueue);
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
    decoder->decode();
}

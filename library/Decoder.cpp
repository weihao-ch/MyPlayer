//
// Created by 13918 on 2023/9/19.
//

#include "Decoder.h"
#include "def.h"

Decoder::Decoder(AVCodecContext *vDecCtx, AVCodecContext *aDecCtx, MediaInfo *info,
                 Queue<AVPacket> *pktQueue, Queue<AVFrame> *vFrameQueue, Queue<AVFrame> *aFrameQueue) :
    videoDecCtx(vDecCtx),
    audioDecCtx(aDecCtx),
    pktQueue(pktQueue),
    videoFrameQueue(vFrameQueue),
    audioFrameQueue(aFrameQueue),
    mediaInfo(info)
{
    frame = av_frame_alloc();
}

void Decoder::run()
{
    while (true) {
        int rc = 0;
        AVPacket pkt = pktQueue->pop();
        int idx = pkt.stream_index;
        rc = avcodec_send_packet(videoDecCtx, &pkt);
        if (FF_ERROR(rc)) {

        }

        while (rc >= 0) {
            if (idx == mediaInfo->getVideoIdx()) {
                rc = avcodec_receive_frame(videoDecCtx, frame);
                if (FF_ERROR(rc)) {

                }
                videoFrameQueue->push(frame);
            } else if (idx == mediaInfo->getAudioIdx()) {
                rc = avcodec_receive_frame(audioDecCtx, frame);
                if (FF_ERROR(rc)) {

                }
                audioFrameQueue->push(frame);
            }
        }

        av_packet_unref(&pkt);
    }
}

void Decoder::decode()
{
    this->run();
}



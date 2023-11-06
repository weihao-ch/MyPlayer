//
// Created by 13918 on 2023/9/19.
//

#include "Decoder.h"
#include "def.h"

Decoder::Decoder(State *state) : state(state)
{

}

void Decoder::run()
{
    while (true) {
        int rc = 0;
        AVPacket pkt = state->pktQueue->pop();
        int idx = pkt.stream_index;

        if (idx == state->videoIdx) {
            rc = avcodec_send_packet(state->videoDecCtx, &pkt);
            while (rc >= 0) {
                AVFrame *f = av_frame_alloc();
                rc = avcodec_receive_frame(state->videoDecCtx, f);
                if (!rc) {
                    state->videoFrameQueue->push(*f);
                }
            }
        }

//        while (rc >= 0) {
//            if (idx == state->videoIdx) {
//
//                rc = avcodec_receive_frame(state->videoDecCtx, frame);
//                if (FF_ERROR(rc)) {
//
//                }
//                state->videoFrameQueue->push(frame);
//            } else if (idx == state->audioIdx) {
//                rc = avcodec_receive_frame(state->audioDecCtx, frame);
//                if (FF_ERROR(rc)) {
//
//                }
//                state->audioFrameQueue->push(frame);
//            }
//        }

        av_packet_unref(&pkt);
    }
}

void Decoder::decode()
{
    this->start();
}

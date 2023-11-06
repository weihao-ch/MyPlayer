//
// Created by liuweihao on 2023/10/19.
//

#include "Renderer.h"
#include "ui.h"

Renderer::Renderer(State *state) : state(state)
{
    videoClk = 0;
    audioClk = 0;
}

void Renderer::run()
{
    while(true) {
//        AVFrame audioFrame = state->audioFrameQueue->pop();
        AVFrame videoFrame = state->videoFrameQueue->pop();
        double pts = videoFrame.pts;
        if (videoFrame.best_effort_timestamp == AV_NOPTS_VALUE) {
            pts = 0;
        }

        AVRational timeBase = state->fmtCtx->streams[state->videoIdx]->time_base;
        pts *= av_q2d(timeBase);

        if (pts == 0) {
            pts = videoClk;
        } else {
            videoClk = pts;
        }

        double delay = 0;
        delay = av_q2d(timeBase);
        delay += videoFrame.repeat_pict * (delay * 0.5);

        videoClk += delay;

        emit show(videoFrame, delay * 1000);

        av_frame_unref(&videoFrame);
    }
}


void Renderer::render()
{
    this->start();
}


//
// Created by liuweihao on 2023/11/5.
//

#include <QScreen>
#include <QApplication>
#include "PlayGround.h"

PlayGround::PlayGround(QWidget *parent) : QWidget(parent)
{
    initSDL();
    swsCtx = nullptr;
    frameRatio = -1;
    renderW = -1;
    renderH = -1;
    sdlWidth = -1;
    sdlHeight = -1;
    sdlRect = {0, 0, 0, 0};
}

PlayGround::~PlayGround()
{
    sws_freeContext(swsCtx);
    SDL_DestroyTexture(sdlTexture);
    SDL_DestroyRenderer(sdlRenderer);
}

double PlayGround::getScreenFactor()
{
    const int baseDpi = 96;
    QScreen *screen = qApp->primaryScreen();
    qreal realDpi = screen->logicalDotsPerInch();
    qreal ratio = screen->devicePixelRatio();

    return realDpi * ratio / baseDpi;
}

void PlayGround::createTexture()
{
    double sdlRation = sdlWidth / static_cast<double>(sdlHeight);
    double renderRatio = frameRatio == -1 ? sdlRation : frameRatio;

    if (sdlRation > renderRatio) {
        renderW = sdlHeight * frameRatio;
        renderH = sdlHeight;
        sdlRect.x = (sdlWidth - renderW) / 2;
        sdlRect.y = 0;
    } else {
        renderW = sdlWidth;
        renderH = sdlWidth * (1 / frameRatio);
        sdlRect.x = 0;
        sdlRect.y = (sdlHeight - renderH) / 2;
    }

    sdlRect.w = renderW;
    sdlRect.h = renderH;

    sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888,
                                   SDL_TEXTUREACCESS_STREAMING, renderW, renderH);
}


void PlayGround::resizeEvent(QResizeEvent *event)
{
    std::unique_lock<std::mutex> lk(mutex);

    double scFactor = getScreenFactor();
    sdlWidth = event->size().width() * scFactor;
    sdlHeight = event->size().height() * scFactor;

    if (sdlWin == nullptr) {
        sdlWin = SDL_CreateWindowFrom((void *) winId());
    }

    if (sdlRenderer == nullptr) {
        sdlRenderer = SDL_CreateRenderer(sdlWin, -1, SDL_RENDERER_ACCELERATED);
    }

    if (sdlTexture != nullptr) {
        SDL_DestroyTexture(sdlTexture);
    }

    createTexture();

    SDL_RenderClear(sdlRenderer);
    SDL_RenderPresent(sdlRenderer);
}

void PlayGround::initSDL()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // 关闭QT控件的自动刷新，否则会与SDL冲突
    setUpdatesEnabled(false);

    sdlWin = nullptr;
    sdlRenderer = nullptr;
    sdlTexture = nullptr;
}

void PlayGround::showScreen(AVFrame *frame, uint32_t delay)
{
    std::unique_lock<std::mutex> lk(mutex);

    if (frameRatio == -1) {
        frameRatio = frame->width / static_cast<double>(frame->height);
        SDL_DestroyTexture(sdlTexture);
        createTexture();
    }

    swsCtx = sws_getContext(frame->width, frame->height,
                            (AVPixelFormat) frame->format,
                            renderW, renderH, AV_PIX_FMT_RGB32,
                            SWS_BICUBLIN, nullptr, nullptr, nullptr);

    uint8_t *dstData[4] = {nullptr};
    int lineSize[4] = {0};
    av_image_alloc(dstData, lineSize, renderW, renderH, AV_PIX_FMT_RGB32, 1);
    sws_scale(swsCtx, frame->data, frame->linesize,
              0, frame->height, dstData, lineSize);

    SDL_UpdateTexture(sdlTexture, nullptr, dstData[0], lineSize[0]);
    SDL_RenderClear(sdlRenderer);

    SDL_RenderCopy(sdlRenderer, sdlTexture, nullptr, &sdlRect);
    SDL_RenderPresent(sdlRenderer);

    SDL_Delay(delay);

    av_freep(&dstData[0]);
    sws_freeContext(swsCtx);
}
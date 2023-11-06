//
// Created by liuweihao on 2023/11/5.
//

#include "PlayGround.h"

PlayGround::PlayGround(QWidget *parent) : QWidget(parent)
{
    initSDL();
}

PlayGround::~PlayGround()
{
    sws_freeContext(swsCtx);
    SDL_DestroyTexture(sdlTexture);
    SDL_DestroyRenderer(sdlRenderer);
}

void PlayGround::resizeEvent(QResizeEvent *event)
{
    std::unique_lock<std::mutex> lk(mutex);
    sdlWidth = event->size().width();
    sdlHeight = event->size().height();

    if (sdlWin == nullptr) {
        sdlWin = SDL_CreateWindowFrom((void *) winId());
    }

    if (sdlRenderer == nullptr) {
        sdlRenderer = SDL_CreateRenderer(sdlWin, -1, SDL_RENDERER_ACCELERATED);
    }

    if (sdlTexture != nullptr) {
        SDL_DestroyTexture(sdlTexture);
    }

    sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888,
                                   SDL_TEXTUREACCESS_STREAMING, sdlWidth, sdlHeight);

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

void PlayGround::showScreen(AVFrame frame, uint32_t delay)
{
    std::unique_lock<std::mutex> lk(mutex);
    swsCtx = sws_getContext(frame.width, frame.height,
                            (AVPixelFormat) frame.format,
                            sdlWidth, sdlHeight, AV_PIX_FMT_RGB32,
                            SWS_BICUBLIN, nullptr, nullptr, nullptr);

    uint8_t *dstData[4] = {nullptr};
    int lineSize[4] = {0};
    av_image_alloc(dstData, lineSize, sdlWidth, sdlHeight, AV_PIX_FMT_RGB32, 1);
    sws_scale(swsCtx, frame.data, frame.linesize,
              0, frame.height, dstData, lineSize);

    SDL_UpdateTexture(sdlTexture, nullptr, dstData[0], lineSize[0]);
    SDL_RenderClear(sdlRenderer);
    SDL_Rect sdl_rect;
    sdl_rect.x = 0;
    sdl_rect.y = 0;
    sdl_rect.w = sdlWidth;
    sdl_rect.h = sdlHeight;

    SDL_RenderCopy(sdlRenderer, sdlTexture, nullptr, &sdl_rect);
    SDL_RenderPresent(sdlRenderer);

    SDL_Delay(delay);
}
//
// Created by liuweihao on 2023/11/5.
//

#ifndef MYPLAYER_PLAYGROUND_H
#define MYPLAYER_PLAYGROUND_H

#include <mutex>
#include <QWidget>
#include <QResizeEvent>
#include "SDL2/SDL.h"

extern "C" {
#include "libswscale/swscale.h"
#include "libavutil/imgutils.h"
}


class PlayGround : public QWidget {
    Q_OBJECT
public:
    explicit PlayGround(QWidget *parent = nullptr);

    ~PlayGround() override;

    void showScreen(AVFrame *frame, uint32_t delay);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void initSDL();
    double getScreenFactor();
    void createTexture();

private:
    SwsContext *swsCtx;

    std::mutex mutex;

    SDL_Window *sdlWin;
    SDL_Renderer *sdlRenderer;
    SDL_Texture *sdlTexture;
    SDL_Rect sdlRect;
    double frameRatio;
    int renderW;
    int renderH;
    int sdlWidth;
    int sdlHeight;
};


#endif //MYPLAYER_PLAYGROUND_H

//
// Created by liuweihao on 2023/10/19.
//

#ifndef MYPLAYER_RENDERER_H
#define MYPLAYER_RENDERER_H

#include <QThread>
#include "State.h"

class Renderer : public QThread {
Q_OBJECT

public:
    explicit Renderer(State *state);

    void run() override;

    void avSync();

public slots:

    void render();

signals:

    void show(AVFrame frame, uint32_t delay);

private:
    State *state;
    double videoClk;
    double audioClk;
};

#endif //MYPLAYER_RENDERER_H

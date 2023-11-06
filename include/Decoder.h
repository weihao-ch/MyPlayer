//
// Created by 13918 on 2023/9/19.
//

#ifndef MYPLAYER_DECODER_H
#define MYPLAYER_DECODER_H

#include <QThread>
#include "State.h"
#include "MediaInfo.h"

class Decoder : public QThread {
Q_OBJECT

public:
    explicit Decoder(State *state);

    void run() override;

public slots:

    void decode();

private:
    AVFrame *frame;
    State *state;
};


#endif //MYPLAYER_DECODER_H

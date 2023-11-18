//
// Created by 13918 on 2023/9/3.
//

#ifndef MYPLAYER_DEMUXER_H
#define MYPLAYER_DEMUXER_H

#include <QThread>
#include "State.h"
#include "MediaInfo.h"

class Demuxer : public QThread {
Q_OBJECT

public:
    explicit Demuxer(State *state);

    void run() override;

public slots:

    void demux();

private:
    State *state;
//    AVPacket *pkt;
};


#endif //MYPLAYER_DEMUXER_H

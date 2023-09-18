//
// Created by 13918 on 2023/9/4.
//

#ifndef MEDIAPLAYER_PKTQUEUE_H
#define MEDIAPLAYER_PKTQUEUE_H

#include <QQueue>

extern "C" {
#include "libavformat/avformat.h"
}

class PktQueue {
public:

private:
    QQueue<AVPacket> queue;
};


#endif //MEDIAPLAYER_PKTQUEUE_H

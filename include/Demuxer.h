//
// Created by 13918 on 2023/9/3.
//

#ifndef MEDIAPLAYER_DEMUXER_H
#define MEDIAPLAYER_DEMUXER_H

#include <QThread>
#include "PktQueue.h"
#include "Parser.h"

class Demuxer : public QThread {
public:
    Demuxer();

    MediaInfo *getMediaInfo();

    void run() override;

    void demux();

private:
    Parser *parser;
    MediaInfo info;
    AVFormatContext *fmtCtx;
    PktQueue videoQueue;
    PktQueue audioQueue;
};


#endif //MEDIAPLAYER_DEMUXER_H

//
// Created by 13918 on 2023/9/3.
//

#ifndef MEDIAPLAYER_PARSER_H
#define MEDIAPLAYER_PARSER_H

#include <QString>
#include <QTime>
#include "MediaInfo.h"

extern "C" {
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
}

class Parser {
public:
    explicit Parser(AVFormatContext *ctx, MediaInfo *info, AVCodecContext *videoDecCtx, AVCodecContext *audioDecCtx);

    void parse(const QString &filePath);

private:
    int openCodecContext(AVCodecContext **decCtx, enum AVMediaType type);

private:
    MediaInfo *mediaInfo;
    AVFormatContext *fmtCtx;
    AVCodecContext *videoDecCtx;
    AVCodecContext *audioDecCtx;

};


#endif //MEDIAPLAYER_PARSER_H

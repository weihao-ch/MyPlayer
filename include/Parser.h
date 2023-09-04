//
// Created by 13918 on 2023/9/3.
//

#ifndef MEDIAPLAYER_PARSER_H
#define MEDIAPLAYER_PARSER_H

#include <QString>
#include <QTime>
#include "MediaInfo.h"
#include "libavformat/avformat.h"


class Parser {
public:
    Parser(const QString &filePath, AVFormatContext *ctx);

    MediaInfo parse();

private:
    QString filePath;
    AVFormatContext *fmtCtx;

};


#endif //MEDIAPLAYER_PARSER_H

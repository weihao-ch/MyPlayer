//
// Created by 13918 on 2023/9/3.
//

#ifndef MYPLAYER_MEDIAPARSER_H
#define MYPLAYER_MEDIAPARSER_H

#include <QString>
#include "MediaInfo.h"
#include "State.h"

class MediaParser : public QObject {
Q_OBJECT

public:
    explicit MediaParser(State *state, MediaInfo *info);

    void parse(const QString &filePath);

private:
    int openCodecContext(AVCodecContext **decCtx, enum AVMediaType type);

signals:

    void startThraed();

private:
    MediaInfo *mediaInfo;
    State *state;

};


#endif //MYPLAYER_MEDIAPARSER_H

//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_PLAYCONTROLLER_H
#define MYPLAYER_PLAYCONTROLLER_H

#include "State.h"
#include "MediaParser.h"
#include "Demuxer.h"
#include "Decoder.h"
#include "Renderer.h"

class PlayController : public QObject {
Q_OBJECT

public:
    explicit PlayController(QWidget *parent);

    ~PlayController() override;

public slots:

    void startPlay(const QString &filePath);

private:
    void initSlots();

private:
    QWidget *parent;
    MediaInfo *mediaInfo;
    MediaParser *parser;
    Demuxer *demuxer;
    Decoder *decoder;
    Renderer *renderer;
    State *state;
};


#endif //MYPLAYER_PLAYCONTROLLER_H

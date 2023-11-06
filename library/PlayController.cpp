//
// Created by LiuWeihao on 2023/9/4.
//

#include "PlayController.h"
#include "MainWindow.h"

PlayController::PlayController(QWidget *parent) : parent(parent)
{
    mediaInfo = new MediaInfo();
    state = new State();

    parser = new MediaParser(state, mediaInfo);
    demuxer = new Demuxer(state);
    decoder = new Decoder(state);
    renderer = new Renderer(state);

    initSlots();
}

PlayController::~PlayController()
{
    delete mediaInfo;
    delete parser;
    delete demuxer;
    delete decoder;
}

void PlayController::startPlay(const QString &filePath)
{
    parser->parse(filePath);
}

void PlayController::initSlots()
{
    connect(renderer, SIGNAL(show(AVFrame, uint32_t)),
            dynamic_cast<MainWindow*>(parent), SLOT(showScreen(AVFrame, uint32_t)), Qt::DirectConnection);
    connect(parser, SIGNAL(startThraed()), demuxer, SLOT(demux()));
    connect(parser, SIGNAL(startThraed()),decoder , SLOT(decode()));
    connect(parser, SIGNAL(startThraed()), renderer, SLOT(render()));
}
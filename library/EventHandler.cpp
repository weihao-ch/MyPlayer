//
// Created by LiuWeihao on 2023/9/4.
//

#include "EventHandler.h"

EventHandler::EventHandler(Ui::MainWindow *ui, QWidget *parent)
        : ui(ui), parent(parent)
{
    playController = new PlayController(this);
    initSlots();
}

void EventHandler::play()
{
    QString filePath = ui->btnOpenUrl->text();
    playController->startPlay(filePath);
}

void EventHandler::stop()
{

}

void EventHandler::initSlots()
{

}

EventHandler::~EventHandler()
{
    delete playController;
}

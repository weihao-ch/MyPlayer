//
// Created by LiuWeihao on 2023/9/4.
//

#include <QFileDialog>
#include "EventHandler.h"

EventHandler::EventHandler(Ui::MainWindow *ui, QWidget *parent)
        : ui(ui), parent(parent)
{
    playController = new PlayController(this);
    initSlots();
}

void EventHandler::play()
{
    const QString filePath = QFileDialog::getOpenFileName(parent, "open file", "D:/");
    if (filePath.isEmpty()) {
        return;
    }
    ui->lineEdit->setText(filePath);
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

//
// Created by LiuWeihao on 2023/9/4.
//

#include <QFileDialog>
#include "EventHandler.h"

EventHandler::EventHandler(Ui::MainWindow *ui, QWidget *parent)
        : ui(ui), parent(parent)
{
    playController = new PlayController(parent);
    initSlots();
}

void EventHandler::play()
{
//    const QString filePath = QFileDialog::getOpenFileName(parent, "open file", "D:/");
//    const QString filePath = "E:\\IDMDownload\\Video\\测试视频\\trailer.mp4";
    const QString filePath = "C:\\Users\\liuweihao\\Downloads\\进击的巨人.Shingeki.no.Kyojin.S04E85.mp4";
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

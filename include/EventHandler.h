//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_EVENTHANDLER_H
#define MYPLAYER_EVENTHANDLER_H

#include <QWidget>
#include "PlayController.h"
#include "ui.h"

class EventHandler : public QObject {
Q_OBJECT
public:
    explicit EventHandler(Ui::MainWindow *ui, QWidget *parent = nullptr);

    ~EventHandler() override;

public slots:

    void play();

    void stop();

private:
    void initSlots();

private:
    QWidget *parent;
    Ui::MainWindow *ui;
    PlayController *playController;
};


#endif //MYPLAYER_EVENTHANDLER_H

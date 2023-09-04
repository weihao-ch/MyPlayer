//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_MAINWINDOW_H
#define MYPLAYER_MAINWINDOW_H

#include <QMainWindow>
#include "EventHandler.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    void initSlots();

private:
    Ui::MainWindow *ui;
    EventHandler *eventHandler;
};

#endif //MYPLAYER_MAINWINDOW_H

//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_MAINWINDOW_H
#define MYPLAYER_MAINWINDOW_H

#include <QMainWindow>
#include "EventHandler.h"
#include "SDL2/SDL.h"
#include "ui.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    void showScreen(AVFrame frame, uint32_t delay);

private:
    void initSlots();

private:
    Ui::MainWindow *ui;
    EventHandler *eventHandler;

};

#endif //MYPLAYER_MAINWINDOW_H

//
// Created by LiuWeihao on 2023/9/4.
//

#ifndef MYPLAYER_MAINWINDOW_H
#define MYPLAYER_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();



private:
    Ui::MainWindow *ui;
};

#endif //MYPLAYER_MAINWINDOW_H

//
// Created by LiuWeihao on 2023/9/4.
//

#include "MainWindow.h"
// 不能删，有这个头文件才会触发UIC
#include "../ui/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    eventHandler = new EventHandler(ui, this);
    initSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eventHandler;
}

void MainWindow::initSlots()
{
    connect(ui->btnOpenLocal, SIGNAL(clicked(bool)), eventHandler, SLOT(play()));
}

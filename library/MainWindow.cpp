//
// Created by LiuWeihao on 2023/9/4.
//

#include "MainWindow.h"

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
}

void MainWindow::initSlots()
{
    connect(ui->btnOpenLocal, SIGNAL(clicked(bool)), eventHandler, SLOT(play()));
}

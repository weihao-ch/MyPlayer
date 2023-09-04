//
// Created by LiuWeihao on 2023/9/4.
//

#include "MainWindow.h"
#include "../ui/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
//
// Created by LiuWeihao on 2023/9/4.
//

#include <QResizeEvent>
#include "MainWindow.h"
// 不能删，有这个头文件才会触发UIC
#include "../ui/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : ui(new Ui::MainWindow)
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

//void MainWindow::timerEvent(QTimerEvent *ev)
//{
//    unsigned char *rgb = NULL;
//    rgb = new unsigned char[sdlHeight * sdlWidth * 4];
//    static unsigned char tmp = 255;
//    tmp--;
//    for (int j = 0; j < sdlHeight; j++) {
//        int b = j * sdlWidth * pixSize;
//        for (int i = 0; i < sdlWidth * pixSize; i += pixSize) {
//            rgb[b + i] = 0;           //B
//            rgb[b + i + 1] = 0;       //G
//            rgb[b + i + 2] = tmp;     //R
//            rgb[b + i + 3] = 0;       //A
//        }
//    }
//    //5 内存数据写入材质
//    SDL_UpdateTexture(sdlTexture, NULL, rgb, sdlWidth * pixSize);
//    //6 清理屏幕
//    SDL_RenderClear(sdlRenderer);
//    SDL_Rect sdl_rect;
//    sdl_rect.x = 0;
//    sdl_rect.y = 0;
//    sdl_rect.w = sdlWidth;
//    sdl_rect.h = sdlHeight;
//    //7 复制材质到渲染器
//    SDL_RenderCopy(sdlRenderer, sdlTexture,
//                   NULL,//原图位置和尺寸
//                   &sdl_rect//目标位置和尺寸
//    );
//    //8 渲染
//    SDL_RenderPresent(sdlRenderer);
//    delete rgb;
//}

void MainWindow::showScreen(AVFrame frame, uint32_t delay)
{
    ui->playGround->showScreen(frame, delay);
}
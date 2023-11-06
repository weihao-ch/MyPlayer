#include <QApplication>
#include "MainWindow.h"

#undef main
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}

//#include "gtest/gtest.h"
//int main(int argc, char *argv[]) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
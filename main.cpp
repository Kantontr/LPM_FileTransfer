#include "mainwindow.h"
#include <QApplication>
#include "install.h"

int main(int argc, char *argv[])
{

    std::cout<<"main"<<std::endl;
    install();



    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

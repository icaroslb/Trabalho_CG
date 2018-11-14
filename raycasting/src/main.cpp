#include "headers/mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.resize(500,500);
    window.setWindowTitle("Computação Gráfica I");
    window.show();


    return a.exec();
}

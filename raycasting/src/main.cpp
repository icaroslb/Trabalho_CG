#include "headers/mainwindow.h"
#include <QApplication>
#include "../headers/objeto.h"

int main(int argc, char *argv[])
{
    std :: vector<Objeto> objetos;
    QApplication a(argc, argv);
    MainWindow window;
    window.resize(500,500);
    window.setWindowTitle("Computação Gráfica I");
    window.show();


    return a.exec();
}

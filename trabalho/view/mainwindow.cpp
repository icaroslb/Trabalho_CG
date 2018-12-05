#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap imgEscalonar("../trabalho/imgs/escalonar.png"),
            imgRotacionar("../trabalho/imgs/rotacionar.png"),
            imgMover("../trabalho/imgs/mover.png"),
            imgCisalhar("../trabalho/imgs/cisalhar.png"),
            imgEspelhar("../trabalho/imgs/espelhar.png");

    QIcon iconEscalonar(imgEscalonar),
          iconRotacionar(imgRotacionar),
          iconMover(imgMover),
          iconCisalhar(imgCisalhar),
          iconEspelhar(imgEspelhar);

    ui->escalonar->setIcon(iconEscalonar);
    ui->escalonar->setIconSize(ui->escalonar->size());

    ui->rotacionar->setIcon(iconRotacionar);
    ui->rotacionar->setIconSize(ui->rotacionar->size());

    ui->mover->setIcon(iconMover);
    ui->mover->setIconSize(ui->mover->size());

    ui->cisalhar->setIcon(iconCisalhar);
    ui->cisalhar->setIconSize(ui->cisalhar->size());

    ui->espelhar->setIcon(iconEspelhar);
    ui->espelhar->setIconSize(ui->espelhar->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

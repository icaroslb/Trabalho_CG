#include "pintar.h"
#include "ui_pintar.h"

pintar::pintar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pintar)
{
    ui->setupUi(this);
}

pintar::~pintar()
{
    delete ui;
}

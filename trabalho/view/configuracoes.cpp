#include "configuracoes.h"
#include "ui_configuracoes.h"

Configuracoes::Configuracoes(QWidget *parent, GLWidget *tela) :
    QDialog(parent),
    ui(new Ui::Configuracoes)
{
    ui->setupUi(this);

    this->tela = tela;
}

Configuracoes::~Configuracoes()
{
    delete ui;
}

void Configuracoes::on_buttonBox_accepted()
{
    tela->mudarCanvas(ui->tlargCanvas->text().toInt(), ui->taltCanvas->text().toInt());


    this->close();
}

#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H

#include <QDialog>
#include "glwidget.h"

namespace Ui {
class Configuracoes;
}

class Configuracoes : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracoes(QWidget *parent = nullptr, GLWidget *tela = nullptr);
    ~Configuracoes();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Configuracoes *ui;

    GLWidget *tela;
};

#endif // CONFIGURACOES_H

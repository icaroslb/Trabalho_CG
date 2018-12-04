#ifndef RAYCAST_H
#define RAYCAST_H

#include "../objetos/objetos.h"
#include "../matematica/vetor.h"

#include <math.h>

class rayCast
{
    int larguraResol, alturaResol, larguraTam, alturaTam;
    double distTela, larguraPix, alturaPix;

public:
    rayCast(int larguraResol, int alturaResol,int larguraTam, int alturaTam, double distTela);

    void mudarDimencoes(int novaLargura, int novaAltura);

    PixInt* intersecao(int xLargura, int yAltura);
    double* calcularCor(Vetor *local);
    double* calcularBackGround(Vetor *raio);
    double* obterCor(int xLargura, int yAltura);
};

#endif // RAYCAST_H

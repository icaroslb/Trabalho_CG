#ifndef RAYCAST_H
#define RAYCAST_H

#include "../objetos/objetos.h"
#include "../matematica/vetor.h"
#include "../objetos/forma.h"
#include "../objetos/esfera.h"
#include "../objetos/luz.h"
#include "../objetos/material.h"
#include "../matematica/matriz.h"

#include <math.h>
#include <vector>

class rayCast
{
public:
    rayCast(int larguraResol, int alturaResol,int larguraTam, int alturaTam, double distTela);

    void mudarDimencoes(int novaLargura, int novaAltura);

    PixInt* intersecao(int xLargura, int yAltura);
    float* calcularCor(Vetor *local);
    float* calcularBackGround(Vetor *raio);
    Vetor* obterCor(int xLargura, int yAltura);

private:
    int larguraResol, alturaResol, larguraTam, alturaTam;
    double distTela, larguraPix, alturaPix;
    std::vector<Forma*> listObjetos;
};

#endif // RAYCAST_H

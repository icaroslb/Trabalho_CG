#ifndef RAYCAST_H
#define RAYCAST_H

#include "../objetos/objetos.h"
#include "../matematica/vetor.h"

#include <math.h>
#include <vector>

class rayCast
{
public:
    rayCast(int larguraResol, int alturaResol,int larguraTam, int alturaTam, float distTela);

    void mudarDimencoes(int novaLargura, int novaAltura);

    PixInt* intersecao(int xLargura, int yAltura);
    float* calcularCor(Vetor *local);
    float* calcularBackGround(Vetor *raio);
    float* obterCor(int xLargura, int yAltura);

private:
    int larguraResol, alturaResol, larguraTam, alturaTam;
    float distTela, larguraPix, alturaPix;
    std::vector<Objetos*> listObjetos;
};

#endif // RAYCAST_H

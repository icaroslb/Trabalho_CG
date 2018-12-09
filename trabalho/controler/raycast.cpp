#include "raycast.h"

rayCast::rayCast(int larguraResol, int alturaResol, int larguraTam, int alturaTam, double distTela)
{
    this->larguraResol = larguraResol;
    this->alturaResol = alturaResol;

    this->larguraTam = larguraTam;
    this->alturaTam = alturaTam;

    this->larguraPix = larguraTam/larguraResol;
    this->alturaPix = alturaTam/alturaResol;

    this->distTela = distTela;
}

void rayCast::mudarDimencoes(int novaLargura, int novaAltura){
    larguraTam = novaLargura;
    alturaTam = novaAltura;

    larguraPix = larguraTam/larguraResol;
    alturaPix = alturaTam/alturaResol;
}

PixInt* rayCast::intersecao(int xLargura, int yAltura){
    PixInt *pix = new PixInt;

    return pix;
}

double* rayCast::calcularCor(Vetor *local){
    double *corCalculada = new double[3];

    return corCalculada;
}

double* rayCast::calcularBackGround(Vetor *raio){

}

double* rayCast::obterCor(int xLargura, int yAltura){
    //xLargura = -(larguraTam/2)+(larguraPix/2)+(larguraPix*abs(larguraTam/larguraPix));
    //yAltura = (alturaTam/2)-(alturaPix/2)-(alturaPix*abs(alturaTam/alturaPix));

    Vetor raio(xLargura, yAltura, distTela);
    PixInt *inter = this->intersecao(xLargura, yAltura);
    double *cores = new double[3];

    /*if(inter->intercedeu)
        cores = calcularCor(raio*(inter->inter));
    else
        cores = calcularBackGround(&raio);*/
    cores[X] = 1;
    cores[Y] = 1;
    cores[Z] = 1;

    return cores;
}

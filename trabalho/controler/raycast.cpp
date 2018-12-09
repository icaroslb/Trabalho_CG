#include "raycast.h"

rayCast::rayCast(int larguraResol, int alturaResol, int larguraTam, int alturaTam, float distTela)
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
    PixInt *pix = new PixInt, *aux;
    yAltura = alturaTam - yAltura;
    int quantObjetos = listObjetos.size();

    pix->intercedeu = false;
    pix->inter = INFINITY;
    Vetor raio(-(larguraResol/2)+(larguraPix/2)+(larguraPix * xLargura),
                           (alturaResol/2)-(alturaPix/2)-(alturaPix * yAltura), distTela),
          origem(0,0,0);

    for(int i = 0; i < quantObjetos; i++){
        aux = listObjetos[i]->intercessao(&raio, &origem, pix);
        if(aux->intercedeu && aux->inter < pix->inter){
            delete pix;
            pix = aux;
        }else{
            delete aux;
        }
    }
    return pix;
}

float* rayCast::calcularCor(Vetor *local){
    float *corCalculada = new float[3];

    return corCalculada;
}

float* rayCast::calcularBackGround(Vetor *raio){

}

float* rayCast::obterCor(int xLargura, int yAltura){
    //xLargura = -(larguraTam/2)+(larguraPix/2)+(larguraPix*abs(larguraTam/larguraPix));
    //yAltura = (alturaTam/2)-(alturaPix/2)-(alturaPix*abs(alturaTam/alturaPix));

    Vetor raio(xLargura, yAltura, distTela);
    PixInt *inter = this->intersecao(xLargura, yAltura);
    float *cores = new float[3];

    /*if(inter->intercedeu)
        cores = calcularCor(raio*(inter->inter));
    else
        cores = calcularBackGround(&raio);*/
    cores[X] = 1;
    cores[Y] = 1;
    cores[Z] = 1;

    return cores;
}

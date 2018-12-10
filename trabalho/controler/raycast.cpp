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

    Vetor *vet = new Vetor(0, 0, 100);
    Vetor *mat = new Vetor(1, 0, 0);
    Material *mate = new Material(mat, mat, mat, 1);

    Esfera *esf = new Esfera(50, vet, mate);

    /*double **mundo = new double*[4];
    for(int i = X; i < W; i++)
        mundo[i] = new double[4];

    mundo[0][0] = 1;
    mundo[0][1] = 0;
    mundo[0][2] = 0;
    mundo[0][3] = 0;

    mundo[1][0] = 0;
    mundo[1][1] = 1;
    mundo[1][2] = 0;
    mundo[1][3] = 0;

    mundo[2][0] = 0;
    mundo[2][1] = 0;
    mundo[2][2] = -1;
    mundo[2][3] = 0;

    mundo[3][0] = 0;
    mundo[3][1] = 0;
    mundo[3][2] = 0;
    mundo[3][3] = 1;

    Matriz matrMundo(mundo);

    matrMundo * esf->getCentro();*/

    listObjetos.push_back(esf);
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

    pix->intercedeu = false;
    pix->inter = INFINITY;
    Vetor raio(-(larguraResol/2)+(larguraPix/2)+(larguraPix * xLargura),
                (alturaResol/2)-(alturaPix/2)-(alturaPix * yAltura), distTela),
          origem(0,0,0);

    for(int i = 0; i < listObjetos.size(); i++){
        aux = listObjetos[i]->intersecao(raio, origem);
        if(aux->intercedeu && aux->inter < pix->inter){
            free(pix);
            pix = aux;
            pix->obj = i;
        }else if(aux->intercedeu){
            free(aux);
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

Vetor* rayCast::obterCor(int xLargura, int yAltura){
    xLargura = -(larguraTam/2)+(larguraPix/2)+(larguraPix*abs(larguraTam/larguraPix));
    yAltura = (alturaTam/2)-(alturaPix/2)-(alturaPix*abs(alturaTam/alturaPix));

    Vetor raio(xLargura, yAltura, distTela);
    PixInt *inter;
    Vetor *cores;
    Vetor *amb = new Vetor(1, 1, 1);

    inter = this->intersecao(xLargura, yAltura);

    if(inter->intercedeu){
        cores = listObjetos[inter->obj]->getCorAmbiente(*amb);//calcularCor(raio*(inter->inter));
    }else{
        //cores = calcularBackGround(&raio);
        cores = new Vetor(0, 0, 0);
    }

    return cores;
}

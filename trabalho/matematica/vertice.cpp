#include "vertice.h"

Vertice::Vertice()
{

}

Vertice::Vertice(double x, double y , double z){
    this->val[X] = x;
    this->val[Y] = y;
    this->val[Z] = z;
    this->val[W] = 1;
}

double Vertice::operator [] (int pos){
    return this->val[pos];
}

Vetor* Vertice::operator - (Vertice sub){
    Vetor *subtracao = new Vetor(this->val[X] - sub.val[X],
                                 this->val[Y] - sub.val[Y],
                                 this->val[Z] - sub.val[Z]);

    return subtracao;
}

Vertice* Vertice::operator + (Vetor som){
    Vertice *soma = new Vertice(this->val[X] + som[X],
                                this->val[Y] + som[Y],
                                this->val[Z] + som[Z]);

    return soma;
}

double Vertice::operator * (Vetor prodturoEsc){
    double produtoEscalar = 0;

    for(int i = X; i < W; i++)
        produtoEscalar = this->val[i] * prodturoEsc[i];

    return produtoEscalar;
}

double Vertice::operator * (Vertice prodturoEsc){
    double produtoEscalar = 0;

    for(int i = X; i < W; i++)
        produtoEscalar = this->val[i] * prodturoEsc.val[i];

    return produtoEscalar;
}

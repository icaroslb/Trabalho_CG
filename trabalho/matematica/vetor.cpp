#include "vetor.h"

Vetor::Vetor()
{

}

Vetor::Vetor(double x, double y, double z){
    val[X] = x;
    val[Y] = y;
    val[Z] = z;
    val[W] = 0;
}

Vetor::~Vetor(){
}

double Vetor::operator [] (int pos){
    return this->val[pos];
}

double Vetor::operator * (Vetor produtoEsc){
    double produtoEscalar = 0;

    for(int i = X; i < W; i++)
        produtoEscalar += this->val[i] * produtoEsc.val[i];

    return produtoEscalar;
}

Vetor* Vetor::operator * (double escalar){
    Vetor *novoVetor = new Vetor(this->val[X] * escalar, this->val[Y] * escalar, this->val[Z] * escalar);

    return novoVetor;
}

Vetor* Vetor::operator / (double escalar){
    Vetor *novoVetor = new Vetor(this->val[X] / escalar, this->val[Y] / escalar, this->val[Z] / escalar);

    return novoVetor;
}

Vetor* Vetor::operator ->* (Vetor produtoVet){
    Vetor *produtorVetorial = new Vetor((this->val[Y] * produtoVet.val[Z]) - (this->val[Z] * produtoVet.val[Y]),
                                        (this->val[Z] * produtoVet.val[X]) - (this->val[X] * produtoVet.val[Z]),
                                        (this->val[X] * produtoVet.val[Y]) - (this->val[Y] * produtoVet.val[X]));

    return produtorVetorial;


}

Vetor* Vetor::operator - (Vetor sub){
    Vetor *subtracao = new Vetor(this->val[X] - sub.val[X],
                                 this->val[Y] - sub.val[Y],
                                 this->val[Z] - sub.val[Z]);

    return subtracao;
}

Vetor* Vetor::unitario(){
    double tamanho = sqrt(pow(this->val[X], 2) + pow(this->val[Y], 2) + pow(this->val[Z], 2));

    return (*this)/tamanho;
}

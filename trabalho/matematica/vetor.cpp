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

Vetor* Vetor::operator*(double escalar){
    Vetor *novoVetor = new Vetor(this->val[X]*escalar, this->val[Y]*escalar, this->val[Z]*escalar);

    return novoVetor;
}

#include "headers/vertice.h"

Vertice::Vertice(double x, double y, double z){
    val = new double[4];

    val[0] = x;
    val[1] = y;
    val[2] = z;
    val[3] = 1;
}

Vertice::~Vertice(){
    delete val;
}

Vetor Vertice::operator-(Vertice vert){
    Vetor novoVetor(val[0]-vert.val[0], val[1]-vert.val[1], val[2]-vert.val[2]);

    return novoVetor;
}

Vetor Vertice::operator+(Vetor vet){
    Vetor novoVet(val[0]+vet.val[0], val[1]+vet.val[1], val[2]+vet.val[2]);

    return novoVet;
}

double Vertice::operator*(Vetor vet){
    double resultado = 0;

    for(int i = 0; i < 4; i++){
        resultado += val[i] * vet.val[i];
    }

    return resultado;
}

double Vertice::operator*(Vertice vert){
    double resultado = 0;

    for(int i = 0; i < 4; i++){
        resultado += val[i] * vert.val[i];
    }

    return resultado;
}

void Vertice::operator =(double *novVal){
    delete val;
    val = novVal;
}

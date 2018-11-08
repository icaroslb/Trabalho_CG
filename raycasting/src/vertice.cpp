#include "../headers/vertice.h"

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


double Vertice::operator[](int i){
	return val[i];
}

Vetor Vertice::operator-(Vertice vert){
    Vetor novoVetor(val[0]-vert[0], val[1]-vert[1], val[2]-vert[2]);

    return novoVetor;
}

Vetor Vertice::operator+(Vetor vet){
    Vetor novoVet(val[0]+vet[0], val[1]+vet[1], val[2]+vet[2]);
    return novoVet;
}

double Vertice::operator*(Vetor vet){
    double resultado = 0;

    for(int i = 0; i < 4; i++){
        resultado += val[i] * vet[i];
    }

    return resultado;
}

double Vertice::operator*(Vertice vert){
    double resultado = 0;

    for(int i = 0; i < 4; i++){
        resultado += val[i] * vert[i];
    }

    return resultado;
}

void Vertice::operator =(double *novVal){
    delete val;
    val = novVal;
}

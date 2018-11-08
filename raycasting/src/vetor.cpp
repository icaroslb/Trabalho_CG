#include "headers/vetor.h"

Vetor::Vetor(double x, double y, double z){
    val = new double[4];

    val[0] = x;
    val[1] = y;
    val[2] = z;
    val[3] = 0;
}

Vetor::~Vetor(){
    delete val;
}

double Vetor::operator *(Vetor vet){
    double resultado = 0;

    for(int i = 0; i < 3; i++){
        resultado += val[i]*vet.val[i];
    }

    return resultado;
}

Vetor Vetor::operator*(double escalar){
    Vetor novoVetor(val[0]*escalar, val[1]*escalar, val[2]*escalar);

    return novoVetor;
}

Vetor Vetor::operator ->* (Vetor vet){
    Vetor resultado(((val[1]*vet.val[2])-(val[2]*vet.val[1])),
                   -((val[0]*vet.val[2])-(val[2]*vet.val[0])),
                   (val[0]*vet.val[1])-(val[1]*vet.val[0]));

    return resultado;
}

Vetor Vetor::operator-(Vetor vet){
    Vetor novoVetor(val[0]-vet.val[0], val[1]-vet.val[1], val[2]-vet.val[2]);

    return novoVetor;
}

Vetor Vetor::unitario(){
    double tamanho = sqrt(pow(val[0], 2)+pow(val[1], 2)+pow(val[2], 2));
    Vetor unitario(val[0]/tamanho, val[1]/tamanho, val[2]/tamanho);

    return unitario;
}

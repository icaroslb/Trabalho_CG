#ifndef VERTICE_H
#define VERTICE_H

#include "headers/vetor.h"

class Vertice{
public:
    double *val;

    Vertice(double, double, double);
    ~Vertice();

    Vetor operator-(Vertice);
    Vetor operator+(Vetor);
    double operator*(Vetor);
    double operator*(Vertice);
    void operator=(double*);
};

#endif // VERTICE_H

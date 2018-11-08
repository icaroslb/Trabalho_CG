#ifndef VERTICE_H
#define VERTICE_H

#include "headers/vetor.h"

class Vertice{
    double *val;
public:
    double *val;
    Vertice(double, double, double);
    ~Vertice();
	
	double operator[](int);
    Vetor operator-(Vertice);
    Vetor operator+(Vetor);
    double operator*(Vetor);
    double operator*(Vertice);
    void operator=(double*);
};

#endif // VERTICE_H

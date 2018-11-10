#ifndef VERTICE_H
#define VERTICE_H

#include "vetor.h"

class Vertice{
    double val[4];
public:
    Vertice(double, double, double);
    Vertice();
    //~Vertice();
	
	double operator[](int);
    Vetor operator-(Vertice);
    Vetor operator+(Vetor);
    double operator*(Vetor);
    double operator*(Vertice);
    void operator =(double*);
    bool operator==(Vertice);
};

#endif // VERTICE_H

#ifndef MATRIZ_H
#define MATRIZ_H

#include "forma.h"
#include <cmath>

class Matriz{
    double **val;
    Matriz *prox;

public:
    Matriz();
    ~Matriz();

	double* operator[](int);
    void operator=(double**);
    void operator*(Vertice);
    void operator*(Forma);
    void operator*(Matriz);
};

#endif // MATRIZ_H

#ifndef MATRIZ_H
#define MATRIZ_H

#include "../objetos/objetos.h"
#include "vetor.h"


class Matriz
{
public:
    Matriz();
    ~Matriz();

    double* operator [] (int);
    void operator = (float**);
    void operator * (Vetor*);
    void operator * (Objetos*);
    void operator * (Matriz*);

private:
    float **val;
    Matriz *prox;
};

#endif // MATRIZ_H

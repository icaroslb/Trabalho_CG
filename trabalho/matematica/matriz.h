#ifndef MATRIZ_H
#define MATRIZ_H

#include "../objetos/objetos.h"
#include "vetor.h"


class Matriz
{
public:
    Matriz();
    Matriz(double**);
    ~Matriz();

    double* operator [] (int);
    void operator = (double**);
    void operator * (Vetor*);
    void operator * (Objetos*);
    void operator * (Matriz*);

    void escala(double Sx, double Sy, double Sz, double x, double y, double z);
    void translacao(double tx, double ty, double tz);
    void cisalhar(double angulo, int eixo1, int eixo2, int eixo3);
    void rotacionar(Vetor *rot, double angulo);
    void indentidade();

private:
    double **val;
    Matriz *prox;
};

#endif // MATRIZ_H

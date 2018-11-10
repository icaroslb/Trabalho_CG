#ifndef ESFERA_H
#define ESFERA_H

#include "forma.h"

class Esfera: public Forma{
    double raio;
    Vertice centro;

public:
    Esfera(Vertice, double);
    bool intercessao(Vetor, Vetor, double&);
};

#endif // ESFERA_H

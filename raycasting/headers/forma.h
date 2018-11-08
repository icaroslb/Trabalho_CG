#ifndef FORMA_H
#define FORMA_H

#include <cmath>
#include <vector>
#include "headers/vertice.h"

class Forma{
private:
    std::vector<Vertice*> vert;
    int tamanho;
    double corAmb[3], corDif[3], corEsp[3];
public:
    virtual bool intercessao(Vetor raio, Vertice origem, double& t) = 0;
};

#endif // FORMA_H

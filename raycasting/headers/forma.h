#ifndef FORMA_H
#define FORMA_H

#include <cmath>
#include <vector>
#include "headers/vertice.h"

class Forma{
private:

public:
    std::vector<Vertice*> vert;
    int tamanho;
    double corAmb[3], corDif[3], corEsp[3];
    //virtual bool intercessao(Vetor raio, Vertice origem, double& t);
};

#endif // FORMA_H

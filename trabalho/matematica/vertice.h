#ifndef VERTICE_H
#define VERTICE_H

#include "vetor.h"

class Vertice
{
private:
    double val[4];

public:
    Vertice();
    Vertice(double x, double y , double z);

    double operator [] (int pos);
    Vetor* operator - (Vertice sub);
    Vertice* operator + (Vetor som);
    double operator * (Vetor prodturoEsc);
    double operator * (Vertice prodturoEsc);
    //void operator = (double *);
};

#endif // VERTICE_H

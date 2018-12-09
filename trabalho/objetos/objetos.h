#ifndef OBEJTOS_H
#define OBEJTOS_H

#include <iostream>
#include <vector>
#include "../matematica/vetor.h"

typedef struct PIXINT{
    bool intercedeu;
    float inter;
    int obj;
} PixInt;

typedef struct Pintar{
    float *cores;
    float x, y, z;
} pint;

class Objetos{
public:
    virtual PixInt* intercessao(Vetor *raycast, Vetor *origem, PixInt *resul);

protected:
    std::vector<Vetor*> vertices;
};


#endif // OBEJTOS_H

#ifndef OBEJTOS_H
#define OBEJTOS_H

#include <iostream>
#include <vector>
#include "../matematica/vetor.h"
#include "../matematica/vertice.h"

typedef struct PIXINT{
    bool intercedeu;
    double inter;
} PixInt;

class Objetos{
public:
    PixInt* intercessao(Vetor *raycast, Vertice *origem);

protected:
    std::vector<Vertice*> vertices;
};


#endif // OBEJTOS_H

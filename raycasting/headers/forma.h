#ifndef FORMA_H
#define FORMA_H

#include <cmath>
#include <vector>
#include "vertice.h"

class Forma{
public:
    virtual bool intercessao(Vetor, Vetor , double&) = 0;
};

#endif // FORMA_H

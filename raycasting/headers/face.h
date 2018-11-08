#ifndef FACE_H
#define FACE_H

#include "forma.h"

class Face: public Forma{
public:
    Face(Vertice*, Vertice*, Vertice*);

    Vetor normalUni();
    bool intercessao(Vetor, Vertice, double);
};

#endif // FACE_H

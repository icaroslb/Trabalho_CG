#ifndef FACE_H
#define FACE_H

#include "forma.h"
//#include "vertice.h"

class Face: public Forma{
    Vertice v1, v2, v3;
public:
    Face(Vertice, Vertice, Vertice);
    Vetor normalUni();
    bool intercessao(Vetor, Vertice, double);
};

#endif // FACE_H

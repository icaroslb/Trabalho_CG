#ifndef FACE_H
#define FACE_H

#include "forma.h"
//#include "vertice.h"
struct Face_Pts{
    Vertice *v1, *v2, *v3;
};

class Face: public Forma{
    std::vector<Face_Pts> triangulos;
    std::vector<Vertice> vertices;
public:
    Face(Vertice, Vertice, Vertice);
    Face();

    void addFace(Vertice, Vertice, Vertice);
    bool intercessao(Vetor, Vertice, double &);
};

#endif // FACE_H

#ifndef FACE_H
#define FACE_H

#include "forma.h"
//#include "vertice.h"
struct Face_Pts{
    int v1, v2, v3;
};

class Face: public Forma{
    std::vector<Face_Pts> triangulos;
    std::vector<Vertice> vertices;

public:

    Face(Vertice, Vertice, Vertice, int p1, int p2, int p3);
    Face();
    void addVertice(Vertice);
    void addFace(int, int, int);
    bool intercessao(Vetor, Vetor, double &);
    int sizeTriangulos();
    int sizeVertices();
};

#endif // FACE_H

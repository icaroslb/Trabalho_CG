#include "../headers/face.h"
#include <iostream>


Face::Face(Vertice vert1, Vertice vert2, Vertice vert3, int p1, int p2, int p3){
    addVertice(vert1);
    addVertice(vert1);
    addVertice(vert3);
    addFace(p1, p2, p3);

}

Face::Face(){

}

void Face::addVertice(Vertice v){
    vertices.push_back(v);
}


void Face::addFace(int v1, int v2, int v3){
    Face_Pts pts;
    pts.v1 = v1 ;
    pts.v2 = v2 ;
    pts.v3 = v3 ;
    triangulos.push_back(pts);
}
bool Face::intercessao(Vetor raio, Vetor ori, double& inter){}

int Face :: sizeTriangulos(){
    return triangulos.size();
}

int Face :: sizeVertices(){
    return vertices.size();
}

/*Vetor Face::normalUni(){

    Vetor vet1((*vert[0])[1] - (*vert[1])[0], (*vert[0])[1] - (*vert[1])[1], (*vert[0])[2] - (*vert[1])[2]),
          vet2((*vert[0])[0] - (*vert[2])[0], (*vert[0])[1] - (*vert[2])[1], (*vert[0])[2] - (*vert[2])[2]),

          resultado = vet1 ->* vet2;

    return resultado.unitario();
}

bool Face::intercessao(Vetor raio, Vertice ori, double inter){
    Vetor normal = this->normalUni(),
            aresta1 = (*vert[0] - *vert[1]),
            aresta2 = (*vert[1] - *vert[2]),
            aresta3 = (*vert[2] - *vert[0]);
        double a, b, c;

        inter = ((*vert[0] - ori) * normal)/(raio * normal);

        if(inter != 0.0){
            a = ((aresta1 ->* aresta2) * normal);
            b = ((aresta2 ->* aresta3) * normal);
            c = ((aresta3 ->* aresta1) * normal);

            if((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)){
                return true;
            }
        }
        return false;
}
*/

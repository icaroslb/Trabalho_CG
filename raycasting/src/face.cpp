#include "../headers/face.h"


Face::Face(Vertice vert1, Vertice vert2, Vertice vert3){
    addFace(vert1, vert2, vert3);
}

Face::Face(){

}

void Face::addFace(Vertice vert1, Vertice vert2, Vertice vert3){
    Face_Pts pts;
    int flagV1 = 0;
    int flagV2 = 0;
    int flagV3 = 0;
    for(Vertice v: vertices){
        if(vert1 == v){
            pts.v1 = &v;
            flagV1 = 1;
        }
        if(vert2 == v){
            pts.v2 = &v;
            flagV2 = 1;
        }
        if(vert3 == v){
            pts.v3 = &v;
            flagV3 = 1;
        }
    }
    if(flagV1 == 0){
        vertices.push_back(vert1);
        pts.v1 = &vert1;
    }
    if(flagV2 == 0){
        vertices.push_back(vert2);
        pts.v2 = &vert2;
    }
    if(flagV3 == 0){
        vertices.push_back(vert3);
        pts.v3 = &vert3;
    }
}
bool Face::intercessao(Vetor raio, Vertice ori, double& inter){}


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

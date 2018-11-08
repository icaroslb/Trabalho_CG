#include "headers/face.h"

Face::Face(Vertice *vert1, Vertice *vert2, Vertice *vert3){
    tamanho = 3;
    vert.push_back(vert1);
    vert.push_back(vert2);
    vert.push_back(vert3);
}

Vetor Face::normalUni(){

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

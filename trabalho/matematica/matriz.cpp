#include "matriz.h"

Matriz::Matriz(){
    val = new double*[4];

    for(int i = X; i < W; i++)
        val[i] = new double[4];
}


Matriz::Matriz(double **matr){
    val = matr;
}

Matriz::~Matriz(){}

double* Matriz::operator [] (int indice){
    return val[indice];
}

void Matriz::operator = (double **matr){
    val = matr;
}

void Matriz::operator * (Vetor *vertice){
    double aux[4];
    for(int i = X; i < W; i++){
        aux[i] = 0;
    }
    for(int i = X; i < W; i++){
        for(int j = X; j < W; j++){
            aux[i] += val[i][j] * *(*vertice)[j];
        }
    }

    for(int i = X; i < W; i++)
        *(*vertice)[i] = aux[i];
}

void Matriz::operator * (Objetos *obj){

}

void Matriz::operator * (Matriz *matr){}

void Matriz::escala(double Sx, double Sy, double Sz, double x, double y, double z){
    for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i==j){
                    switch (i) {
                    case 0: val[0][0] = Sx/x; break;
                    case 1: val[1][1] = Sy/y; break;
                    case 2: val[2][2] = Sz/z; break;
                    case 3: val[3][3] = 1; break;
                    }
                }else val[i][j] = 0;
            }
    }
}

void Matriz::translacao(double tx, double ty, double tz){
    for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(j == 3){
                    switch (i) {
                    case 0: val[0][3] = tx; break;
                    case 1: val[1][3] = ty; break;
                    case 2: val[2][3] = tz; break;
                    case 3: val[3][3] = 1; break;
                    }
                }else if(i == j) val[i][j] = 1;
                else val[i][j] = 0;
            }
    }
}

void Matriz::cisalhar(double angulo, int eixo1, int eixo2, int eixo3){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i==j){
                val[i][j] = 1;
                }else if(eixo1 == 0 && eixo2 == 1 && eixo3 == 0){   //XY X
                    if(i == 0 && j == 2) val[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 0 && eixo2 == 1 && eixo3 == 1){   //XY Y
                    if(i == 1 && j == 2) val[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 0 && eixo2 == 2 && eixo3 == 0){   //XZ X
                    if(i == 0 && j == 1) val[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 0 && eixo2 == 2 && eixo3 == 2){   //XZ Z
                    if(i == 2 && j == 1) val[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 1 && eixo2 == 2 && eixo3 == 1){   //YZ Y
                    if(i == 1 && j == 0) val[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 1 && eixo2 == 2 && eixo3 == 2){   //YZ Z
                if(i == 2 && j == 0) val[i][j] = tan(angulo);
                else val[i][j] = 0;
            }
        }
    }
}

void Matriz::rotacionar(Vetor *rot, double angulo){
    Vetor *uni = rot->unitario();

    for(int i = X; i < Z; i++)
        (*(*uni)[i]) = (*(*uni)[i]) * sin(angulo/2);
    (*(*uni)[W]) = (*(*uni)[W]) * cos(angulo/2);

    val[0][0] = pow(*(*rot)[W], 2) + pow(*(*rot)[X], 2) - pow(*(*rot)[Y], 2) - pow(*(*rot)[Z], 2);
    val[0][1] = (2 * (*(*rot)[X] * *(*rot)[Y])) - (2 * (*(*rot)[W] * *(*rot)[Z]));
    val[0][2] = (2 * (*(*rot)[X] * *(*rot)[Z])) + (2 * (*(*rot)[W] * *(*rot)[Y]));;
    val[0][3] = 0;

    val[1][0] = (2 * (*(*rot)[X] * *(*rot)[Y])) + (2 * (*(*rot)[W] * *(*rot)[Z]));;
    val[1][1] = pow(*(*rot)[W], 2) - pow(*(*rot)[X], 2) + pow(*(*rot)[Y], 2) - pow(*(*rot)[Z], 2);
    val[1][2] = (2 * (*(*rot)[Y] * *(*rot)[Z])) - (2 * (*(*rot)[W] * *(*rot)[X]));;
    val[1][3] = 0;

    val[2][0] = (2 * (*(*rot)[X] * *(*rot)[Z])) - (2 * (*(*rot)[W] * *(*rot)[Y]));;
    val[2][1] = (2 * (*(*rot)[Y] * *(*rot)[Z])) + (2 * (*(*rot)[W] * *(*rot)[X]));;
    val[2][2] = pow(*(*rot)[W], 2) - pow(*(*rot)[X], 2) - pow(*(*rot)[Y], 2) + pow(*(*rot)[Z], 2);
    val[2][3] = 0;

    val[3][0] = 0;
    val[3][1] = 0;
    val[3][2] = 0;
    val[3][3] = pow(*(*rot)[W], 2) + pow(*(*rot)[X], 2) + pow(*(*rot)[Y], 2) + pow(*(*rot)[Z], 2);
}

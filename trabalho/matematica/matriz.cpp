#include "matriz.h"

Matriz::Matriz(){
    val = new double*[4];

    for(int i = X; i < W; i++)
        val[i] = new double[4];

    indentidade();
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
    double **aux = new double*[4];

    for(int i = X; i < W; i++)
        aux[i] = new double[4];

    //Faz a matriz de escala
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i==j){
                switch (i) {
                    case 0: aux[0][0] = Sx/x; break;
                    case 1: aux[1][1] = Sy/y; break;
                    case 2: aux[2][2] = Sz/z; break;
                    case 3: aux[3][3] = 1; break;
                }
            }else aux[i][j] = 0;
        }
    }

    //Multiplica a matriz anterior com a atual
    for(int i = X; i < W; i++){
        for(int j = X; j < W; j++){
            for(int k = X; k < W; k++){
                val[i][j] += val[i][k] * aux[k][i];
            }
        }
    }

    //Exclui a matriz auxiliar
    for(int i = X; i < W; i++)
        delete aux[i];

    delete[] aux;
}

void Matriz::translacao(double tx, double ty, double tz){
    double **aux = new double*[4];

    for(int i = X; i < W; i++)
        aux[i] = new double[4];

    //Faz a matriz de translação
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j == 3){
                switch (i) {
                    case 0: aux[0][3] = tx; break;
                    case 1: aux[1][3] = ty; break;
                    case 2: aux[2][3] = tz; break;
                    case 3: aux[3][3] = 1; break;
                }
            }else if(i == j) aux[i][j] = 1;
            else val[i][j] = 0;
        }
    }

    //Multiplica a matriz anterior com a atual
    for(int i = X; i < W; i++){
        for(int j = X; j < W; j++){
            for(int k = X; k < W; k++){
                val[i][j] += val[i][k] * aux[k][i];
            }
        }
    }

    //Exclui a matriz auxiliar
    for(int i = X; i < W; i++)
        delete aux[i];

    delete[] aux;
}

void Matriz::cisalhar(double angulo, int eixo1, int eixo2, int eixo3){
    double **aux = new double*[4];

    for(int i = X; i < W; i++)
        aux[i] = new double[4];

    //Faz a matriz de cisalhamento
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i==j){
                val[i][j] = 1;
                }else if(eixo1 == 0 && eixo2 == 1 && eixo3 == 0){   //XY X
                    if(i == 0 && j == 2) aux[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 0 && eixo2 == 1 && eixo3 == 1){   //XY Y
                    if(i == 1 && j == 2) aux[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 0 && eixo2 == 2 && eixo3 == 0){   //XZ X
                    if(i == 0 && j == 1) aux[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 0 && eixo2 == 2 && eixo3 == 2){   //XZ Z
                    if(i == 2 && j == 1) aux[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 1 && eixo2 == 2 && eixo3 == 1){   //YZ Y
                    if(i == 1 && j == 0) aux[i][j] = tan(angulo);
                    else val[i][j] = 0;
                }else if(eixo1 == 1 && eixo2 == 2 && eixo3 == 2){   //YZ Z
                if(i == 2 && j == 0) aux[i][j] = tan(angulo);
                else val[i][j] = 0;
            }
        }
    }

    //Multiplica a matriz anterior com a atual
    for(int i = X; i < W; i++){
        for(int j = X; j < W; j++){
            for(int k = X; k < W; k++){
                val[i][j] += val[i][k] * aux[k][i];
            }
        }
    }

    //Exclui a matriz auxiliar
    for(int i = X; i < W; i++)
        delete aux[i];

    delete[] aux;
}

void Matriz::rotacionar(Vetor *rot, double angulo){
    Vetor *uni = rot->unitario();
    double **aux = new double*[4];

    for(int i = X; i < W; i++)
        aux[i] = new double[4];

    for(int i = X; i < Z; i++)
        (*(*uni)[i]) = (*(*uni)[i]) * sin(angulo/2);

    (*(*uni)[W]) = (*(*uni)[W]) * cos(angulo/2);

    //Faz a matriz de rotação
    aux[0][0] = pow(*(*rot)[W], 2) + pow(*(*rot)[X], 2) - pow(*(*rot)[Y], 2) - pow(*(*rot)[Z], 2);
    aux[0][1] = (2 * (*(*rot)[X] * *(*rot)[Y])) - (2 * (*(*rot)[W] * *(*rot)[Z]));
    aux[0][2] = (2 * (*(*rot)[X] * *(*rot)[Z])) + (2 * (*(*rot)[W] * *(*rot)[Y]));;
    aux[0][3] = 0;

    aux[1][0] = (2 * (*(*rot)[X] * *(*rot)[Y])) + (2 * (*(*rot)[W] * *(*rot)[Z]));;
    aux[1][1] = pow(*(*rot)[W], 2) - pow(*(*rot)[X], 2) + pow(*(*rot)[Y], 2) - pow(*(*rot)[Z], 2);
    aux[1][2] = (2 * (*(*rot)[Y] * *(*rot)[Z])) - (2 * (*(*rot)[W] * *(*rot)[X]));;
    aux[1][3] = 0;

    aux[2][0] = (2 * (*(*rot)[X] * *(*rot)[Z])) - (2 * (*(*rot)[W] * *(*rot)[Y]));;
    aux[2][1] = (2 * (*(*rot)[Y] * *(*rot)[Z])) + (2 * (*(*rot)[W] * *(*rot)[X]));;
    aux[2][2] = pow(*(*rot)[W], 2) - pow(*(*rot)[X], 2) - pow(*(*rot)[Y], 2) + pow(*(*rot)[Z], 2);
    aux[2][3] = 0;

    aux[3][0] = 0;
    aux[3][1] = 0;
    aux[3][2] = 0;
    aux[3][3] = pow(*(*rot)[W], 2) + pow(*(*rot)[X], 2) + pow(*(*rot)[Y], 2) + pow(*(*rot)[Z], 2);

    //Multiplica a matriz anterior com a atual
    for(int i = X; i < W; i++){
        for(int j = X; j < W; j++){
            for(int k = X; k < W; k++){
                val[i][j] += val[i][k] * aux[k][i];
            }
        }
    }

    //Exclui a matriz auxiliar
    for(int i = X; i < W; i++)
        delete aux[i];

    delete[] aux;
}

void Matriz::indentidade(){
    for(int i = X; i < W; i++){
        for(int j = X; j < W; j++){
            if(i == j)
                val[i][j] = 1;
            else
                val[i][j] = 0;
        }
    }
}

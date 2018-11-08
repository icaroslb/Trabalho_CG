#include "../Headers/matrizrotacao.h"

MatrizRotacao::MatrizRotacao(int eixo, double angulo){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            switch (eixo) {
            case 0:
                if((i == 1 || i == 2) && (j == 1 || j == 2)){
                    if(i == j) val[i][j] = cos(angulo);
                    else if(i == 1 && j == 2) val[i][j] = sin(angulo);
                    else val[i][j] = -sin(angulo);
                }else if(i == j) val[i][j] = 1;
                else val[i][j] = 0; break;
            case 1:
                if((i == 0 || i == 2) && (j == 0 ||j == 2)){
                    if(i == j) val[i][j] = cos(angulo);
                    else if(i == 0 && j == 2) val[i][j] = sin(angulo);
                    else val[i][j] = -sin(angulo);
                }else if(i == j) val[i][j] = 1;
                else val[i][j] = 0; break;
            case 2:
                if((i == 0 || i == 1) && (j == 0 || j == 1)){
                    if(i==j) val[i][j] = cos(angulo);
                    else if(i == 0 && j == 1) val[i][j] = sin(angulo);
                    else val[i][j] = -sin(angulo);
                }else if(i == j) val[i][j] = 1;
                else val[i][j] = 0;
            }
        }
    }
}

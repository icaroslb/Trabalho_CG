#include "../Headers/matrizreflexao.h"

MatrizReflexao::MatrizReflexao(int eixo1, int eixo2){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                if((eixo1 == 0 && eixo2 == 1) || (eixo1 == 1 && eixo2 == 0)){       //Plano XY
                    if(i == 2) val[i][j] = -1;
                    else val[i][j] = 1;
                }else if((eixo1 == 0 && eixo2 == 2) || (eixo1 == 2 && eixo2 == 0)){ //Plano XZ
                    if(i == 1) val[i][j] = -1;
                    else val[i][j] = 1;
                }else if((eixo1 == 1 && eixo2 == 2) || (eixo1 == 2 && eixo2 == 1)){ //Plano YZ
                    if(i == 0) val[i][j] = -1;
                    else val[i][j] = 1;
                }
            }else val[i][j] = 0;
        }
    }
}

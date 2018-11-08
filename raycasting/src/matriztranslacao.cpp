#include "../Headers/matriztranslacao.h"

MatrizTranslacao::MatrizTranslacao(double tx, double ty, double tz){
    Matriz();

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

#include "../Headers/matrizescala.h"

MatrizEscala::MatrizEscala(double Sx, double Sy, double Sz){
    Matriz();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i==j){
                switch (i) {
                case 0: val[0][0] = Sx; break;
                case 1: val[1][1] = Sy; break;
                case 2: val[2][2] = Sz; break;
                case 3: val[3][3] = 1; break;
                }
            }else val[i][j] = 0;
        }
    }
}

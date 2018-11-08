#include "../headers/matrizcisalhamento.h"

MatrizCisalhamento::MatrizCisalhamento(int eixo1, int eixo2, int eixo3, double angulo){
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

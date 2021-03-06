#include "../headers/parser.h"

bool parser (const char * path, std::vector < Objeto> &objetos){

    int size = objetos.size();
    std::vector<Vertice> temp_vertices;


    FILE * file = fopen(path, "r");
    if( file == NULL ){
        printf("Impossivel abrir arquivo!\n");
        return false;
    }
    int numeroVertices = 0, indiceVetor = 0;
    while(true){
        char linha_lida[128], nome_do_objeto[30];
        int res = fscanf(file, "%s", linha_lida);
        if(res == EOF)
            break;
        if(strcmp(linha_lida, "o") == 0){
            fscanf(file, "%s", nome_do_objeto);
            Objeto obj(nome_do_objeto);
            Forma *f = new Face();
            obj.addForma(f);
            objetos.push_back(obj);
            size ++;
            indiceVetor = numeroVertices;
        }else if(strcmp(linha_lida, "v") == 0){
            float x, y, z;
            fscanf(file, "%f %f %f\n", &x, &y, &z );
            Vertice v(x,y,z);
            ((Face*)(*objetos[size -1].getFormas())[0])->addVertice(v);
            numeroVertices ++;
        }else if(strcmp(linha_lida, "f") == 0){
            int v1, v2, v3, aux;
            int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &v1, &aux, &v2, &aux, &v3, &aux);
            if(matches != 6){
                return false;
            }

            ((Face*)(*objetos[size -1].getFormas())[0])->addFace(v1-indiceVetor -1,v2-indiceVetor-1,v3-indiceVetor-1);
        }else if(strcmp(linha_lida, "o.E") == 0){
            fscanf(file, "%s", nome_do_objeto);
            Objeto obj(nome_do_objeto);
            float x, y, z, raio;
            while (int matches = fscanf(file, "%s %f %f %f %f", nome_do_objeto, &x, &y, &z, &raio) == 5) {
                Vertice v(x,y,z);
                Forma *f = new Esfera(v, raio);
                obj.addForma(f);

            }
            objetos.push_back(obj);
            size ++;
        }
    }
    return true;
}

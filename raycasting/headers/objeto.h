#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <vector>
#include "headers/forma.h"

class Objeto {
private:
    std :: string nome;
    std :: vector<Forma*> formas;
    std :: vector<Vertice> vertices;
public:
    Objeto(std :: string nome);
    std :: string getNome();
    void addForma(Forma *forma);
    std :: vector<Forma*>* getFormas();
    std :: vector<Vertice>* getVertices();
    void addVertice(Vertice vertice);

};

#endif /* end of include guard: OBJETO_H */

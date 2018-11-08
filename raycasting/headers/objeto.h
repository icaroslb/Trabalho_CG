#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <vector>
#include "headers/forma.h"

class Objeto {
    std :: string nome;
    std :: vector<Forma*> formas;


public:

    Objeto(std :: string nome);
    std :: string getNome();
    void addForma(Forma *forma);
    std :: vector<Forma*>* getFormas();

};

#endif /* end of include guard: OBJETO_H */

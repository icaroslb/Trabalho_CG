#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <vector>
#include "forma.h"

class Objeto {
private:
    std :: string nome;
    std :: vector<Forma*> formas;
public:
    Objeto(std :: string nome);
    std :: string getNome();
    void addForma(Forma *forma);
    std :: vector<Forma*>* getFormas();  
};

#endif /* end of include guard: OBJETO_H */

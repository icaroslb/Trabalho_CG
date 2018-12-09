#ifndef VETOR_H
#define VETOR_H

#include <math.h>

#define X 0
#define Y 1
#define Z 2
#define W 3

class Vetor
{
private:
    float val[4];

public:
    Vetor();
    Vetor(float x, float y, float z);
    ~Vetor();

    float operator [] (int pos);
    float operator * (Vetor produtoEsc);
    Vetor* operator * (float escalar);
    Vetor* operator / (float escalar);
    Vetor* operator ->* (Vetor produtoVet);
    Vetor* operator - (Vetor sub);
    Vetor* unitario();
};

#endif // VETOR_H

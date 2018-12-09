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
    double val[4];

public:
    Vetor();
    Vetor(double x, double y, double z);
    ~Vetor();

    double operator [] (int pos);
    void set(int pos, double value);
    double operator * (Vetor produtoEsc);
    Vetor* operator * (double escalar);
    Vetor* operator / (double escalar);
    Vetor* operator ->* (Vetor produtoVet);
    Vetor* operator - (Vetor sub);
    Vetor* operator + (Vetor sum);
    void operator += (Vetor sum);

    Vetor* arroba (Vetor sum);
    double norma();
    Vetor* unitario();
};

#endif // VETOR_H

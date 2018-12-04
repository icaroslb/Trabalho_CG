#ifndef VETOR_H
#define VETOR_H

#define X 0
#define Y 1
#define Z 2
#define W 3

class Vetor
{
    double val[4];

public:
    Vetor();
    Vetor(double x, double y, double z);
    //~Vetor();

    double operator[](int);
    double* operator*(Vetor);
    Vetor* operator*(double escalar);
    Vetor* operator->*(Vetor);
    Vetor* operator-(Vetor);
    Vetor* unitario();
};

#endif // VETOR_H

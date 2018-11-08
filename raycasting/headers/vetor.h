#ifndef VETOR_H
#define VETOR_H

#include <cmath>

class Vetor{
    double *val;
public:
    Vetor(double, double, double);
    //~Vetor();
	
	double operator[](int);
    double operator*(Vetor);
    Vetor operator*(double);
    Vetor operator->*(Vetor);
    Vetor operator-(Vetor);
    Vetor unitario();
};

#endif // VETOR_H

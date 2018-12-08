#ifndef ESFERA_H
#define ESFERA_H

#include <cmath>
#include <cstdio>

#include "forma.h"
#include "objetos.h"

class Esfera : public Forma{
public:
	Esfera();
	Esfera(double raio, Vetor *centro);

	//void setW(double observador[3]);
	//double getT();
	Vetor* getN(Vetor Pint);
	double getRaio();
	
	PixInt intersecao(Vetor D, Vetor o);
	
	//void mudaCoodCamera(Camera *camera);
	//void mudaCoodMundo(Camera *camera);


private:
	double raio;
	Vetor *centro;
	//Material *material;

};

#endif //ESFERA_H
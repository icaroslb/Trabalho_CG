#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <cmath>
#include <cstdio>

#include "forma.h"
#include "material.h"

class Triangulo : public Forma{
public:
	Triangulo();
	Triangulo(Vetor *p1, Vetor *p2, Vetor *p3, Material *material);

	//void setW(double observador[3]);
	//double getT();
	Vetor* getN(Vetor Pint);
	
	PixInt intersecao(Vetor D, Vetor o);
	bool visivel(Vetor v);
	Vetor* getCorAmbiente(Vetor Iamb);
	Vetor* getCorLuz(Vetor Pint, Luz luz);
	//void mudaCoodCamera(Camera *camera);
	//void mudaCoodMundo(Camera *camera);


private:
	Vetor *p1, *p2, *p3;
	//Material *material;

};

#endif //TRIANGULO_H
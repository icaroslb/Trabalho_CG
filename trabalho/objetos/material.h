#ifndef MATERIAL_H
#define MATERIAL_H

#include "../matematica/vetor.h"

class Material
{
public:
	Material();
	Material(Vetor *Kamb, Vetor *Kdif, Vetor *Kesp, int m);

	Vetor *getKamb();
	Vetor *getKdif();
	Vetor *getKesp();
	int getM();

private:
	Vetor *Kamb, *Kdif, *Kesp;
	double m;
};

#endif

#ifndef OBEJTOS_H
#define OBEJTOS_H

#include "forma.h"
#include <vector>
#include <limits>

using namespace std;

class Objeto{
public:
	Objeto();
	Objeto(Forma *forma);

	void addForma(Forma *forma);
	void setVisiveis(Vetor v);

	PixIntFor intersecao(Vetor D, Vetor o);


private:
	vector<Forma*> formas;
	vector<Forma*> visiveis;

	
};


#endif // OBEJTOS_H

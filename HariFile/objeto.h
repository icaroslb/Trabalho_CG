#ifndef OBEJTOS_H
#define OBEJTOS_H

#include "forma.h"
#include <vector>

using namespace std;

class Objeto{
public:
	Objeto();
	Objeto(Forma *forma);

	void addForma(Forma *forma);
	void setVisiveis(Vetor v);


private:
	vector<Forma*> formas;
	vector<Forma*> visiveis;

	
};


#endif // OBEJTOS_H

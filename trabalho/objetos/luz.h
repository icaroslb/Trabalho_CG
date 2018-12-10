#ifndef LUZ_H
#define LUZ_H

//#include "Camera.h"
#include "../matematica/vetor.h"

class Luz{
public:
	Luz(Vetor *coordenada, Vetor *If);

	Vetor *getCoordenada();
	Vetor *getIf();

//	void mudaCoodCamera(Camera *camera);
//	void mudaCoodMundo(Camera *camera);

private:
	Vetor *coordenada, *If;
};


#endif //LUZ_H

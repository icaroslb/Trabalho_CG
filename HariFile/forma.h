#ifndef FORMA_H
#define FORMA_H 

#include "vetor.h"
#include "objetos.h"

class Forma{
public:
	Forma();
	//Forma(Material *material);
	//Material getMaterial();
	//void setMaterial(Material *material);
	virtual PixInt intersecao(Vetor D, Vetor o);
	//virtual bool intersecaoSombra(double D[3], double o[3]);
	//virtual double getT();
	virtual Vetor* getN(Vetor Pint);
	//virtual void mudaCoodCamera(Camera *camera);
	//virtual void mudaCoodMundo(Camera *camera);

private:
	//Material *material;

};

#endif //FORMA_H
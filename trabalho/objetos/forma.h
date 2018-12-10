#ifndef FORMA_H
#define FORMA_H 

#include "../matematica/vetor.h"
#include "objetos.h"
#include "material.h"
#include "luz.h"

/*typedef struct PIXINT{
	bool intercedeu;
	double t;
} PixInt;*/


class Forma{
public:
	Forma();
	Forma(Material *material);
	//Material getMaterial();
	//void setMaterial(Material *material);
    virtual PixInt* intersecao(Vetor D, Vetor o);
	//virtual bool intersecaoSombra(double D[3], double o[3]);
	//virtual double getT();
	virtual Vetor* getN(Vetor Pint);
	virtual bool visivel(Vetor v);
	virtual Vetor* getCorAmbiente(Vetor Iamb);
	virtual Vetor* getCorLuz(Vetor Pint, Luz luz);
	Material* getMaterial();
	//virtual void mudaCoodCamera(Camera *camera);
	//virtual void mudaCoodMundo(Camera *camera);

private:
	Material *material;

};


typedef struct PIXINTFOR{
	bool intercedeu;
	double t;
	Forma *forma;
} PixIntFor;

#endif //FORMA_H

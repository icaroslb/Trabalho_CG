#include "forma.h"

Forma::Forma(Material *material) {
	this->material = material;
}

PixInt* Forma::intersecao(Vetor D, Vetor o){
    PixInt *p = new PixInt;
	return p;
}

Vetor* Forma::getN(Vetor Pint){
	Vetor *n;
	return n;
}

bool Forma::visivel(Vetor v){
	return true;
}

Vetor* Forma::getCorAmbiente(Vetor Iamb){
	Vetor *cor = new Vetor(1, 1, 1);
	return cor;
}

Vetor* Forma::getCorLuz(Vetor Pint, Luz luz){
	Vetor *cor = new Vetor(1, 1, 1);
	return cor;
}

Material* Forma::getMaterial(){
	return material;
}

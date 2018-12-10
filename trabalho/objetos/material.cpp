
#include "material.h"

Material::Material(Vetor *Kamb, Vetor *Kdif, Vetor *Kesp, int m){
	this->Kamb = Kamb;
	this->Kdif = Kdif;
	this->Kesp = Kesp;
	this->m = m;
}

Vetor* Material::getKamb(){
	return this->Kamb;
}
Vetor* Material::getKdif(){
	return this->Kdif;
}
Vetor* Material::getKesp(){
	return this->Kesp;
}
int Material::getM(){
	return this->m;
}
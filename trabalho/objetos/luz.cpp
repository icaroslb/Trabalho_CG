#include "luz.h"

Luz::Luz(Vetor *coordenada, Vetor *If){
	this->coordenada = coordenada;
	this->If = If;
}

Vetor* Luz::getCoordenada(){
	return this->coordenada;
}

Vetor* Luz::getIf(){
	return this->If;
}
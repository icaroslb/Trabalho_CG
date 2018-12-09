#include "triangulo.h"

Triangulo::Triangulo(Vetor *p1, Vetor *p2, Vetor *p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Vetor* Triangulo::getN(Vetor Pint){
	Vetor *v2, *v3;
	v2 = *p2 - *p1;
	v3 = *p3 - *p1;

	return *v2 ->* *v3;
}

PixInt Triangulo::intersecao(Vetor D, Vetor o){
	Vetor *n, *w, *Pint;
	PixInt resultado;

	n = getN(*Pint);
	w = *p1 - o;

	if ((D * *n) != 0) resultado.t = (*w * *n)/(D * *n);
	else {
		resultado.intercedeu = false;
		return resultado;
	}
	Pint = D * resultado.t;
	Pint = *Pint + o;

	Vetor *v1, *v2, *aux;
	double A1, A2, A3, A;

	v1 = *p2 - *p1;
	v2 = *p3 - *p2;

	aux = *v1 ->* *v2;
	A = aux->norma()/2;

	Vetor *w1, *w2, *w3, *aux1, *aux2, *aux3;
	w1 = *p1 - *Pint;
	w2 = *p2 - *Pint;
	w3 = *p3 - *Pint;

	aux1 = *w1 ->* *w2;
	aux2 = *w3 ->* *w1;
	aux3 = *w2 ->* *w3;

	A1 = aux1->norma()/2;
	A2 = aux2->norma()/2;
	A3 = aux3->norma()/2;

	resultado.intercedeu = abs(A - (A1 + A2 + A3)) < 0.000000005 ? true : false;
	return resultado;
}

bool Triangulo::visivel(Vetor v){
	if (getN(v) * v < 0) return false;
	return true;
}


#include "esfera.h"

Esfera::Esfera(double raio, Vetor *centro){
	this->raio = raio;
	this->centro = centro;
}

Vetor * Esfera::getN(Vetor Pint){
	return Pint - (*centro);
}

double Esfera::getRaio(){
	return raio;
}
	
	
PixInt Esfera::intersecao(Vetor D, Vetor o) {
	double a, b, c, delta, t1, t2;
	Vetor *w = o - (*centro);
	PixInt resultado;

	a = D * D;
	b = 2 * (D * *w);
	c = (*w * *w) - raio * raio;

	delta = (b * b) - (4 * a * c);

	if (delta < 0) resultado.intercedeu = false;

	else if (delta == 0) {
		resultado.intercedeu = true;
		resultado.t = - b / (2 * a);
	}

	else {
		t1 = (-b+sqrt(delta))/(2*a);
		t2 = (-b-sqrt(delta))/(2*a);

		resultado.intercedeu = true;
		resultado.t = (t1 < t2) ? t1 : t2;
	}

	return resultado;
}
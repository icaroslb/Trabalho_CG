
#include "esfera.h"

Esfera::Esfera(double raio, Vetor *centro, Material *material):Forma(material){
	this->raio = raio;
	this->centro = centro;
}

Vetor * Esfera::getN(Vetor Pint){
	return (Pint - (*centro))->unitario();
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

Vetor* Esfera::getCorAmbiente(Vetor Iamb){
	return Iamb.arroba(*this->getMaterial()->getKamb());
}

Vetor* Esfera::getCorLuz(Vetor Pint, Luz luz){
	Vetor *n, *v, *l, *r, *resposta;
	Vetor observador(0, 0, 0);
	double prodLN, prodVR;

	n = getN(Pint);
	v = observador - Pint;
	l = *luz.getCoordenada() - Pint;

	v = v->unitario();
	l = l->unitario();

	prodLN = *l * *n;
	r = *(*n * ((*l * *n) * 2)) - *l;
	prodVR = pow((*v * *r), getMaterial()->getM());

	if (prodLN < 0) {
		prodLN = 0;
		prodVR = 0;
	}

	return *(*(getMaterial()->getKdif()->arroba(*(luz.getIf()))) * prodLN) + *(*(getMaterial()->getKesp()->arroba(*(luz.getIf()))) * prodVR);
}
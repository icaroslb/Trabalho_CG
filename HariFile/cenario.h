
#include "objeto.h"
#include "vetor.h"
#include "luz.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Cenario {
public:
	Cenario();
	void addObjeto(Objeto objeto);
	void addObjeto(Luz luz);
	void setIamb(Vetor Iamb);
	Vetor *raycasting(Vetor Pix);

private:
	vector<Objeto> objetos;
	vector<Luz> luzes;
	Vetor Iamb;

};
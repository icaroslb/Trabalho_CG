#include "cenario.h"

void Cenario::addObjeto(Objeto objeto){
	objetos.push_back(objeto);
}
void Cenario::addObjeto(Luz luz){
	luzes.push_back(luz);
}
Vetor *Cenario::raycasting(Vetor Pix){
	Vetor origem(0, 0, 0);
	PixIntFor intersecao;
	intersecao.t = std::numeric_limits<double>::max();
	Vetor *cor = new Vetor(0, 0, 0);
	
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i].setVisiveis(Pix);
		PixIntFor aux = objetos[i].intersecao(Pix, origem);

		if (aux.intercedeu and aux.t < intersecao.t) {
			intersecao.t = aux.t;
			intersecao.forma = aux.forma;
			intersecao.intercedeu = true;
		}
	}

	if (intersecao.intercedeu) {
		Vetor *Pint = origem + *(Pix * intersecao.t);
		PixIntFor aux;
		for (int i = 0; i < luzes.size(); i++) {
			cor =  *cor + *intersecao.forma->getCorAmbiente(Iamb);
			Vetor *D = (*luzes[i].getCoordenada() - *Pint)->unitario();
			
			if (intersecao.forma->getN(*Pint) >= 0) {
				aux.intercedeu = false;
				for (int i = 0; i < objetos.size() and not aux.intercedeu; i++) {
					objetos[i].setVisiveis(*D);
					aux = objetos[i].intersecao(*D, *Pint);
				}
				
				if (not aux.intercedeu) {
					cor = *cor + *intersecao.forma->getCorLuz(*Pint, luzes[i]);
				}
			}
		}
	}
	return cor;
}
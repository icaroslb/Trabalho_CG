#include "objeto.h"

Objeto::Objeto(Forma *forma){
	formas.push_back(forma);
}

void Objeto::addForma(Forma *forma){
	formas.push_back(forma);
}
void Objeto::setVisiveis(Vetor v){
	visiveis.clear();
	for (int i = 0; i < formas.size(); i++) {
		if (formas[i]->visivel(v)) {
			visiveis.push_back(formas[i]);
		}
	}
}

PixIntFor Objeto::intersecao(Vetor D, Vetor o){
	PixIntFor resposta;
	resposta.intercedeu = false;
	resposta.t = std::numeric_limits<double>::max();
	
	for (int i = 0; i < visiveis.size(); i++) {
		PixInt aux = visiveis[i]->intersecao(D, o);	
		if (aux.intercedeu and aux.t < resposta.t) {
			resposta.intercedeu = true;
			resposta.t = aux.t;
			resposta.forma = visiveis[i];
		}
	}
	return resposta;
}

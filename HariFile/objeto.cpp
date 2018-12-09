#include "objeto.h"

Objeto::Objeto(Forma *forma){
	formas.push_back(forma);
}

void Objeto::addForma(Forma *forma){
	formas.push_back(forma);
}
void Objeto::setVisiveis(Vetor v){
	for (int i = 0; i < formas.size(); i++) {
		if (formas[i]->visivel(v)) {
			visiveis.push_back(formas[i]);
		}
	}
}

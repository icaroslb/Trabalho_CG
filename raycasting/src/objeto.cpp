#include "../headers/objeto.h"

/*
Construtor da Classe
@Parâmetros
    name: nome do objeto.
*/
Objeto :: Objeto(std :: string nome){
    this->nome = nome;
}

/*
Metodo getName
@retorno:
    nome do objeto.
*/
std :: string Objeto :: getNome(){
    return nome;
}

/*
Metodo getFormas
@retono:
    o vector de formas.
*/
std :: vector<Forma*>* Objeto :: getFormas(){
    return &formas;
}

/*
Adiciona um vertice ao vetor de formas
@Parêmetros: Objeto do tipo Vertex
*/
void Objeto :: addForma(Forma *forma){
    formas.push_back(forma);
}


/*
Metodo getVertices
@retono:
    o vector de vertices.
*/
std :: vector<Vertice>* Objeto :: getVertices(){
    return &vertices;
}

/*
Adiciona um vertice ao vetor de formas
@Parêmetros: Objeto do tipo Vertex
*/
void Objeto :: addVertice(Vertice vertice){
    vertices.push_back(vertice);
}

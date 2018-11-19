#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "objeto.h"
#include "vertice.h"
#include "face.h"
#include "forma.h"
#include "esfera.h"
#include <string.h>

bool parser(const char * caminho, std::vector <Objeto> &objetos);

#endif // PARSER_H

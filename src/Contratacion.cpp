#include "Contratacion.h"

long Contratacion::AI = 1;

long Contratacion::getCodigo()
{
    return codigo;
}

Contratacion::Contratacion(){
    this->codigo = AI;
    AI++;
}
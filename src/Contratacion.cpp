#include "Contratacion.h"

long Contratacion::AI = 1;

Contratacion::Contratacion(){
    this->codigo = AI;
    AI++;
}
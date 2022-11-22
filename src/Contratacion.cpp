#include "Contratacion.h"

long Contratacion::AI = 1;

long Contratacion::getCodigo()
{
    return codigo;
}

void Contratacion::getInfo()
{
    cout << "Codigo: " << getCodigo() << endl;
}

Contratacion::Contratacion(){
    this->codigo = AI;
    AI++;
}
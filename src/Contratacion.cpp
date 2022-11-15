#include "Contratacion.h"

long Contratacion::IA = 1;

Contratacion::Contratacion(){
    this->codigo = IA;
    IA++;
}
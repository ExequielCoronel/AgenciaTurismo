#ifndef PAQUETE_CPP_
#define PAQUETE_CPP_

#include "Paquete.h"

long Paquete::AI = 1;

Paquete::Paquete(string Destino, Fecha FechaSalida, int cantidadDias)
{
	this->cantidadDias = cantidadDias;
	codPaquete = AI;
	destino = Destino;
	fechaSalida = FechaSalida;
	AI++;
}

Paquete::~Paquete(){}




#endif
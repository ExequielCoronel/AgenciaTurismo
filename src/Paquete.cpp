#ifndef PAQUETE_CPP_
#define PAQUETE_CPP_

#include "Paquete.h"

long Paquete::IA=1;

Paquete::Paquete(string Destino, Fecha FechaSalida, int cantidadDias)
{
	this->cantidadDias = cantidadDias;
	codPaquete = IA;
	destino = Destino;
	fechaSalida = FechaSalida;
	IA++;
}

Paquete::~Paquete(){}




#endif /* PAQUETE_CPP_ */

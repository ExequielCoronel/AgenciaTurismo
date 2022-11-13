#ifndef PAQUETE_CPP_
#define PAQUETE_CPP_

#include "Paquete.h"

long Paquete::IA=0;

Paquete::Paquete(string Destino, Fecha FechaSalida)
{
	codPaquete = IA;
	destino = Destino;
	fechaSalida = FechaSalida;
	IA++;
}

Paquete::~Paquete(){}




#endif /* PAQUETE_CPP_ */

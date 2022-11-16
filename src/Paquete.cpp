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

long Paquete::getCodigo()
{
	return codPaquete;
}

Fecha Paquete::getFechaSalida(){
	return fechaSalida;
}

Paquete::~Paquete()
{
}
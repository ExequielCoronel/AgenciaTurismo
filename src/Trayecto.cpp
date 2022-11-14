#include "Trayecto.h"

long Trayecto::AI = 1;

Trayecto::Trayecto(string ciudadOrigen, string ciudadDestino, int cantidadDias, float costo)
{
	this->ciudadOrigen = ciudadOrigen;
	this->ciudadDestino = ciudadDestino;
	cantDias = cantidadDias;
	this->costo = costo;
	codTrayecto = AI;
	AI++;
}

long Trayecto::getCodTrayecto(){return codTrayecto;}

string Trayecto::getCiudadDestino(){return ciudadDestino;}

string Trayecto::getCiudadOrigen(){return ciudadOrigen;}

int Trayecto::getcantDias(){return cantDias;}

float Trayecto::getCosto(){return costo;}

Trayecto::~Trayecto(){}

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

long Trayecto::getCodTrayecto()
{
	return codTrayecto;
}

string Trayecto::getCiudadDestino()
{
	return ciudadDestino;
}

string Trayecto::getCiudadOrigen()
{
	return ciudadOrigen;
}

int Trayecto::getcantDias()
{
	return cantDias;
}

float Trayecto::getCosto()
{
	return costo;
}

void Trayecto::getInfo(){
	cout << "Codigo: " << getCodTrayecto() << endl;
	cout << "Ciudad de origen: " << getCiudadOrigen() << endl;
	cout << "Ciudad de destino: " << getCiudadDestino() << endl;
	cout << "Cantidad de dias: " << getcantDias() << endl;
	cout << "Costo: " << getCosto() << endl;
}

Trayecto::~Trayecto() {}

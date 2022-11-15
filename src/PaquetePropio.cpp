#include "PaquetePropio.h"

// Falta realizar el metodo CalcularCosto();

PaquetePropio::PaquetePropio(string destino, Fecha fechaSalida, int cantidadDias, int cantidadReservas, int cupoMaximoPasajeros, float descuento) : Paquete(destino, fechaSalida, cantidadDias)
{
	this->cantidadReservas = cantidadReservas;
	cupoMaxPasajeros = cupoMaximoPasajeros;
	this->descuento = descuento;
}

float PaquetePropio::getDescuento(){return descuento;}

float PaquetePropio::calcularCosto()
{
	float costoTotal = 0;
	for(Trayecto* trayecto:ListaTrayectos)
	{
		costoTotal += trayecto->getCosto();
	}
	costoTotal = costoTotal*(1-descuento);
	return costoTotal;
}

int PaquetePropio::getCantidadReservas(){return cantidadReservas;}

int PaquetePropio::getCupoMaxPasajeros(){return cupoMaxPasajeros;}

void PaquetePropio::AgregarTrayecto(Trayecto *trayecto) {ListaTrayectos.push_back(trayecto);}

void PaquetePropio::EliminarTrayecto(long codTrayecto)
{
	for(int i=0;i<ListaTrayectos.size();i++)						//Se podria utilizar una clase iteradora
	{
		if(ListaTrayectos[i]->getCodTrayecto() == codTrayecto)
		{
			ListaTrayectos.erase(ListaTrayectos.begin() + i);
		}
	}
}

PaquetePropio::~PaquetePropio(){}


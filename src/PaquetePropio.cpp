#include "PaquetePropio.h"

PaquetePropio::PaquetePropio(string destino, Fecha fechaSalida, int cantidadDias, int cupoMaximoPasajeros, float descuento) : Paquete(destino, fechaSalida, cantidadDias) // @suppress("Class members should be properly initialized")
{
	cupoMaxPasajeros = cupoMaximoPasajeros;
	this->descuento = descuento;
	cantidadPersonas = 0;
}

float PaquetePropio::getDescuento()
{
	return descuento;
}

float PaquetePropio::calcularCosto()
{
	float costoTotal = 0;

	for (Trayecto *trayecto : ListaTrayectos)
	{
		costoTotal += trayecto->getCosto();
	}

	costoTotal = costoTotal * (1 - (descuento / 100));

	return costoTotal;
}

bool PaquetePropio::ingresarPersonas(int cantidad)
{
	if ((cantidadPersonas + cantidad) > cupoMaxPasajeros)
	{
		return false;
	}
	else
	{
		cantidadPersonas += cantidad;
		return true;
	}
}

int PaquetePropio::getCupoMaxPasajeros()
{
	return cupoMaxPasajeros;
}

void PaquetePropio::eliminarPersonas(int cantidad)
{
	this->cantidadPersonas -= cantidad;
	if(cantidadPersonas < 0) cantidadPersonas = 0;
}

void PaquetePropio::ingresarTrayecto(Trayecto *trayecto)
{
	ListaTrayectos.push_back(trayecto);
}

void PaquetePropio::ingresarContratacion(Contratacion *contratacion)
{
}

void PaquetePropio::eliminarTrayecto(long codigo)
{
	for (int i = 0; i < ListaTrayectos.size(); i++)
	{
		if (ListaTrayectos[i]->getCodTrayecto() == codigo)
		{
			ListaTrayectos.erase(ListaTrayectos.begin() + i);
			break;
		}
	}
}

void PaquetePropio::eliminarContratacion(long codigo)
{

}

void PaquetePropio::getInfo()
{
	Paquete::getInfo();
	cout << "Cupo maximo de pasajeros: " << getCupoMaxPasajeros() << endl;
	cout << "Cantidad restante de pasajeros: " << cupoMaxPasajeros - cantidadPersonas << endl;
	cout << "Costo: " << calcularCosto() << endl;
	cout << "Descuento: " << descuento << endl;
	cout << "Trayectos: " << endl;
	for (Trayecto *trayecto : ListaTrayectos)
	{
		cout << trayecto->getCiudadOrigen() << " - " << trayecto->getCiudadDestino() << endl;
	}
	cout << endl;
}

int PaquetePropio::cantidadContrataciones()
{
	return 0;
}

PaquetePropio::~PaquetePropio()
{
}

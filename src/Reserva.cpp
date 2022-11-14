#include "Reserva.h"

long Reserva::AI=1;

Reserva::Reserva(Fecha fechaReserva,Fecha fechaCaducidad,float senia, Agente Agente, Paquete* Paquete)
{
	this->fechaReserva = fechaReserva;
	this->fechaCaducidad = fechaCaducidad;
	this->senia = senia;
	this->Agent = &Agente;
	this->Packet = Paquete;
	CodigoReserva = AI;
	AI++;
}

Agente Reserva::getAgente(){return *Agent;}

Paquete* Reserva::getPaquete(){return Packet;}

Fecha Reserva::getFechaCaducidad(){return fechaCaducidad;}

Fecha Reserva::getFechaReserva(){return fechaReserva;}

long Reserva::getCodigoReserva(){return CodigoReserva;}

float Reserva::getSenia(){return senia;}

bool Reserva::AgregarPasajero(Pasajero *nuevoPasajero)
{
	if(ListadoPasajeros.push_back(nuevoPasajero)) return true;
	return false;
}

bool Reserva::EliminarPasajero(long codPasajero)
{
	for(int i=0;i<ListadoPasajeros.size();i++)									//Se podria utilizar una clase iteradora
	{
		if(ListadoPasajeros[i]->getCod() == codPasajero)
		{
			if(ListadoPasajeros.erase(ListadoPasajeros.begin() + i)) return true;
		}
	}
	return false;
}

Reserva::~Reserva(){}

#include "Reserva.h"

long Reserva::AI=1;

Reserva::Reserva(Fecha fechaReserva,Fecha fechaCaducidad, Agente Agente, Paquete* Paquete)
{
	this->fechaReserva = fechaReserva;
	this->fechaCaducidad = fechaCaducidad;
	this->senia = 0;
	this->Agent = &Agente;
	this->Packet = Paquete;
	this->reservaConfirmada = false;
	CodigoReserva = AI;
	AI++;
}

Agente Reserva::getAgente(){return *Agent;}

Paquete* Reserva::getPaquete(){return Packet;}

Fecha Reserva::getFechaCaducidad(){return fechaCaducidad;}

Fecha Reserva::getFechaReserva(){return fechaReserva;}

long Reserva::getCodigoReserva(){return CodigoReserva;}

float Reserva::getSenia(){return senia;}

float Reserva::SeniaMinima(){return Packet->calcularCosto()*PORCENTAJESENIA;}

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

bool Reserva::pagarSenia(long senia)
{
	if(SeniaMinima()<senia && this->senia == 0)
	{
		this->senia = senia;
		return true;
	}
	return false;
}

void Reserva::confirmarReserva()
{

	if(!this->fechaCaducidad.esFechaPasada() && !this->reservaConfirmada){
		this->reservaConfirmada = true;
	}
}

Reserva::~Reserva(){}

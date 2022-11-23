#include "Reserva.h"

long Reserva::AI = 1;

Reserva::Reserva(Fecha fechaReserva, Fecha fechaCaducidad, int cantPersonas, Agente *Agente, Paquete *Paquete)
{
	if(Paquete->ingresarPersonas(cantPersonas))
	{
		this->fechaReserva = fechaReserva;
		this->fechaCaducidad = fechaCaducidad;
		this->senia = 0;
		this->Agent = Agente;
		this->Packet = Paquete;
		this->cantPersonas = cantPersonas;
		this->reservaConfirmada = false;
		CodigoReserva = AI;
		AI++;
	}
}

Agente Reserva::getAgente()
{
	return *Agent;
}

Paquete *Reserva::getPaquete()
{
	return Packet;
}

Fecha Reserva::getFechaCaducidad()
{
	return fechaCaducidad;
}

Fecha Reserva::getFechaReserva()
{
	return fechaReserva;
}

long Reserva::getCodigoReserva()
{
	return CodigoReserva;
}

float Reserva::getSenia()
{
	return senia;
}

int Reserva::getCantidadPersonas()
{
	return cantPersonas;
}

float Reserva::SeniaMinima()
{
	return getSaldoAPagar() * PORCENTAJESENIA;
}

void Reserva::AgregarPasajero(Cliente *nuevoPasajero)
{
	if(Packet->ingresarPersonas(1))
	{
		ListadoPasajeros.push_back(nuevoPasajero);
	}
}

void Reserva::EliminarPasajero(long codPasajero)
{
	for (int i = 0; i < ListadoPasajeros.size(); i++) // Se podria utilizar una clase iteradora
	{
		if (ListadoPasajeros[i]->getCodigo() == codPasajero)
		{
			ListadoPasajeros.erase(ListadoPasajeros.begin() + i);
			Packet->eliminarPersonas(1);
			break;
		}
	}
}

float Reserva::getSaldoAPagar()
{
	return Packet->calcularCosto() * cantPersonas;
}

bool Reserva::pagarSenia(long senia)
{
	if (SeniaMinima() < senia && this->senia == 0)
	{
		this->senia = senia;
		return true;
	}

	return false;
}

void Reserva::confirmarReserva()
{
	if (!this->fechaCaducidad.esFechaPasada() && !this->reservaConfirmada)
	{
		this->reservaConfirmada = true;
	}
}

void Reserva::getInfo()
{
	cout << "Codigo: " << getCodigoReserva() << endl;
	cout << "Fecha de reserva: " << getFechaReserva().toString() << endl;
	cout << "Fecha de caducidad: " << getFechaCaducidad().toString() << endl;
	cout << "Agente: " << Agent->getNombre() << endl;
	cout << "Cantidad de pasajeros: " << cantPersonas << endl;
	cout << "Senia: " << getSenia() << endl;
	cout << "Reserva confirmada: ";
	
	if (reservaConfirmada)
	{
		cout << "Si" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

Reserva::~Reserva()
{
}

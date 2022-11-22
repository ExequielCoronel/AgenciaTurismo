#include "Pasajero.h"

long Pasajero::AI = 1;

Pasajero::Pasajero(string nombre, string apellido, long DNI, long numeroPasaporte, Fecha fechaNac)
{
	this->nombre = nombre;
	this->apellido = apellido;
	dni = DNI;
	numPasaporte = numeroPasaporte;
	FechaNacimiento = fechaNac;
	codPasajero = AI;
	AI++;
}

string Pasajero::getNombre(){return nombre;}

string Pasajero::getApellido(){return apellido;}

long Pasajero::getDni(){return dni;}

long Pasajero::getNumPasaporte(){return numPasaporte;}

Fecha Pasajero::getFechaNacimiento(){return FechaNacimiento;}

Pasajero::~Pasajero(){}

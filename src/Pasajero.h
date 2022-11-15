#ifndef PASAJERO_H_
#define PASAJERO_H_

#include "iostream"
#include "Fecha.h"
using namespace std;

class Pasajero
{
	static long AI;
	long codPasajero;
	string nombre;
	string apellido;
	long dni;
	long numPasaporte;
	Fecha FechaNacimiento;

	public:
		Pasajero(string nombre,string apellido,long dni,long numPasaporte,Fecha fechaNacimiento);
		long getCod();
		string getNombre();
		string getApellido();
		long getDni();
		long getNumPasaporte();
		Fecha getFechaNacimiento();
		~Pasajero();
};



#endif /* PASAJERO_H_ */

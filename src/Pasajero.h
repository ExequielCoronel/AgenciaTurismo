/*
 * Pasajero.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef PASAJERO_H_
#define PASAJERO_H_

#include "iostream"
#include "Fecha.h"
using namespace std;

class Pasajero
{
	static long AI = 0;
	long codPasajero;
	string nombre;
	string apellido;
	long dni;
	long numPasaporte;
	Fecha FechaNacimiento;

	public:
		Pasajero(int,string,string,long,long,Fecha);
		long getCod();
		string getNombre();
		string getApellido();
		long getDni();
		long getNumPasaporte();
		Fecha getFechaNacimiento();
		~Pasajero();
};



#endif /* PASAJERO_H_ */

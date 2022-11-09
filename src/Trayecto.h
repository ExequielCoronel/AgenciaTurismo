/*
 * Trayecto.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef TRAYECTO_H_
#define TRAYECTO_H_

#include <iostream>
using namespace std;

class Trayecto
{
	static long IA;
	long codTrayecto;
	string ciudadOrigen;
	string ciudadDestino;
	int cantDias;
	float costo;

	public:
		Trayecto(string,string,int,float);
		string getCiudadOrigen();
		string getCiudadDestino();
		int getcantDias();
		float getCosto();
		~Trayecto();
};



#endif /* TRAYECTO_H_ */

/*
 * Paquete.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef PAQUETE_H_
#define PAQUETE_H_

#include "iostream"
using namespace std;
#include "Fecha.h"

class Paquete
{
	static long IA;
	long codPaquete;
	string destino;
	Fecha fechaSalida;

	public:
		Paquete(string,Fecha);
		virtual float calcularCosto() = 0;
		virtual ~Paquete();
};



#endif /* PAQUETE_H_ */

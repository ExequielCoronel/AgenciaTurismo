/*
 * ContratacionVuelo.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef CONTRATACIONVUELO_H_
#define CONTRATACIONVUELO_H_

#include "fecha.h"
#include "Hora.h"
#include <iostream>
using namespace std;

class ContratacionVuelo
{
	static long IA;
	long codContratacionV;
	string lineaAerea;
	string operadorVuelo;
	Fecha fechaSalida;
	Fecha fechaLlegada;
	Hora horaSalida;
	Hora horaLlegada;
	float tarifaXMenor;
	float tarifaXMayor;

	public:
		ContratacionVuelo(string lineaAerea,string operadorVuel,Fecha fechaSalida,Hora horasalida,Fecha fechaLlegada,Hora horaLlegada,float tarifaXmenor,float tarifaXmayor);
		string getLineaAerea();
		string getOperadorVuelo();
		Fecha getFechaSalida();
		Fecha getFechaLlegada();
		Hora getHoraSalida();
		Hora getHoraLlegada();
		float getTarifaXMenor();
		float getTarifaXMayor();
		~ContratacionVuelo();
};



#endif /* CONTRATACIONVUELO_H_ */

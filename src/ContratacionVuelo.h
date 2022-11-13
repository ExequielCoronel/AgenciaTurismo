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
	float tarifaPorMenor;
	float tarifaPorMayor;

	public:
		ContratacionVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor);
		string getLineaAerea();
		string getOperadorVuelo();
		Fecha getFechaSalida();
		Fecha getFechaLlegada();
		Hora getHoraSalida();
		Hora getHoraLlegada();
		float getTarifaPorMenor();
		float getTarifaPorMayor();
		~ContratacionVuelo();
};



#endif /* CONTRATACIONVUELO_H_ */
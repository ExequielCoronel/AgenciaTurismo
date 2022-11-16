#ifndef CONTRATACIONVUELO_H_
#define CONTRATACIONVUELO_H_

#include "Fecha.h"
#include "Hora.h"
#include "Contratacion.h"
#include <iostream>
using namespace std;

class ContratacionVuelo: public Contratacion
{
	string lineaAerea;
	string operadorVuelo;
	Fecha fechaSalida;
	Fecha fechaLlegada;
	Hora horaSalida;
	Hora horaLlegada;
	float tarifaPorMenor;
	float tarifaPorMayor;
	int cantMayores;
	int cantMenores;

	public:
		ContratacionVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores);
		string getLineaAerea();
		string getOperadorVuelo();
		Fecha getFechaSalida();
		Fecha getFechaLlegada();
		Hora getHoraSalida();
		Hora getHoraLlegada();
		float getTarifaPorMenor();
		float getTarifaPorMayor();
		float calcularCostoContratacion();
		~ContratacionVuelo();
};



#endif /* CONTRATACIONVUELO_H_ */

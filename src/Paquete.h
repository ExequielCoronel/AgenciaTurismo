#ifndef PAQUETE_H_
#define PAQUETE_H_

#include "iostream"
using namespace std;
#include "Fecha.h"

class Paquete
{
	static long IA;

	protected:
		long codPaquete;
		string destino;
		Fecha fechaSalida;
		int cantidadDias;

	public:
		Paquete(string destino, Fecha fechaSalida, int cantidadDias);
		virtual long getCodigo() = 0;
		virtual float calcularCosto() = 0;
		virtual ~Paquete();
};



#endif
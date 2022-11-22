#ifndef PAQUETE_H_
#define PAQUETE_H_

#include "iostream"
using namespace std;
#include "Fecha.h"
#include "Contratacion.h"

class Paquete
{
	static long AI;

	protected:
		long codPaquete;
		string destino;
		Fecha fechaSalida;
		int cantidadDias;

	public:
		Paquete(string destino, Fecha fechaSalida, int cantidadDias);
		long getCodigo();
		virtual float calcularCosto() = 0;
		virtual void ingresarContratacion(Contratacion* contratacion) = 0;
		virtual void ingresarTrayecto(Trayecto* trayecto) = 0;
		virtual void eliminarContratacion(long codigo) = 0;
		virtual void eliminarTrayecto(long codigo) = 0;
		virtual int cantidadContrataciones() = 0;
		Fecha getFechaSalida();
		virtual ~Paquete();
};



#endif

#ifndef PAQUETEPROPIO_H_
#define PAQUETEPROPIO_H_

#include "Paquete.h"
#include <vector>
#include "Trayecto.h"
#include "Contratacion.h"

class PaquetePropio : public Paquete
{
	vector<Trayecto*> ListaTrayectos;
	int cupoMaxPasajeros;
	int cantidadPersonas;
	float descuento;

	public:
		PaquetePropio(string destino, Fecha fechaSalida, int cantidadDias, int cupoMaximoPasajeros, float descuento);
		int getCupoMaxPasajeros();
		bool ingresarPersonas(int cantidad);
		float getDescuento();
		float calcularCosto();
		void ingresarTrayecto(Trayecto* trayecto);
		void ingresarContratacion(Contratacion* contratacion);
		void eliminarPersonas(int cantidad);
		int cantidadContrataciones();
		void eliminarTrayecto(long codigo);
		void eliminarContratacion(long codigo);
		void getInfo();
		~PaquetePropio();
};




#endif

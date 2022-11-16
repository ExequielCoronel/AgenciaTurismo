#ifndef PAQUETEPROPIO_H_
#define PAQUETEPROPIO_H_

#include "Paquete.h"
#include <vector>
#include "Trayecto.h"

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
		long getCodigo();
		void AgregarTrayecto(Trayecto*);
		void EliminarTrayecto(long codTrayecto);
		~PaquetePropio();
};




#endif
/*
 * PaquetePropio.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef PAQUETEPROPIO_H_
#define PAQUETEPROPIO_H_

#include "Paquete.h"
#include <vector>
#include "Trayecto.h"

class PaquetePropio : public Paquete
{
	vector<Trayecto*> ListaTrayectos;
	int cupoMaxPasajeros;
	int cantidadReservas;
	float descuento;

	public:
		PaquetePropio(string destino,Fecha fechaSalida,int cantidadDias,int cantidadReservas,int cupoMaximoPasajeros,float descuento);
		int getCupoMaxPasajeros();
		int getCantidadReservas();
		float getDescuento();
		float calcularCosto();
		void AgregarTrayecto(Trayecto*);
		~PaquetePropio();
};




#endif /* PAQUETEPROPIO_H_ */

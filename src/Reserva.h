/*
 * Reserva.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef RESERVA_H_
#define RESERVA_H_

#include <vector>
#include "Paquete.h"
#include "Agente.h"
#include "Pasajero.h"

class Reserva
{
    static long AI;
    long CodigoReserva;
    Fecha fechaReserva;
    Fecha fechaCaducidad;
    Agente *Agent;
    vector<Pasajero*> ListadoPasajeros;
    Paquete *Packet;
    float senia;

	public:
    	Reserva(Fecha fechaReserva,Fecha fechaCaducidad,float senia, Agente Agente, Paquete* Paquete);
    	long getCodigoReserva();
    	Fecha getFechaReserva();
    	Fecha getFechaCaducidad();
    	Agente getAgente();
    	Paquete* getPaquete();
    	bool AgregarPasajero(Pasajero*);
    	float getSenia();
    	~Reserva();
}



#endif /* RESERVA_H_ */

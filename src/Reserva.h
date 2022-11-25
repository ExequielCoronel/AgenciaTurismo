#ifndef RESERVA_H_
#define RESERVA_H_

#include <vector>
#include "Paquete.h"
#include "Agente.h"
#include "Cliente.h"

class Reserva
{
	static long AI;
	const float PORCENTAJESENIA = 0.30;
	long CodigoReserva;
	Fecha fechaReserva;
	Fecha fechaCaducidad;
	Agente *Agent;
	vector<Cliente*> ListadoPasajeros;
	Paquete *Packet;
	int cantPersonas;
	float senia;
	bool reservaConfirmada;

	public:
		Reserva(Fecha fechaReserva, Fecha fechaCaducidad, int cantPersonas, Agente *Agente, Paquete *Paquete);

		Paquete *getPaquete();
		void AgregarPasajero(Cliente*);
		void EliminarPasajero(long codPasajero);
		bool pagarSenia(long pagoSenia);
		float SeniaMinima();
		void confirmarReserva();
		float costoTotal();

		//Getters
		long getCodigoReserva();
		Fecha getFechaReserva();
		Fecha getFechaCaducidad();
		Agente getAgente();
		float getSenia();
		void getInfo();
		int getCantidadPersonas();
		float getSaldoAPagar();

		
		~Reserva();
};

#endif

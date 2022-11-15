#ifndef RESERVA_H_
#define RESERVA_H_

#include <vector>
#include "Paquete.h"
#include "Agente.h"
#include "Pasajero.h"

class Reserva
{
    static long AI;
    const float PORCENTAJESENIA = 0.30;
    long CodigoReserva;
    Fecha fechaReserva;
    Fecha fechaCaducidad;
    Agente *Agent;
    vector<Pasajero*> ListadoPasajeros;
    Paquete *Packet;
    float senia;
    bool reservaConfirmada;

	public:
    	Reserva(Fecha fechaReserva,Fecha fechaCaducidad, Agente Agente, Paquete* Paquete);
    	long getCodigoReserva();
    	Fecha getFechaReserva();
    	Fecha getFechaCaducidad();
    	Agente getAgente();
    	Paquete* getPaquete();
    	bool AgregarPasajero(Pasajero*);
    	bool EliminarPasajero(long codPasajero);
    	bool pagarSenia(long pagoSenia);
    	float getSenia();
    	float SeniaMinima();
    	bool getPaqueteConfirmado();
    	void confirmarReserva();
    	~Reserva();
}



#endif /* RESERVA_H_ */

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
#include "Pasajero.h"

class Reserva
{
    static long AI;
    long CodigoReserva;
    Fecha fecha;
    string NombreAgente;
    vector<Pasajero*> ListadoPasajeros;
    Paquete *Paquete;
    float senia;
}



#endif /* RESERVA_H_ */

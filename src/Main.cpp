#include <iostream>

using namespace std;

#include "Agente.h"
#include "ContratacionHotel.h"
#include "ContratacionVuelo.h"
#include "Paquete.h"
#include "PaqueteEspecial.h"
#include "PaquetePropio.h"
#include "Pasajero.h"
#include "Reserva.h"
#include "Trayecto.h"
#include "Fecha.h"
#include "Hora.h"

int main() {
	Fecha fechaSalida(11,01,2023), fechaLlegada(12,01,2023);
	PaquetePropio PP1("BRASIL",fechaSalida,7,5,30,0.20);
	cout<<PP1.calcularCosto()<<endl;
	return 0;
}

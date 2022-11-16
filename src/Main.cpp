#include <iostream>

using namespace std;

#include "Empresa.h"
#include "Agente.h"
#include "ContratacionHotel.h"
#include "ContratacionVuelo.h"
#include "Paquete.h"
#include "PaqueteEspecial.h"
#include "PaquetePropio.h"
#include "Cliente.h"
#include "Reserva.h"
#include "Trayecto.h"
#include "Fecha.h"
#include "Hora.h"

int main() {
	Empresa empresa("Lecfer Turismo");

	// Añadir empleados
	empresa.ingresarAgente("Juan Ignacio", "Gramajo", 43867293);
	empresa.ingresarAgente("Jacundo", "Vabas", 42825293);
	empresa.ingresarAgente("Tajiel", "Videla", 43682930);

	// Añadir pasajeros
	empresa.ingresarCliente("Francisco", "Coronel", 43710806, 514193077964, Fecha(21, 10, 2001));
	empresa.ingresarCliente("Ezequiel", "Acosta", 43564834, 420691997078, Fecha(27, 9, 2001));


	// Añadir trayectos
	empresa.ingresarTrayecto("Tucuman", "Famailla", 1, 250);
	empresa.ingresarTrayecto("Tucuman", "Simoca", 1, 400);
	empresa.ingresarTrayecto("Tucuman", "Buenos Aires", 2, 20000);
	empresa.ingresarTrayecto("Tucuman", "Salta", 1, 10000);

	empresa.getInfo();

	return 0;
}

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

void ingresarDatos(Empresa &empresa);

int main()
{
	Empresa empresa("Lecfer Turismo");

	ingresarDatos(empresa);

	// Mostrar información de agentes
	cout << "Agentes: " << endl;
	empresa.getInfoAgente();

	// Mostrar información de clientes
	cout << "Clientes: " << endl;
	empresa.getInfoCliente();

	// Mostrar información de paquetes
	cout << "Paquetes: " << endl;
	empresa.getInfoPaquete();

	// Mostrar información de trayectos
	cout << "Trayectos: " << endl;
	empresa.getInfoTrayecto();

	// Mostrar información de contrataciones
	cout << "Contrataciones: " << endl;
	empresa.getInfoContratacion();

	return 0;
}

void ingresarDatos(Empresa &empresa)
{
	// Añadir empleados
	empresa.ingresarAgente("Juan Ignacio", "Gramajo", 43867293);	// Código 1
	empresa.ingresarAgente("Ezequiel", "Acosta", 43710806);			// Código 2
	empresa.ingresarAgente("Francisco", "Coronel", 43564834);		// Código 3

	// Añadir pasajeros
	empresa.ingresarCliente("Eduardo", "Herrera", 39827304, 514193077, Fecha(15, 2, 1990));		// Código 1
	empresa.ingresarCliente("Martin", "Lopez", 35012036, 420691997, Fecha(27, 5, 1995));	   // Código 2

	// Añadir trayectos
	empresa.ingresarTrayecto("Tucuman", "Famailla", 1, 250);			   // Código 1
	empresa.ingresarTrayecto("Tucuman", "Simoca", 1, 400);				   // Código 2
	empresa.ingresarTrayecto("Tucuman", "Buenos Aires", 2, 20000);		   // Código 3
	empresa.ingresarTrayecto("Buenos Aires", "Estados Unidos", 2, 100000); // Código 4
	empresa.ingresarTrayecto("Tucuman", "Salta", 1, 10000);				   // Código 5

	// Añadir paquetes
	empresa.ingresarPaquete("Estados Unidos", Fecha(10, 12, 2022), 3, 200, 10); // Código 1
	empresa.ingresarPaquete("Salta", Fecha(5, 12, 2022), 1, 80, 15);			// Código 2

	// Añadir trayectos a paquete
	// Ingresando en paquete Tucumán -- Estados Unidos
	empresa.ingresarTrayectoEnPaquete(1, 3);
	empresa.ingresarTrayectoEnPaquete(1, 4);

	// Ingresando en paquete Tucumán -- Salta
	empresa.ingresarTrayectoEnPaquete(2, 5);

	// Añadir contrataciones
	empresa.ingresarHotel("Cerum", "Buenos Aires", Fecha(20, 12, 2022), Fecha(25, 12, 2022), 5, 5000, 0, "Buenos Aires", Fecha(19, 12, 2022), 6, 15000); // Código contratación 1, código paquete 3
}
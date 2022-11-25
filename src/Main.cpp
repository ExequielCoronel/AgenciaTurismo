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
	int opcion;

	ingresarDatos(empresa);

	cout << "Ingresar opcion para mostrar informacion: " << endl;
	cout << "1) Agentes" << endl;
	cout << "2) Clientes" << endl;
	cout << "3) Paquetes" << endl;
	cout << "4) Trayectos" << endl;
	cout << "5) Contrataciones" << endl;
	cout << "6) Reservas" << endl;
	cout << "Opcion: ";
	cin >> opcion;

	cout << endl;

	switch (opcion)
	{
		case 1:
			cout << "Agentes: " << endl;
			empresa.getInfoAgente();
			break;
		case 2:
			cout << "Clientes: " << endl;
			empresa.getInfoCliente();
			break;
		case 3:
			cout << "Paquetes: " << endl;
			empresa.getInfoPaquete();
			break;
		case 4:
			cout << "Trayectos: " << endl;
			empresa.getInfoTrayecto();
			break;
		case 5:
			cout << "Contrataciones: " << endl;
			empresa.getInfoContratacion();
			break;
		case 6:
			cout << "Reservas: " << endl;
			empresa.getInfoReserva();
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
	}

	return 0;
}

void ingresarDatos(Empresa &empresa)
{
	// Añadir empleados
	empresa.ingresarAgente("Juan Ignacio", "Gramajo", 43867293); // Código 1
	empresa.ingresarAgente("Ezequiel", "Acosta", 43710806);		 // Código 2
	empresa.ingresarAgente("Francisco", "Coronel", 43564834);	 // Código 3

	// Añadir pasajeros
	empresa.ingresarCliente("Eduardo", "Herrera", 32597373, 435643869, Fecha(15, 2, 1990)); // Código 1
	empresa.ingresarCliente("Martin", "Lopez", 32254443, 463625643, Fecha(27, 5, 1990));	// Código 2
	empresa.ingresarCliente("Katrina", "Prado", 38012036, 442966110, Fecha(11, 8, 1999));	// Código 3
	empresa.ingresarCliente("Mirta", "Robledo", 28106273, 483645786, Fecha(17, 5, 1980));	// Código 4

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
	// Ingresar hotel
	empresa.ingresarHotel("Cerum", "Buenos Aires", Fecha(20, 1, 2023), Fecha(25, 12, 2023), 5, 5000, 0, "Buenos Aires", Fecha(19, 1, 2023), 6, 15000); // Código contratación 1, código paquete 3

	// Ingresar vuelo
	empresa.ingresarVuelo("JetSmart", "Juan Casal", Fecha(19, 1, 2023), Hora(0, 0, 15), Fecha(19, 1, 2023), Hora(0, 0, 17), 20000, 25000, 2, 2, 3); // Código contratación 2, código paquete 3

	// Añadir reservas
	empresa.crearReserva(Fecha(20, 11, 2022), Fecha(30, 11, 2022), 2, 1, 1);
	empresa.crearReserva(Fecha(18, 11, 2022), Fecha(28, 11, 2022), 1, 2, 1);
}
#ifndef PAQUETEESPECIAL_H_
#define PAQUETEESPECIAL_H_

#include "Paquete.h"
#include <vector>
#include "ContratacionHotel.h"
#include "ContratacionVuelo.h"
#include "Contratacion.h"
#include "Trayecto.h"

class PaqueteEspecial : public Paquete
{
	float comisionAgencia;
	vector<Contratacion*> contrataciones;

	public:
		PaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia);
		float getComisionAgencia();
		int cantidadContrataciones();
		void ingresarTrayecto(Trayecto* trayecto);
		void ingresarContratacion(Contratacion* contratacion);
		void eliminarContratacion(long codigo);
		void eliminarTrayecto(long codigo);
		void eliminarPersonas(int cantidad);
		bool ingresarPersonas(int cantidad);
		float calcularCosto();
		void getInfo();
		~PaqueteEspecial();
};



#endif

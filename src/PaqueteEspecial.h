#ifndef PAQUETEESPECIAL_H_
#define PAQUETEESPECIAL_H_

#include "Paquete.h"
#include <vector>
#include "ContratacionHotel.h"
#include "ContratacionVuelo.h"
#include "Contratacion.h"

class PaqueteEspecial : public Paquete
{
	float comisionAgencia;
	vector<Contratacion*> contrataciones;

	public:
		PaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia);
		float getComisionAgencia();
		void agregarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores);
		void agregarHotel(string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche);
		void eliminarContratacion(long codigo);
		long getCodigo();
		float calcularCosto();
		~PaqueteEspecial();
};



#endif
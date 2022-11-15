#ifndef PAQUETEESPECIAL_H_
#define PAQUETEESPECIAL_H_

#include "Paquete.h"
#include <vector>
#include "ContratacionHotel.h"
#include "ContratacionVuelo.h"

class PaqueteEspecial : public Paquete
{
	float comisionAgencia;
	vector<ContratacionVuelo*> vuelosContratados;
	vector<ContratacionHotel*> hotelesContratados;


	public:
		PaqueteEspecial(string destino,Fecha fechaSalida,int cantidadDias,float comisionAgencia);
		float getComisionAgencia();
		void AgregarVuelo(string,string,Fecha,Hora,Fecha,Hora,float,float);
		void AgregarHotel(string,string,Fecha,Fecha,int,float);
		void EliminarVuelo(long);
		void EliminarHotel(long);
		float calcularCosto();
		~PaqueteEspecial();
};



#endif /* PAQUETEESPECIAL_H_ */

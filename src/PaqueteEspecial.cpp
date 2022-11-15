#include "PaqueteEspecial.h"

PaqueteEspecial::PaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia) : Paquete(destino,fechaSalida,cantidadDias){this->comisionAgencia = comisionAgencia;}

float PaqueteEspecial::getComisionAgencia(){return comisionAgencia;}

void PaqueteEspecial::AgregarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor)
{
	ContratacionVuelo nuevaContratacionVuelo(lineaAerea, operadorVuelo, fechaSalida, horaSalida, fechaLlegada, horaLlegada, tarifaPorMenor, tarifaPorMayor);
	vuelosContratados.push_back(&nuevaContratacionVuelo);
}

void PaqueteEspecial::AgregarHotel(string nombreHotel,string ubicacion,Fecha CheckIn,Fecha CheckOut,int cantidadNoches,float precioNoche)
{
	ContratacionHotel nuevaContratacionHotel(nombreHotel,ubicacion,CheckIn,CheckOut,cantidadNoches,precioNoche);
	hotelesContratados.push_back(&nuevaContratacionHotel);
}

void PaqueteEspecial::EliminarHotel(long codHotel)
{
	for(int i=0; i<hotelesContratados.size();i++)
	{																		//Se podria utilizar un Iterador
		if(codHotel == hotelesContratados[i]->getCodContratacionHotel())
		{
			hotelesContratados.erase(hotelesContratados.begin() + i);
		}
	}
}

void PaqueteEspecial::EliminarVuelo(long codVuelo)
{
	for(int i=0; i<vuelosContratados.size();i++)
	{																		//Se podria utilizar un Iterador
		if(codVuelo == vuelosContratados[i]->getCodContratacionV())
		{
			vuelosContratados.erase(vuelosContratados.begin() + i);
		}
	}
}

float PaqueteEspecial::calcularCosto(){

	float total = 0;

	for(ContratacionHotel* contHotel:hotelesContratados){
		total = total + contHotel->calcularCostoContratacion();
	}

	for(ContratacionVuelo* contVuelo:vuelosContratados){
		total = total + contVuelo->calcularCostoContratacion();
	}

	total = total + this->comisionAgencia;

	return total;
}

PaqueteEspecial::~PaqueteEspecial()
{
	int i=0;
	while(!vuelosContratados.empty())
	{
		delete vuelosContratados[i];
		i++;
	}
	vuelosContratados.clear();
	i=0;
	while(!hotelesContratados.empty())
	{
		delete hotelesContratados[i];
		i++;
	}
	hotelesContratados.clear();
}

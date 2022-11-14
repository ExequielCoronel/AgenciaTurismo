#include "PaqueteEspecial.h"

PaqueteEspecial::PaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia) : Paquete(destino,fechaSalida,cantidadDias){this->comisionAgencia = comisionAgencia;}

float PaqueteEspecial::getComisionAgencia(){return comisionAgencia;}

bool PaqueteEspecial::AgregarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor)
{
	ContratacionVuelo *nuevaContratacionVuelo(lineaAerea, operadorVuelo, fechaSalida, horaSalida, fechaLlegada, horaLlegada,tarifaPorMenor, tarifaPorMayor);
	if(vuelosContratados.push_back(nuevaContratacionVuelo)) return true;
	return false;
}

bool PaqueteEspecial::AgregarHotel(string nombreHotel,string ubicacion,Fecha CheckIn,Fecha CheckOut,int cantidadNoches,float precioNoche)
{
	ContratacionHotel *nuevaContratacionHotel(nombreHotel,ubicacion,CheckIn,CheckOut,cantidadNoches,precioNoche);
	if(hotelesContratados.push_back(nuevaContratacionHotel)) return true;
	return false;
}

bool PaqueteEspecial::EliminarHotel(long codHotel)
{
	for(int i=0; i<hotelesContratados.size();i++)
	{																		//Se podria utilizar un Iterador
		if(codHotel == hotelesContratados[i]->getCodContratacionHotel())
		{
			if(hotelesContratados.erase(hotelesContratados.begin() + i)) return true;
		}
	}
	return false;
}

bool PaqueteEspecial::EliminarVuelo(long codVuelo)
{
	for(int i=0; i<vuelosContratados.size();i++)
	{																		//Se podria utilizar un Iterador
		if(codVuelo == vuelosContratados[i]->getCodContratacionV())
		{
			if(vuelosContratados.erase(vuelosContratados.begin() + i)) return true;
		}
	}
	return false;
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

PaqueteEspecial::~PaqueteEspecial(){}

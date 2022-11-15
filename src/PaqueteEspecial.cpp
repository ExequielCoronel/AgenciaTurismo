#include "PaqueteEspecial.h"

PaqueteEspecial::PaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia) : Paquete(destino, fechaSalida, cantidadDias)
{
	this->comisionAgencia = comisionAgencia;
}

float PaqueteEspecial::getComisionAgencia()
{
	return comisionAgencia;
}

void PaqueteEspecial::agregarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores)
{
	contrataciones.push_back(new ContratacionVuelo(lineaAerea, operadorVuelo, fechaSalida, horaSalida, fechaLlegada, horaLlegada, tarifaPorMenor, tarifaPorMayor, cantMayores, cantMenores));
}

void PaqueteEspecial::agregarHotel(string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche)
{
	contrataciones.push_back(new ContratacionHotel(nombreHotel, ubicacion, CheckIn, CheckOut, cantidadNoches, precioNoche));
}

long PaqueteEspecial::getCodigo()
{
	return codPaquete;
}

void PaqueteEspecial::eliminarContratacion(long codigo)
{
	int index;
	bool encontrado = false;

	for (index = 0; index < contrataciones.size() && !encontrado; index++)
	{
		if (contrataciones[index]->getCodigo() == codigo)
		{
			encontrado = true;
		}
	}

	if (encontrado)
	{
		delete contrataciones[index];
		contrataciones.erase(contrataciones.begin() + index);
	}
}

float PaqueteEspecial::calcularCosto()
{

	float total = 0;

	for (Contratacion *cont : contrataciones)
	{
		total = total + cont->calcularCostoContratacion();
	}

	total = total + this->comisionAgencia;

	return total;
}

PaqueteEspecial::~PaqueteEspecial()
{

	for (int i = 0; i < contrataciones.size(); i++)
	{
		delete contrataciones[i];
	}

	contrataciones.clear();
}

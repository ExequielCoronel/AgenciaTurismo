#include "PaqueteEspecial.h"

PaqueteEspecial::PaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia) : Paquete(destino, fechaSalida, cantidadDias)
{
	this->comisionAgencia = comisionAgencia;
}

float PaqueteEspecial::getComisionAgencia()
{
	return comisionAgencia;
}

int PaqueteEspecial::cantidadContrataciones()
{
	return contrataciones.size();
}

void PaqueteEspecial::ingresarTrayecto(Trayecto *trayecto)
{
}

void PaqueteEspecial::ingresarContratacion(Contratacion *contratacion)
{
	contrataciones.push_back(contratacion);
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
		contrataciones.erase(contrataciones.begin() + index);
	}
}

void PaqueteEspecial::eliminarTrayecto(long codigo)
{
}

bool PaqueteEspecial::ingresarPersonas(int cantidad)
{
	return true;
}

void PaqueteEspecial::eliminarPersonas(int cantidad)
{

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

void PaqueteEspecial::getInfo()
{
	Paquete::getInfo();
	cout << "Comision de agencia: " << getComisionAgencia() << endl;
	cout << "Costo: " << calcularCosto() << endl;
	cout << "Contrataciones: " << endl;

	for (Contratacion *contratacion : contrataciones)
	{
		contratacion->getInfo();
		cout << endl;
	}
}

PaqueteEspecial::~PaqueteEspecial()
{

	for (int i = 0; i < contrataciones.size(); i++)
	{
		delete contrataciones[i];
	}

	contrataciones.clear();
}

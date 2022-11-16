#include "Fecha.h"
#include <iostream>

#include <sstream>
#include <ctime>

using namespace std;

Fecha::Fecha()
{
	setFechaActual();
	// cout<<"Constructor de Fecha "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
Fecha::Fecha(short int d, short int m, short int a)
{
	setFecha(d, m, a);
	// cout<<"Constructor de Fecha "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
Fecha::Fecha(const Fecha &f) : dia(f.dia), mes(f.mes), anio(f.anio)
{
	// cout<<"Constructor de Fecha "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::setFechaActual(void)
{
	struct tm *ptr;
	time_t sec;

	time(&sec);
	ptr = localtime(&sec);
	dia = (short)ptr->tm_mday;
	mes = (short)ptr->tm_mon + 1;
	anio = (short)ptr->tm_year + 1900;
}

void Fecha::setFecha(const short d, const short m, const short a)
{
	dia = d;
	mes = m;
	anio = a;
	if (!esAnioValido() || !esMesValido() || !esDiaValido())
	{
		setFechaActual();
	}
}

bool Fecha::esAnioValido() const
{
	return (anio > 0);
}
bool Fecha::esMesValido() const
{
	return (mes >= 1 && mes <= 12);
}
bool Fecha::esDiaValido() const
{
	return (dia >= 1 && dia <= diasEnMes(mes));
}

short Fecha::diasEnMes(const short m) const
{
	short cantidadDias = 0;
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cantidadDias = 31;
		break;
	case 2:
		if (esAnioBisiesto())
		{
			cantidadDias = 29;
		}
		else
		{
			cantidadDias = 28;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cantidadDias = 30;
		break;
	}
	return cantidadDias;
}

bool Fecha::esAnioBisiesto() const
{
	return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

short Fecha::getDia() const
{
	return dia;
}
short Fecha::getMes() const
{
	return mes;
}
short Fecha::getAnio() const
{
	return anio;
}
string Fecha::toString()
{
	stringstream flujo;
	flujo << this->dia << "/" << this->mes << "/" << this->anio;
	return string(flujo.str());
}

bool Fecha::esFechaPasada()
{
	Fecha fechaActual;
	if (getAnio() >= fechaActual.getAnio())
	{
		if (getAnio() == fechaActual.getAnio())
		{
			if (getMes() >= fechaActual.getMes())
			{
				if (getMes() == fechaActual.getMes())
				{
					if (getDia() >= fechaActual.getDia())
					{
						return false;
					}
					return true;
				}
				return false;
			}
			return true;
		}
		return false;
	}
	return true;
}

tm cambiarFormatoATM(Fecha fecha)
{
	time_t sec;
	time(&sec);

	struct tm *pTm;
	pTm = localtime(&sec);
	pTm->tm_mday = fecha.getDia();
	pTm->tm_mon = fecha.getMes() - 1;
	pTm->tm_year = fecha.getAnio() - 1900;
	return *pTm;
}

double Fecha::diasDeDiferenciaAFechaActual()
{
	Fecha fechaActual;

	struct tm pTm1, pTma;
	pTm1 = cambiarFormatoATM(*this);
	pTma = cambiarFormatoATM(fechaActual);
	time_t x = mktime(&pTm1);
	time_t y = mktime(&pTma);
	double distancia = difftime(y, x) / (60 * 60 * 24);
	if (distancia < 0)
	{
		distancia = distancia * (-1);
	}
	return distancia;
}

// Devuelve la diferencia en años de 2 fechas
int operator-(Fecha fecha1, Fecha fecha2)
{
	int dif = fecha1.getAnio() - fecha2.getAnio();
	if (fecha1.getMes() < fecha2.getMes() || (fecha1.getMes() == fecha2.getMes() && fecha1.getDia() < fecha2.getDia()))
		dif = dif - 1;
	return dif;
}

string getNombreMes(int mes)
{
	string nombre = "indefinido";
	switch (mes)
	{
	case 1:
		nombre = "Enero";
		break;
	case 2:
		nombre = "Febrero";
		break;
	case 3:
		nombre = "Marzo";
		break;
	case 4:
		nombre = "Abril";
		break;
	case 5:
		nombre = "Mayo";
		break;
	case 6:
		nombre = "Junio";
		break;
	case 7:
		nombre = "Julio";
		break;
	case 8:
		nombre = "Agosto";
		break;
	case 9:
		nombre = "Septiembre";
		break;
	case 10:
		nombre = "Octubre";
		break;
	case 11:
		nombre = "Noviembre";
		break;
	case 12:
		nombre = "Diciembre";
		break;
	default:
		break;
	}
	return nombre;
}

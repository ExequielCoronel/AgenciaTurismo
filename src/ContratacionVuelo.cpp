#include "ContratacionVuelo.h"

ContratacionVuelo::ContratacionVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores) : Contratacion()
{
    this->lineaAerea = lineaAerea;
    this->operadorVuelo = operadorVuelo;
    this->fechaSalida = fechaSalida;
    this->horaSalida = horaSalida;
    this->fechaLlegada = fechaLlegada;
    this->horaLlegada = horaLlegada;
    this->tarifaPorMenor = tarifaPorMenor;
    this->tarifaPorMayor = tarifaPorMayor;
    this->cantMayores = cantMayores;
    this->cantMenores = cantMenores;
}

string ContratacionVuelo::getLineaAerea()
{
    return this->lineaAerea;
}

string ContratacionVuelo::getOperadorVuelo()
{
    return this->operadorVuelo;
}

Fecha ContratacionVuelo::getFechaSalida()
{
    return this->fechaSalida;
}

Fecha ContratacionVuelo::getFechaLlegada()
{
    return this->fechaLlegada;
}

Hora ContratacionVuelo::getHoraSalida()
{
    return this->horaSalida;
}

Hora ContratacionVuelo::getHoraLlegada()
{
    return this->horaLlegada;
}

float ContratacionVuelo::getTarifaPorMenor()
{
    return this->tarifaPorMenor;
}

float ContratacionVuelo::getTarifaPorMayor()
{
    return this->tarifaPorMayor;
}

long ContratacionVuelo::getCodigo()
{
    return codigo;
}

float ContratacionVuelo::calcularCostoContratacion()
{
    return (this->tarifaPorMayor * this->cantMayores) + (this->tarifaPorMenor * this->cantMenores);
}

ContratacionVuelo::~ContratacionVuelo()
{

}
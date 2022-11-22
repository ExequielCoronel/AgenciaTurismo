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

float ContratacionVuelo::calcularCostoContratacion()
{
    return (this->tarifaPorMayor * this->cantMayores) + (this->tarifaPorMenor * this->cantMenores);
}

void ContratacionVuelo::getInfo()
{
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Linea aerea: " << getLineaAerea() << endl;
    cout << "Fecha de salida: " << getFechaSalida().toString() << endl;
    cout << "Fecha de llegada: " << getFechaLlegada().toString() << endl;
    cout << "Hora de salida: " << getHoraSalida() << endl;
    cout << "Hora de llegada: " << getHoraLlegada() << endl;
    cout << "Costo menores: " << getTarifaPorMenor() << endl;
    cout << "Costo mayores: " << getTarifaPorMayor() << endl;
    cout << "Cantidad mayores: " << cantMayores << endl;
    cout << "Cantidad menores: " << cantMenores << endl;
}

ContratacionVuelo::~ContratacionVuelo()
{

}
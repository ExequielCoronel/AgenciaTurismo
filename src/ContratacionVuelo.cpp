#include "ContratacionVuelo.h"

long ContratacionVuelo::IA = 1;

ContratacionVuelo::ContratacionVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int mayores, int menores){
    this->lineaAerea = lineaAerea;
    this->operadorVuelo = operadorVuelo;
    this->fechaSalida = fechaSalida;
    this->horaSalida = horaSalida;
    this->fechaLlegada = fechaLlegada;
    this->horaLlegada = horaLlegada;
    this->tarifaPorMenor = tarifaPorMenor;
    this->tarifaPorMayor = tarifaPorMayor;
    this->cantMayores = mayores;
    this->cantMenores = menores;
    this->codContratacionV = IA;
    IA++;
}

string ContratacionVuelo::getLineaAerea(){
    return this->lineaAerea;
}

string ContratacionVuelo::getOperadorVuelo(){
    return this->operadorVuelo;
}

Fecha ContratacionVuelo::getFechaSalida(){
    return this->fechaSalida;
}

Fecha ContratacionVuelo::getFechaLlegada(){
    return this->fechaLlegada;
}

Hora ContratacionVuelo::getHoraSalida(){
    return this->horaSalida;
}

Hora ContratacionVuelo::getHoraLlegada(){
    return this->horaLlegada;
}

float ContratacionVuelo::getTarifaPorMenor(){
    return this->tarifaPorMenor;
}

float ContratacionVuelo::getTarifaPorMayor(){
    return this->tarifaPorMayor;
}

long ContratacionVuelo::getCodContratacionV(){return codContratacionV;}

float ContratacionVuelo::calcularCostoContratacion(){ //para la funcion hay que mandar por parametros cuantos mayores y cuantos menores

	return ((this->tarifaPorMayor * this->cantMayores) + (this->tarifaPorMenor * this->cantMenores));
}

ContratacionVuelo::~ContratacionVuelo(){

}

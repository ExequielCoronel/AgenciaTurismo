#include "ContratacionVuelo.h"

long ContratacionVuelo::IA = 1;

ContratacionVuelo::ContratacionVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor){
    this->lineaAerea = lineaAerea;
    this->operadorVuelo = operadorVuelo;
    this->fechaSalida = fechaSalida;
    this->horaSalida = horaSalida;
    this->fechaLlegada = fechaLlegada;
    this->horaLlegada = horaLlegada;
    this->tarifaPorMenor = tarifaPorMenor;
    this->tarifaPorMayor = tarifaPorMayor;
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

ContratacionVuelo::~ContratacionVuelo(){

}

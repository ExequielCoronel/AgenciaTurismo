#include "Hora.h"

Hora::Hora(){
    this->segundos = 0;
    this->minutos = 0;
    this->horas = 0;
}

Hora::Hora(int seg, int min, int hs){

    if(esHoraValida(seg, min, hs)){
        this->segundos = seg;
        this->minutos = min;
        this->horas = hs;
    }
}

int Hora::getHoras(){

    return horas;
}

int Hora::getMinutos(){

    return minutos;
}

int Hora::getSegundos(){

    return segundos;
}

void Hora::setHoras(int hs){
    if(hs > 0 && hs < 24){
        this->horas = hs;
    }
}

void Hora::setMinutos(int min){
    if(min > 0 && min < 60){
        this->minutos = min;
    }
}

void Hora::setSegundos(int seg){
    if(seg > 0 && seg < 60){
        this->segundos = seg;
    }
}

bool Hora::esHoraValida(int seg, int min, int hs){

    if(seg < 0 || seg > 59){
        return false;
    }

    if(min < 0 || min > 59){
        return false;
    }

    if(hs < 0 || hs > 23){
        return false;
    }

    return true;
}

ostream& operator<<(ostream& os, const Hora& hs)
{
    string seg, min, horas;
    seg = to_string(hs.segundos);
    min = to_string(hs.minutos);
    horas = to_string(hs.horas);
    if(hs.segundos < 10) seg = "0" + to_string(hs.segundos);
    if(hs.minutos < 10) min = "0" + to_string(hs.minutos);
    if(hs.horas < 10) horas = "0" + to_string(hs.horas);

    os << horas << ":" << min << ":" << seg;

    return os;
}
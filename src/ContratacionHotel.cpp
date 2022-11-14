#include "ContratacionHotel.h"

long ContratacionHotel::IA = 1;

ContratacionHotel::ContratacionHotel(string nombreHotel,string ubicacion,Fecha CheckIn,Fecha CheckOut,int cantidadNoches,float precioNoche){
    this->nombreHotel = nombreHotel;
    this->ubicacion = ubicacion;
    this->fechaCheckIn = CheckIn;
    this->fechaCheckOut = CheckOut;
    this->cantNoches = cantidadNoches;
    this->precioNoche = precioNoche;
    this->codContratacionH = IA;
    IA++;
}

string ContratacionHotel::getNombreHotel(){
    return this->nombreHotel;
}

string ContratacionHotel::getUbicacion(){
    return this->ubicacion;
}

Fecha ContratacionHotel::getFechaCheckIn(){
    return this->fechaCheckIn;
}

Fecha ContratacionHotel::getFechaCheckOut(){
    return this->fechaCheckOut;
}

int ContratacionHotel::getCantidadNoches(){
    return this->cantNoches;
}

float ContratacionHotel::getPrecioXNoche(){
    return this->precioNoche;
}

long ContratacionHotel::getCodContratacionHotel(){return codContratacionH;}

float ContratacionHotel::calcularCostoContratacion(){

	return this->cantNoches * this->getPrecioXNoche();
}

ContratacionHotel::~ContratacionHotel(){

}

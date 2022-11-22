#include "ContratacionHotel.h"

ContratacionHotel::ContratacionHotel(string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche) : Contratacion()
{
    this->nombreHotel = nombreHotel;
    this->ubicacion = ubicacion;
    this->fechaCheckIn = CheckIn;
    this->fechaCheckOut = CheckOut;
    this->cantNoches = cantidadNoches;
    this->precioNoche = precioNoche;
}

string ContratacionHotel::getNombreHotel()
{
    return this->nombreHotel;
}

string ContratacionHotel::getUbicacion()
{
    return this->ubicacion;
}

Fecha ContratacionHotel::getFechaCheckIn()
{
    return this->fechaCheckIn;
}

Fecha ContratacionHotel::getFechaCheckOut()
{
    return this->fechaCheckOut;
}

int ContratacionHotel::getCantidadNoches()
{
    return this->cantNoches;
}

float ContratacionHotel::getPrecioXNoche()
{
    return this->precioNoche;
}

float ContratacionHotel::calcularCostoContratacion()
{

    return this->cantNoches * this->getPrecioXNoche();
}

void ContratacionHotel::getInfo(){
    Contratacion::getInfo();
    cout << "Hotel: " << getNombreHotel() << endl;
    cout << "Ubicacion: " << getUbicacion() << endl;
    cout << "Fecha check in: " << fechaCheckIn.toString() << endl;
    cout << "Fecha check out: " << fechaCheckOut.toString() << endl;
    cout << "Cantidad de noches: " << getCantidadNoches() << endl;
    cout << "Precio por noche: " << getPrecioXNoche() << endl;
}

ContratacionHotel::~ContratacionHotel()
{
}

#include "Cliente.h"

long Cliente::IA = 1;

Cliente::Cliente()
{
}

Cliente::Cliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento)
{
    this->codCliente = IA;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
    this->pasaporte = pasaporte;
    this->fechaNacimiento = fechaNacimiento;
    IA++;
}

long Cliente::getCodigo()
{
    return this->codCliente;
}

string Cliente::getNombre()
{
    return this->nombre;
}

string Cliente::getApellido()
{
    return this->apellido;
}

long Cliente::getDni()
{
    return this->dni;
}

long Cliente::getPasaporte()
{
    return this->pasaporte;
}

Fecha Cliente::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

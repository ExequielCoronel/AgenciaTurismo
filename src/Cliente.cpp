#include "Cliente.h"

long Cliente::AI = 1;

Cliente::Cliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento)
{
    this->codCliente = AI;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
    this->pasaporte = pasaporte;
    this->fechaNacimiento = fechaNacimiento;
    AI++;
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

Cliente::~Cliente()
{

}
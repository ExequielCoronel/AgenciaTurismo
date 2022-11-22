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

void Cliente::getInfo()
{
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "DNI: " << getDni() << endl;
    cout << "Pasaporte: " << getPasaporte() << endl;
    cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << endl;
}

Fecha Cliente::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

Cliente::~Cliente()
{

}
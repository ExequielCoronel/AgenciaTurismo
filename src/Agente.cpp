#include "Agente.h"

long Agente::AI = 1;

Agente::Agente(string nombre, string apellido, long dni)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
    this->codAgente = AI;
    AI++;
}

long Agente::getCodAgente()
{
    return this->codAgente;
}

string Agente::getNombre()
{
    return this->nombre;
}

string Agente::getApellido()
{
    return this->apellido;
}

void Agente::getInfo()
{
    cout << "Codigo: " << getCodAgente() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "DNI: " << dni << endl;
}

Agente::~Agente()
{

}
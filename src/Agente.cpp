#include "Agente.h"

long Agente::IA = 1;

Agente::Agente(string nombre, string apellido, long dni){
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
    this->codAgente = IA;
    IA++;
}

long Agente::getCodAgente(){
    return this->codAgente;
}

string Agente::getNombre(){
    return this->nombre;
}

string Agente::getApellido(){
    return this->apellido;
}

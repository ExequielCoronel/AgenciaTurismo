#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Fecha.h"

using namespace std;

class Cliente
{
	static long IA;
    long codCliente;
	string nombre;
	string apellido;
	long dni;
    long pasaporte;
    Fecha fechaNacimiento;

    public:
        Cliente();
        Cliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento);
        long getCodigo();
        string getNombre();
        string getApellido();
        long getDni();
        long getPasaporte();
        Fecha getFechaNacimiento();
};

#endif
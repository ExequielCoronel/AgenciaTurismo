#ifndef AGENTE_H_
#define AGENTE_H_

#include <iostream>
using namespace std;

class Agente
{
	static long AI;
	long codAgente;
	string nombre;
	string apellido;
	long dni;

	public:
		Agente(string nombre, string apellido, long dni);
		long getCodAgente();
		string getNombre();
		string getApellido();
		~Agente();
};



#endif
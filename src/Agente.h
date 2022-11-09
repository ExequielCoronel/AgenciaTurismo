/*
 * Agente.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef AGENTE_H_
#define AGENTE_H_


#include <iostream>
using namespace std;

class Agente
{
	static long IA;
	long codAgente;
	string nombre;
	string apellido;
	long dni;

	public:
		Agente(string,string,long);
		long getCodAgente();
		string getNombre();
		string getApellido();
		~Agente();
};



#endif /* AGENTE_H_ */

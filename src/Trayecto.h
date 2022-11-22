#ifndef TRAYECTO_H_
#define TRAYECTO_H_

#include <iostream>
using namespace std;

class Trayecto
{
	static long AI;
	long codTrayecto;
	string ciudadOrigen;
	string ciudadDestino;
	int cantDias;
	float costo;

	public:
		Trayecto(string ciudadOrigen,string ciudadDestino,int cantidadDias,float costo);
		string getCiudadOrigen();
		string getCiudadDestino();
		int getcantDias();
		float getCosto();
		long getCodTrayecto();
		void getInfo();
		~Trayecto();
};



#endif
/*
 * ContratacionesHotel.h
 *
 *  Created on: 9 nov. 2022
 *      Author: execo
 */

#ifndef CONTRATACIONHOTEL_H_
#define CONTRATACIONHOTEL_H_

#include <iostream>
using namespace std;
#include "Fecha.h"

class ContratacionHotel
{
	static long IA;
	long codContratacionH;
	string nombreHotel;
	string ubicacion;
	Fecha fechaCheckIn;
	Fecha fechaCheckOut;
	int cantNoches;
	float precioXNoche;

	public:
		ContratacionHotel(string nombreHotel,string ubicacion,Fecha CheckIn,Fecha CheckOut,int cantidadNoches,float precioXnoche);
		string getNombreHotel();
		string getUbicacion();
		Fecha getFechaCheckIn();
		Fecha getFechaCheckOut();
		int getCantidadNoches();
		float getPrecioXNoche();
		~ContratacionHotel();
};



#endif /* CONTRATACIONHOTEL_H_ */

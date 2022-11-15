#ifndef FECHA_H_
#define FECHA_H_
#include <iostream>

using namespace std;

class Fecha {
private:
	short dia;
	short mes;
	short anio;
	bool esDiaValido() const;
	bool esMesValido() const;
	bool esAnioValido() const;
	short diasEnMes(const short mes) const;

public:
	Fecha();
	Fecha(const short d, const short m, const short a);
	Fecha(const Fecha &f);
	void setFechaActual(void);
	void setFecha(const short d, const short m, const short a);
	short getDia() const;
	short getMes() const;
	short getAnio() const;
	bool esAnioBisiesto(void) const;
    string toString();
    bool esFechaPasada();
    double diasDeDiferenciaAFechaActual();

};

int operator-(Fecha fecha1, Fecha fecha2);
tm cambiarFormatoaTM(Fecha fecha);
string getNombreMes(int mes);
#endif 
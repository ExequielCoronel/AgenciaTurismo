#include <iostream>

#ifndef HORA_H
#define HORA_H

using namespace std;

class Hora
{
    int segundos, minutos, horas;

    public:
        Hora();
        Hora(int seg, int min, int hs);
        int getSegundos();
        int getMinutos();
        int getHoras();
        void setSegundos(int seg);
        void setHoras(int hs);
        void setMinutos(int min);
        bool esHoraValida(int seg, int min, int hs);
        friend ostream& operator<<(ostream& os, const Hora& hs);
};

#endif
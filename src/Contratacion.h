#ifndef CONTRATACION_H
#define CONTRATACION_H

#include <iostream>

using namespace std;

class Contratacion{
    static long AI;
    
    protected:
        long codigo;

    public:
        Contratacion();
        long getCodigo();
        virtual void getInfo();
        virtual float calcularCostoContratacion() = 0;
};

#endif
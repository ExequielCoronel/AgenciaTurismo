#ifndef CONTRATACION_H
#define CONTRATACION_H

class Contratacion{
    static long AI;
    
    protected:
        long codigo;

    public:
        Contratacion();
        virtual float calcularCostoContratacion() = 0;
        virtual long getCodigo() = 0;
};

#endif
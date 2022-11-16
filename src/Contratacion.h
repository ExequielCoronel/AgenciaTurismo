#ifndef CONTRATACION_H
#define CONTRATACION_H

class Contratacion{
    static long AI;
    
    protected:
        long codigo;

    public:
        Contratacion();
        long getCodigo();
        virtual float calcularCostoContratacion() = 0;
};

#endif
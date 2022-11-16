#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include "Agente.h"
#include "Cliente.h"
#include "Trayecto.h"
#include "Reserva.h"
#include "Paquete.h"
#include "PaqueteEspecial.h"
#include "PaquetePropio.h"

using namespace std;

class Empresa
{
    string nombre;
    vector<Agente*> empleados;
    vector<Cliente*> clientes;
    vector<Trayecto*> trayectos;
    vector<Reserva*> reservas;
    vector<PaquetePropio*> paquetesPropios;
    vector<PaqueteEspecial*> paquetesEspeciales;

    public:
        Empresa();
        Empresa(string nombreEmpresa);
        void ingresarAgente(string nombre, string apellido, long dni);
        void eliminarAgente(long codigo);
        void ingresarCliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento);
        void eliminarCliente(long codigo);
        void crearReserva(Fecha fechaReserva, Fecha fechaCaducidad, int cantPersonas, long codAgente, long codPaquete);
        void pagarReserva(long codigo);
        void eliminarReserva(long codigo);
        void ingresarTrayecto(string ciudadOrigen, string ciudadDestino, int cantidadDias, float costo);
        void eliminarTrayecto(long codigo);
        void ingresarPaquetePropio(string destino, Fecha fechaSalida, int cantidadDias, int cupoMaximoPasajeros, float descuento);
        void ingresarTrayectoEnPaquete(long codPaquete, long codTrayecto);
        void ingresarPaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia);
        void ingresarContVueloEnPaquete(long codPaquete, string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores);
        void ingresarContHotelEnPaquete(long codPaquete, string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche);
        void eliminarPaquete(long codigo);
        void getInfo();
        ~Empresa();
};

#endif
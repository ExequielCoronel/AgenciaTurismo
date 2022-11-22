#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include "Agente.h"
#include "Cliente.h"
#include "Trayecto.h"
#include "Reserva.h"
#include "Contratacion.h"
#include "ContratacionHotel.h"
#include "ContratacionVuelo.h"
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
    vector<Contratacion*> contrataciones;
    vector<Paquete*> paquetes;

    public:
        // Constructor
        Empresa(string nombreEmpresa);

        // Ingresar
        void ingresarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores, long codPaquete = 0, string destino = "", Fecha fechaSalidaPaquete = Fecha(), int cantidadDias = 0, int comisionAgencia = 0);
        void ingresarHotel(string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche, long codPaquete = 0, string destino = "", Fecha fechaSalidaPaquete = Fecha(), int cantidadDias = 0, int comisionAgencia = 0);
        void ingresarAgente(string nombre, string apellido, long dni);
        void ingresarCliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento);
        void ingresarTrayecto(string ciudadOrigen, string ciudadDestino, int cantidadDias, float costo);
        void ingresarPaquete(string destino, Fecha fechaSalida, int cantidadDias, int cupoMaximoPasajeros, float descuento);
        void ingresarTrayectoEnPaquete(long codPaquete, long codTrayecto);
        void crearReserva(Fecha fechaReserva, Fecha fechaCaducidad, int cantPersonas, long codAgente, long codPaquete);
        void pagarReserva(long codigo);

        // Eliminar
        void eliminarAgente(long codigo);
        void eliminarCliente(long codigo);
        void eliminarReserva(long codigo);
        void eliminarTrayecto(long codigo);
        void eliminarContratacion(long codigo);
        void eliminarPaquete(long codigo);
        void eliminarContratacionDePaquete(long codPaquete, long codContratacion);
        void eliminarTrayectoDePaquete(long codPaquete, long codTrayecto);

        // Mostrar
        void getInfo();
        void getInfoPaquete(int codigo = 0);
        void getInfoTrayecto(int codigo = 0);
        void getInfoContratacion(int codigo = 0);
        void getInfoCliente(int codigo = 0);
        void getInfoAgente(int codigo = 0);

        // Getters por código privados
        private:
            Agente* getAgentePorCodigo(long codigo);
            Cliente* getClientePorCodigo(long codigo);
            Trayecto* getTrayectoPorCodigo(long codigo);
            Reserva* getReservaPorCodigo(long codigo);
            Contratacion* getContratacionPorCodigo(long codigo);
            Paquete* getPaquetePorCodigo(long codigo);

        // Destructor
        public:
            ~Empresa();
};

#endif
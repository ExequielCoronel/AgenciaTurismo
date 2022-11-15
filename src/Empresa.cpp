#include "Empresa.h"

Empresa::Empresa()
{
}

Empresa::Empresa(string nombreEmpresa)
{
    this->nombre = nombreEmpresa;
}

void Empresa::ingresarAgente(string nombre, string apellido, long dni)
{
    empleados.push_back(new Agente(nombre, apellido, dni));
}

void Empresa::eliminarAgente(long codigo)
{
    int index;
    bool encontrado = false;

    for (index = 0; index < empleados.size() && !encontrado; index++)
    {
        if (empleados[index]->getCodAgente() == codigo)
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        delete empleados[index];
        empleados.erase(empleados.begin() + index);
    }
}

void Empresa::ingresarCliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento)
{
    clientes.push_back(new Cliente(nombre, apellido, dni, pasaporte, fechaNacimiento));
}

void Empresa::eliminarCliente(long codigo)
{
    int index;
    bool encontrado = false;

    for (index = 0; index < clientes.size() && !encontrado; index++)
    {
        if (clientes[index]->getCodigo() == codigo)
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        delete clientes[index];
        clientes.erase(clientes.begin() + index);
    }
}

void Empresa::crearReserva(Fecha fechaReserva, Fecha fechaCaducidad, long codAgente, long codPaquete)
{
    Agente *empleado;
    Paquete *paquete;
    bool encontradoEmpleado = false, encontradoPaquete = false;

    // Obtener el agente según el código
    for (Agente *emp : empleados)
    {
        if (emp->getCodAgente() == codAgente)
        {
            empleado = emp;
            encontradoEmpleado = true;
            break;
        }
    }

    // Obtener el paquete según el código
    for (Paquete *p : paquetes)
    {
        if (p->getCodigo() == codPaquete)
        {
            paquete = p;
            encontradoPaquete = true;
            break;
        }
    }

    if (encontradoEmpleado && encontradoPaquete)
    {
        reservas.push_back(new Reserva(fechaReserva, fechaCaducidad, empleado, paquete));
    }
}

void Empresa::ingresarTrayecto(string ciudadOrigen, string ciudadDestino, int cantidadDias, float costo)
{
    trayectos.push_back(new Trayecto(ciudadOrigen, ciudadDestino, cantidadDias, costo));
}

void Empresa::eliminarTrayecto(long codigo)
{
    int index;
    bool encontrado = false;

    for (index = 0; index < trayectos.size() && !encontrado; index++)
    {
        if (trayectos[index]->getCodTrayecto() == codigo)
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        delete trayectos[index];
        trayectos.erase(trayectos.begin() + index);
    }
}

void Empresa::ingresarPaquetePropio(string destino, Fecha fechaSalida, int cantidadDias, int cantidadReservas, int cupoMaximoPasajeros, float descuento)
{
    paquetes.push_back(new PaquetePropio(destino, fechaSalida, cantidadDias, cantidadReservas, cupoMaximoPasajeros, descuento));
}

void Empresa::ingresarPaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia)
{
    paquetes.push_back(new PaqueteEspecial(destino, fechaSalida, cantidadDias, comisionAgencia));
}

void Empresa::ingresarTrayectoEnPaquete(long codPaquete, long codTrayecto)
{
    Paquete *paquete;
    Trayecto *trayecto;
    bool encPaquete = false, encTrayecto = false;

    // Buscar el paquete según el código
    for(Paquete* p: paquetes)
    {
        if(p->getCodigo() == codPaquete)
        {
            paquete = p;
            encPaquete = true;
            break;
        }
    }

    // Buscar el trayecto según el código
    for(Trayecto* t: trayectos)
    {
        if(t->getCodTrayecto() == codTrayecto)
        {
            trayecto = t;
            encTrayecto = true;
            break;
        }
    }
}

void Empresa::ingresarContVueloEnPaquete(long codPaquete, string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores)
{
    Paquete *paquete;
    bool encPaquete = false;

    // Buscar el paquete según el código
    for(Paquete* p: paquetes)
    {
        if(p->getCodigo() == codPaquete)
        {
            paquete = p;
            encPaquete = true;
            break;
        }
    }
}

void Empresa::eliminarPaquete(long codigo)
{
    int index;
    bool encontrado = false;

    for (index = 0; index < paquetes.size() && !encontrado; index++)
    {
        if (paquetes[index]->getCodigo() == codigo)
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        delete paquetes[index];
        paquetes.erase(paquetes.begin() + index);
    }
}
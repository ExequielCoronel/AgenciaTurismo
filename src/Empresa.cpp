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

void Empresa::crearReserva(Fecha fechaReserva, Fecha fechaCaducidad, int cantPersonas, long codAgente, long codPaquete)
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

    // Obtener en paquete propio según el código
    for (PaquetePropio *p : paquetesPropios)
    {
        if (p->getCodigo() == codPaquete)
        {
            if(p->ingresarPersonas(cantPersonas))
            {
                paquete = p;
                encontradoPaquete = true;
                break;
            }
            else
            {
                return;
            }
            
        }
    }

    // En caso de no encontrar el código en los paquetes propios, buscar en el paquete especial
    if (!encontradoPaquete)
    {
        for (PaqueteEspecial *p : paquetesEspeciales)
        {
            if (p->getCodigo() == codPaquete)
            {
                paquete = p;
                encontradoPaquete = true;
                break;
            }
        }
    }

    if (encontradoEmpleado && encontradoPaquete)
    {
        reservas.push_back(new Reserva(fechaReserva, fechaCaducidad, cantPersonas, empleado, paquete));
    }
}

void Empresa::pagarReserva(long codigo)
{

}

void Empresa::eliminarReserva(long codigo)
{
    int index;
    bool encontrado = false;

    for (index = 0; index < reservas.size() && !encontrado; index++)
    {
        if (reservas[index]->getCodigoReserva() == codigo)
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        delete reservas[index];
        reservas.erase(reservas.begin() + index);
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

void Empresa::ingresarPaquetePropio(string destino, Fecha fechaSalida, int cantidadDias, int cupoMaximoPasajeros, float descuento)
{
    paquetesPropios.push_back(new PaquetePropio(destino, fechaSalida, cantidadDias, cupoMaximoPasajeros, descuento));
}

void Empresa::ingresarPaqueteEspecial(string destino, Fecha fechaSalida, int cantidadDias, float comisionAgencia)
{
    paquetesEspeciales.push_back(new PaqueteEspecial(destino, fechaSalida, cantidadDias, comisionAgencia));
}

void Empresa::ingresarTrayectoEnPaquete(long codPaquete, long codTrayecto)
{
    PaquetePropio *paquete;
    Trayecto *trayecto;
    bool encPaquete = false, encTrayecto = false;

    // Buscar el paquete según el código
    for (PaquetePropio *p : paquetesPropios)
    {
        if (p->getCodigo() == codPaquete)
        {
            paquete = p;
            encPaquete = true;
            break;
        }
    }

    // Buscar el trayecto según el código
    for (Trayecto *t : trayectos)
    {
        if (t->getCodTrayecto() == codTrayecto)
        {
            trayecto = t;
            encTrayecto = true;
            break;
        }
    }

    if (encPaquete && encTrayecto)
    {
        paquete->AgregarTrayecto(trayecto);
    }
}

void Empresa::ingresarContVueloEnPaquete(long codPaquete, string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores)
{
    PaqueteEspecial *paquete;
    bool encPaquete = false;

    // Buscar el paquete según el código
    for (PaqueteEspecial *p : paquetesEspeciales)
    {
        if (p->getCodigo() == codPaquete)
        {
            paquete = p;
            encPaquete = true;
            break;
        }
    }

    if(encPaquete)
    {
        paquete->agregarVuelo(lineaAerea, operadorVuelo, fechaSalida, horaSalida, fechaLlegada, horaLlegada, tarifaPorMenor, tarifaPorMayor, cantMayores, cantMenores);
    }
}

void Empresa::eliminarPaquete(long codigo)
{
    int index, tipoPaquete;
    bool encontrado = false;

    for (index = 0; index < paquetesPropios.size() && !encontrado; index++)
    {
        if (paquetesPropios[index]->getCodigo() == codigo)
        {
            encontrado = true;
        }
    }

    for (index = 0; index < paquetesEspeciales.size() && !encontrado; index++)
    {
        if (paquetesEspeciales[index]->getCodigo() == codigo)
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        if(tipoPaquete == 1)
        {
            delete paquetesPropios[index];
            paquetesPropios.erase(paquetesPropios.begin() + index);
        }
        else{
            delete paquetesEspeciales[index];
            paquetesEspeciales.erase(paquetesEspeciales.begin() + index);
        }
    }
}

Empresa::~Empresa()
{
    for(int i = 0; i < empleados.size(); i++)
    {
        delete empleados[i];
    }

    for(int i = 0; i < clientes.size(); i++)
    {
        delete clientes[i];
    }

    for(int i = 0; i < trayectos.size(); i++)
    {
        delete trayectos[i];
    }

    for(int i = 0; i < reservas.size(); i++)
    {
        delete reservas[i];
    }

    for(int i = 0; i < paquetesPropios.size(); i++)
    {
        delete paquetesPropios[i];
    }

    for(int i = 0; i < paquetesEspeciales.size(); i++)
    {
        delete paquetesEspeciales[i];
    }

    empleados.clear();
    clientes.clear();
    trayectos.clear();
    reservas.clear();
    paquetesPropios.clear();
    paquetesEspeciales.clear();
}

void Empresa::getInfo()
{
    
}
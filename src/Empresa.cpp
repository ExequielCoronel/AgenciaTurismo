#include "Empresa.h"

Empresa::Empresa(string nombreEmpresa)
{
    this->nombre = nombreEmpresa;
}

void Empresa::ingresarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores, long codPaquete = 0)
{
    contrataciones.push_back(new ContratacionVuelo(lineaAerea, operadorVuelo, fechaSalida, horaSalida, fechaLlegada, horaLlegada, tarifaPorMenor, tarifaPorMayor, cantMayores, cantMenores));

    // En caso de ingresar un código de paquete, busca el paquete
    if (codPaquete != 0)
    {
        getPaquetePorCodigo(codPaquete)->ingresarContratacion(contrataciones[contrataciones.size() - 1]);
    }
}

void Empresa::ingresarHotel(string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche, long codPaquete = 0)
{
    contrataciones.push_back(new ContratacionHotel(nombreHotel, ubicacion, CheckIn, CheckOut, cantidadNoches, precioNoche));

    // En caso de ingresar un código de paquete, busca el paquete
    if (codPaquete != 0)
    {
        getPaquetePorCodigo(codPaquete)->ingresarContratacion(contrataciones[contrataciones.size() - 1]);
    }
}

void Empresa::ingresarAgente(string nombre, string apellido, long dni)
{
    empleados.push_back(new Agente(nombre, apellido, dni));
}

void Empresa::ingresarCliente(string nombre, string apellido, long dni, long pasaporte, Fecha fechaNacimiento)
{
    clientes.push_back(new Cliente(nombre, apellido, dni, pasaporte, fechaNacimiento));
}

void Empresa::ingresarTrayecto(string ciudadOrigen, string ciudadDestino, int cantidadDias, float costo)
{
    trayectos.push_back(new Trayecto(ciudadOrigen, ciudadDestino, cantidadDias, costo));
}

void Empresa::ingresarPaquete(string destino, Fecha fechaSalida, int cantidadDias, int cupoMaximoPasajeros, float descuento)
{
    paquetes.push_back(new PaquetePropio(destino, fechaSalida, cantidadDias, cupoMaximoPasajeros, descuento));
}

void Empresa::ingresarTrayectoEnPaquete(long codPaquete, long codTrayecto)
{
    Paquete *paquete;
    Trayecto *trayecto;

    // Buscar el paquete según el código
    paquete = getPaquetePorCodigo(codPaquete);

    // Buscar el trayecto según el código
    trayecto = getTrayectoPorCodigo(codTrayecto);

    if (paquete != NULL && trayecto != NULL)
    {
        paquete->ingresarTrayecto(trayecto);
    }
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

    paquete = getPaquetePorCodigo(codPaquete);

    if(paquete != NULL)

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

void Empresa::eliminarContratacion(long codigo)
{
    int index;
    bool encontrado = false;

    for (index = 0; index < contrataciones.size() && !encontrado; index++)
    {
        if (contrataciones[index]->getCodigo() == codigo)
        {
            encontrado = true;
        }
    }

    // Buscar la contratación en cada paquete y eliminarla del paquete

    if (encontrado)
    {
        delete contrataciones[index];
        contrataciones.erase(contrataciones.begin() + index);
    }
}

void Empresa::eliminarContratacionDePaquete(long codPaquete, long codContratacion)
{
    Paquete* paquete;

    paquete = getPaquetePorCodigo(codPaquete);

    if(paquete != NULL)
    {
        paquete->eliminarContratacion(codContratacion);
    }
}

void Empresa::eliminarTrayectoDePaquete(long codPaquete, long codTrayecto)
{
    Paquete* paquete;

    paquete = getPaquetePorCodigo(codPaquete);

    if(paquete != NULL)
    {
        paquete->eliminarTrayecto(codTrayecto);
    }
}


Empresa::~Empresa()
{
    for (int i = 0; i < empleados.size(); i++)
    {
        delete empleados[i];
    }

    for (int i = 0; i < clientes.size(); i++)
    {
        delete clientes[i];
    }

    for (int i = 0; i < trayectos.size(); i++)
    {
        delete trayectos[i];
    }

    for (int i = 0; i < reservas.size(); i++)
    {
        delete reservas[i];
    }

    for (int i = 0; i < paquetes.size(); i++)
    {
        delete paquetes[i];
    }

    empleados.clear();
    clientes.clear();
    trayectos.clear();
    reservas.clear();
    paquetes.clear();
}

void Empresa::getInfo()
{
    cout << "Clientes:" << endl;
    for (Cliente *c : clientes)
    {
        cout << c->getApellido() << endl;
    }

    cout << endl
         << "Empleados:" << endl;
    for (Agente *a : empleados)
    {
        cout << a->getApellido() << endl;
    }

    cout << endl
         << "Trayectos:" << endl;
    for (Trayecto *t : trayectos)
    {
        cout << t->getCiudadOrigen() << " - " << t->getCiudadDestino() << endl;
    }

    cout << endl
         << "Paquetes:" << endl;
    for (Paquete *p : paquetes)
    {
        cout << "Costo: " << p->calcularCosto() << endl;
    }
}

Agente *Empresa::getAgentePorCodigo(long codigo)
{
    for (Agente *a : empleados)
    {
        if (a->getCodAgente() == codigo)
            return a;
    }

    return NULL;
}

Cliente *Empresa::getClientePorCodigo(long codigo)
{
    for (Cliente *c : clientes)
    {
        if (c->getCodigo() == codigo)
            return c;
    }

    return NULL;
}

Trayecto *Empresa::getTrayectoPorCodigo(long codigo)
{
    for (Trayecto *t : trayectos)
    {
        if (t->getCodTrayecto() == codigo)
            return t;
    }

    return NULL;
}

Reserva *Empresa::getReservaPorCodigo(long codigo)
{
    for (Reserva *s : reservas)
    {
        if (s->getCodigoReserva() == codigo)
            return s;
    }

    return NULL;
}

Contratacion *Empresa::getContratacionPorCodigo(long codigo)
{
    for (Contratacion *c : contrataciones)
    {
        if (c->getCodigo() == codigo)
            return c;
    }

    return NULL;
}

Paquete *Empresa::getPaquetePorCodigo(long codigo)
{
    for (Paquete *p : paquetes)
    {
        if (p->getCodigo() == codigo)
            return p;
    }

    return NULL;
}
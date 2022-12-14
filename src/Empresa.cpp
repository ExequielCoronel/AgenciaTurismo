#include "Empresa.h"

Empresa::Empresa(string nombreEmpresa)
{
    this->nombre = nombreEmpresa;
}

void Empresa::ingresarVuelo(string lineaAerea, string operadorVuelo, Fecha fechaSalida, Hora horaSalida, Fecha fechaLlegada, Hora horaLlegada, float tarifaPorMenor, float tarifaPorMayor, int cantMayores, int cantMenores, long codPaquete, string destino, Fecha fechaSalidaPaquete, int cantidadDias, int comisionAgencia)
{
    Contratacion *contratacion = new ContratacionVuelo(lineaAerea, operadorVuelo, fechaSalida, horaSalida, fechaLlegada, horaLlegada, tarifaPorMenor, tarifaPorMayor, cantMayores, cantMenores);
    Paquete *paquete;
    contrataciones.push_back(contratacion);

    // En caso de ingresar un código de paquete, busca el paquete
    if (codPaquete != 0 && getPaquetePorCodigo(codPaquete) != NULL)
    {
        getPaquetePorCodigo(codPaquete)->ingresarContratacion(contratacion);
    }
    else
    {
        paquete = new PaqueteEspecial(destino, fechaSalidaPaquete, cantidadDias, comisionAgencia);
        paquetes.push_back(paquete);
        paquete->ingresarContratacion(contratacion);
    }
}

void Empresa::ingresarHotel(string nombreHotel, string ubicacion, Fecha CheckIn, Fecha CheckOut, int cantidadNoches, float precioNoche, long codPaquete, string destino, Fecha fechaSalidaPaquete, int cantidadDias, int comisionAgencia)
{
    Contratacion *contratacion = new ContratacionHotel(nombreHotel, ubicacion, CheckIn, CheckOut, cantidadNoches, precioNoche);
    contrataciones.push_back(contratacion);
    Paquete *paquete;

    // En caso de ingresar un código de paquete, busca el paquete
    if (codPaquete != 0 && getPaquetePorCodigo(codPaquete) != NULL)
    {
        getPaquetePorCodigo(codPaquete)->ingresarContratacion(contrataciones[contrataciones.size() - 1]);
    }
    else
    {
        paquete = new PaqueteEspecial(destino, fechaSalidaPaquete, cantidadDias, comisionAgencia);
        paquetes.push_back(paquete);
        paquete->ingresarContratacion(contratacion);
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

    empleado = getAgentePorCodigo(codAgente);
    paquete = getPaquetePorCodigo(codPaquete);

    if (empleado != NULL && paquete != NULL)
    {
        reservas.push_back(new Reserva(fechaReserva, fechaCaducidad, cantPersonas, empleado, paquete));
    }
}

void Empresa::confirmarReserva(long codigo)
{
    bool encontrado = false;
    for (int i = 0; i < reservas.size() && !encontrado; i++)
    {
        if (reservas[i]->getCodigoReserva() == codigo)
        {
            encontrado = true;
            reservas[i]->confirmarReserva();
        }
    }
}

bool Empresa::pagarSenia(long codigo, float monto)
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
        return reservas[index]->pagarSenia(monto);
    }
    else
    {
        return false;
    }
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
        reservas[index]->getPaquete()->eliminarPersonas(reservas[index]->getCantidadPersonas());
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
    if (encontrado)
    {
        for (int i = 0; i < paquetes.size(); i++)
        {
            paquetes[i]->eliminarContratacion(codigo);
            if (paquetes[i]->cantidadContrataciones() == 0)
            {
                delete paquetes[i];
                paquetes.erase(paquetes.begin() + i);
            }
        }
        delete contrataciones[index];
        contrataciones.erase(contrataciones.begin() + index);
    }
}

void Empresa::eliminarContratacionDePaquete(long codPaquete, long codContratacion)
{
    Paquete *paquete;

    paquete = getPaquetePorCodigo(codPaquete);

    if (paquete != NULL)
    {
        paquete->eliminarContratacion(codContratacion);
    }
}

void Empresa::eliminarTrayectoDePaquete(long codPaquete, long codTrayecto)
{
    Paquete *paquete;

    paquete = getPaquetePorCodigo(codPaquete);

    if (paquete != NULL)
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

void Empresa::getInfoPaquete(long codigo)
{
    if (codigo == 0)
    {
        for (Paquete *paquete : paquetes)
        {
            paquete->getInfo();
            cout << endl;
        }
    }
    else
    {
        Paquete *paquete = getPaquetePorCodigo(codigo);

        if (paquete != NULL)
        {
            paquete->getInfo();
            cout << endl;
        }
    }
}

void Empresa::getInfoTrayecto(long codigo)
{
    if (codigo == 0)
    {
        for (Trayecto *trayecto : trayectos)
        {
            trayecto->getInfo();
            cout << endl;
        }
    }
    else
    {
        Trayecto *trayecto = getTrayectoPorCodigo(codigo);

        if (trayecto != NULL)
        {
            trayecto->getInfo();
            cout << endl;
        }
    }
}

void Empresa::getInfoContratacion(long codigo)
{
    if (codigo == 0)
    {
        for (Contratacion *contratacion : contrataciones)
        {
            contratacion->getInfo();
            cout << endl;
        }
    }
    else
    {
        Contratacion *contratacion = getContratacionPorCodigo(codigo);

        if (contratacion != NULL)
        {
            contratacion->getInfo();
            cout << endl;
        }
    }
}

void Empresa::getInfoCliente(long codigo)
{
    if (codigo == 0)
    {
        for (Cliente *cliente : clientes)
        {
            cliente->getInfo();
            cout << endl;
        }
    }
    else
    {
        Cliente *cliente = getClientePorCodigo(codigo);

        if (cliente != NULL)
        {
            cliente->getInfo();
            cout << endl;
        }
    }
}

void Empresa::getInfoAgente(long codigo)
{
    if (codigo == 0)
    {
        for (Agente *agente : empleados)
        {
            agente->getInfo();
            cout << endl;
        }
    }
    else
    {
        Agente *agente = getAgentePorCodigo(codigo);

        if (agente != NULL)
        {
            agente->getInfo();
            cout << endl;
        }
    }
}

void Empresa::getInfoReserva(long codigo)
{
    if (codigo == 0)
    {
        for (Reserva *reserva : reservas)
        {
            reserva->getInfo();
            cout << endl;
        }
    }
    else
    {
        Reserva *reserva = getReservaPorCodigo(codigo);

        if (reserva != NULL)
        {
            reserva->getInfo();
            cout << endl;
        }
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

#include <iostream>
#include "Persona.h"

using namespace std;

class Cliente: public Persona {
    private:
        string idCliente, fechaRegistro;
    public:
        Cliente(string idCliente, string fechaRegistro, string id, string nombre, string email, int telefono, Direccion &direccion): idCliente(idCliente), fechaRegistro(fechaRegistro), Persona(id, nombre, email, telefono, direccion) {};
    };
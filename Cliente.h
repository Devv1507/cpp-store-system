#include <iostream>
#include "Persona.h"

using namespace std;

class Cliente: public Persona {
    private:
        int idCliente;
        string fechaRegistro;
    public:
        Cliente(int idCliente, string fechaRegistro, string id, string nombre, string email, int telefono, Direccion &direccion): idCliente(idCliente), fechaRegistro(fechaRegistro), Persona(id, nombre, email, telefono, direccion) {};
    };
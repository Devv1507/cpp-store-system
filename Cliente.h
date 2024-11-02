#include <iostream>
#include "Persona.h"

using namespace std;

class Cliente: public Persona {
    private:
        int idCliente;
        string fechaRegistro;
    public:
        Cliente(int idCliente, string fechaRegistro, string nombre, string apellido, int edad): idCliente(idCliente), fechaRegistro(fechaRegistro), Persona(nombre, apellido, edad) {};
    };
#include <iostream>
#include "Persona.h"

using namespace std;

class Proveedor: public Persona {
    private:
        string rut, banco, numeroCuenta, tipoCuenta;
    public:
        Proveedor(string rut, string banco, string numeroCuenta, string tipoCuenta, string id, string nombre, string email, int telefono, Direccion &direccion): 
            rut(rut), banco(banco), numeroCuenta(numeroCuenta), Persona(id, nombre, email, telefono, direccion) {};
        string getRut();
        string getBanco();
        string getNumeroCuenta();
        string getTipoCuenta();
        void setRut(string);
        void setBanco(string);
        void setNumeroCuenta(string);
        void setTipoCuenta(string);
        void mostrarDatos();
    };
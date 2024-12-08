#include <iostream>
#include "Persona.h"

using namespace std;

class Proveedor: public Persona {
    private:
        string rut, banco, numeroCuenta, tipoCuenta;
    public:
        Proveedor(string rut, string banco, string numeroCuenta, string tipoCuenta, string id, string nombre, string email, int telefono, Direccion &direccion): 
            rut(rut), banco(banco), numeroCuenta(numeroCuenta), tipoCuenta(tipoCuenta), Persona(id, nombre, email, telefono, direccion) {};
        string getRut() { return this->rut; };
        string getBanco() { return this->banco; };
        string getNumeroCuenta() { return this->numeroCuenta; };
        string getTipoCuenta()  { return this->tipoCuenta; };
        void setRut(string rut) { this->rut = rut; };
        void setBanco(string banco) { this->banco = banco; };
        void setNumeroCuenta(string numeroCuenta) { this->numeroCuenta = numeroCuenta; };
        void setTipoCuenta(string tipoCuenta) { this->tipoCuenta = tipoCuenta; };
        void mostrarDatos() override {
            Persona::mostrarDatos();
            cout << left
                << setw(10) << "RUT: " << rut << endl
                << setw(10) << "Banco: " << banco << endl
                << setw(10) << "Numero de Cuenta: " << numeroCuenta << endl
                << setw(10) << "Tipo de Cuenta: " << tipoCuenta << endl;
        };
    };
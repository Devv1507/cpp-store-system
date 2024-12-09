#include <iostream>
#include "Persona.h"

using namespace std;

class Proveedor: public Persona {
    private:
        string rut; // RUT del proveedor
        string banco; // Banco del proveedor
        string numeroCuenta; // Número de cuenta del proveedor
        string tipoCuenta; // Tipo de cuenta del proveedor
    public:
        /**
         * @brief Constructor de la clase Proveedor.
         * 
         * @param rut RUT del proveedor.
         * @param banco Banco del proveedor.
         * @param numeroCuenta Número de cuenta del proveedor.
         * @param tipoCuenta Tipo de cuenta del proveedor.
         * @param id Identificación de la persona.
         * @param nombre Nombre de la persona.
         * @param email Correo electrónico de la persona.
         * @param telefono Número de teléfono de la persona.
         * @param direccion Referencia a un objeto de la clase Direccion.
         */
        Proveedor(string rut, string banco, string numeroCuenta, string tipoCuenta, string id, string nombre, string email, string telefono, Direccion &direccion): 
            rut(rut), banco(banco), numeroCuenta(numeroCuenta), tipoCuenta(tipoCuenta), Persona(id, nombre, email, telefono, direccion) {};

        // Getters y Setters
        string getRut() { return this->rut; };
        string getBanco() { return this->banco; };
        string getNumeroCuenta() { return this->numeroCuenta; };
        string getTipoCuenta()  { return this->tipoCuenta; };
        void setRut(string rut) { this->rut = rut; };
        void setBanco(string banco) { this->banco = banco; };
        void setNumeroCuenta(string numeroCuenta) { this->numeroCuenta = numeroCuenta; };
        void setTipoCuenta(string tipoCuenta) { this->tipoCuenta = tipoCuenta; };

        /**
         * @brief Muestra los datos del proveedor.
         */
        void mostrarDatos() override {
            Persona::mostrarDatos();
            cout << left
                << setw(10) << "RUT: " << rut << endl
                << setw(10) << "Banco: " << banco << endl
                << setw(10) << "Numero de Cuenta: " << numeroCuenta << endl
                << setw(10) << "Tipo de Cuenta: " << tipoCuenta << endl;
        };
};
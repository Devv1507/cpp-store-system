#include <iostream>
#include "Persona.h"

using namespace std;

class Proveedor: public Persona {
    private:
        string rut; 
        string banco; 
        string numeroCuenta; 
        string tipoCuenta;

        /**
        * @brief Verifica que el tipo de cuenta sea válido.
        */
        bool verificarCuentaValida(string tipoCuenta){
            if(tipoCuenta != "ahorros" &&  tipoCuenta != "Ahorros" 
            && tipoCuenta != "corriente" &&  tipoCuenta != "Corriente"){
                return false;
            }
            return true;
        }
    public:
        /**
         * @brief Constructor de la clase Proveedor.
         * Esta clase representa un proveedor que suministra productos a la tienda.
         * A continuación se describen los parámetros del constructor:
         * @param rut RUT del proveedor.
         * @param banco Banco del proveedor.
         * @param numeroCuenta Número de cuenta del proveedor.
         * @param tipoCuenta Tipo de cuenta del proveedor.
         * El resto de parámetros son heredados de la clase Persona.
         */
        Proveedor(string rut, string banco, string numeroCuenta, string tipoCuenta, string id, string nombre, string email, string telefono, Direccion &direccion): 
            rut(rut), banco(banco), numeroCuenta(numeroCuenta), 
            Persona(id, nombre, email, telefono, direccion) {
                if (!verificarCuentaValida(tipoCuenta)) {
                    throw invalid_argument("El tipo de cuenta debe ser 'ahorros' o 'corriente'.");
                }
                this->tipoCuenta = tipoCuenta;
            };

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
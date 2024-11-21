#include <iostream>
#include <iomanip>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string rut, profesion, tipoCliente;
        float totalCompras;
    public:
        Cliente(string id, string nombre, string email, int telefono, Direccion& direccion, string rut, string profesion, string tipoCliente, float totalCompras):
            Persona(id, nombre, email, telefono, direccion), rut(rut), profesion(profesion), tipoCliente(tipoCliente), totalCompras(totalCompras) {}
        //Getters y Setters
        string getRut(){ return rut; };
        string getProfesion() { return profesion; };
        string getTipoCliente() { return tipoCliente; };
        float getTotalCompras() { return totalCompras; };
        void setRut(string rut) { this->rut = rut; };
        void setProfesion(string profesion) { this->profesion = profesion; };
        void setTipoCliente(string tipoCliente) { this->tipoCliente = tipoCliente; };
        void setTotalCompras(float totalCompras) { this->totalCompras = totalCompras; };
        //Método para mostrar los datos completos del cliente
        void mostrarDatos() override {
            Persona::mostrarDatos();
            cout << left 
                << setw(10) << "RUT: " << rut << endl
                << setw(10) << "Profesión: " << profesion << endl
                << setw(10) << "Tipo de Cliente: " << tipoCliente << endl
                << setw(10) << "Total de Compras: " << totalCompras << endl;
            direccion.mostrarDireccion();
        };
};
#include <iostream>
#include <iomanip>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string rut, profesion, tipoCliente;
        float totalCompras;
    public:
        Cliente(string id, string nombre, string email, int telefono, Direccion& direccion): Persona(id, nombre, email, telefono, direccion), rut(rut), profesion(profesion), tipoCliente(tipoCliente), totalCompras(totalCompras) {}
        //Getters y Setters
        string getRut();
        string getProfesion();
        string getTipoCliente();
        float getTotalCompras();
        void setRut(string rut);
        void setProfesion(string profesion);
        void setTipoCliente(string tipoCliente);
        void setTotalCompras(float totalCompras);
        //Método para mostrar los datos completos del cliente
        void mostrarDatos() override;
};

    string Cliente::getRut() { return rut; };
    string Cliente::getProfesion() { return profesion; };
    string Cliente::getTipoCliente() { return tipoCliente; };
    float Cliente::getTotalCompras() { return totalCompras; };
    
    void Cliente::setRut(string rut) { this->rut = rut; };
    void Cliente::setProfesion(string profesion) { this->profesion = profesion; };
    void Cliente::setTipoCliente(string tipoCliente) { this->tipoCliente = tipoCliente; };
    void Cliente::setTotalCompras(float totalCompras) { this->totalCompras = totalCompras; };
    
    void Cliente::mostrarDatos() {
        Persona::mostrarDatos();
        cout << left
            << setw(10) << "RUT: " << rut << endl
            << setw(10) << "Profesión: " << profesion << endl
            << setw(10) << "Tipo de Cliente: " << tipoCliente << endl
            << setw(10) << "Total de Compras: " << totalCompras << endl;
        direccion.mostrarDireccion();
    }



#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string rut, profesion, tipoCliente;
    public:
        Cliente(string id, string nombre, string email, int telefono, Direccion& direccion, string rut, string profesion, string tipoCliente):
            Persona(id, nombre, email, telefono, direccion), rut(rut), profesion(profesion), tipoCliente(tipoCliente) {}
        //Getters y Setters
        string getRut(){ return rut; };
        string getProfesion() { return profesion; };
        string getTipoCliente() { return tipoCliente; };
        void setRut(string rut) { this->rut = rut; };
        void setProfesion(string profesion) { this->profesion = profesion; };
        void setTipoCliente(string tipoCliente) { this->tipoCliente = tipoCliente; };
        //Metodo para mostrar los datos completos del cliente
        void mostrarDatos() override {
            Persona::mostrarDatos();
            cout << left 
                << setw(10) << "RUT: " << rut << endl
                << setw(10) << "Profesion: " << profesion << endl
                << setw(10) << "Tipo de Cliente: " << tipoCliente << endl;
        };
};

#endif // CLIENTE_H
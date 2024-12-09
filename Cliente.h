#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string rut; // RUT (Registro Único Tributario) del cliente.
        string profesion; // Profesión u ocupación del cliente.
        string tipoCliente; // Tipo de cliente (ej: regular, VIP, etc.).

    public:
        /**
         * @brief Constructor de la clase Cliente.
         * @param id Identificación única del cliente.
         * @param nombre Nombre completo del cliente.
         * @param email Correo electrónico del cliente.
         * @param telefono Número de teléfono del cliente.
         * @param direccion Referencia a un objeto Direccion con los datos de ubicación.
         * @param rut RUT del cliente.
         * @param profesion Profesión u ocupación del cliente.
         * @param tipoCliente Categoría o tipo de cliente.
         */
        Cliente(string id, string nombre, string email, string telefono, 
                Direccion& direccion, string rut, string profesion, string tipoCliente):
            Persona(id, nombre, email, telefono, direccion), rut(rut), profesion(profesion), tipoCliente(tipoCliente) {}

        // Getters y Setters
        string getRut(){ return rut; };
        string getProfesion() { return profesion; };
        string getTipoCliente() { return tipoCliente; };
        void setRut(string rut) { this->rut = rut; };
        void setProfesion(string profesion) { this->profesion = profesion; };
        void setTipoCliente(string tipoCliente) { this->tipoCliente = tipoCliente; };
        
        /**
         * @brief Muestra los datos completos del cliente.
         * @override Sobrescribe el método mostrarDatos de la clase Persona.
         */
        void mostrarDatos() override {
            Persona::mostrarDatos();
            cout << left 
                << setw(10) << "RUT: " << rut << endl
                << setw(10) << "Profesion: " << profesion << endl
                << setw(10) << "Tipo de Cliente: " << tipoCliente << endl;
        };
};

#endif // CLIENTE_H
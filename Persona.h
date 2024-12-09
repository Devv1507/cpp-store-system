#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Direccion.h"

using namespace std;


class Persona {
    private:
        string id; // Identificación de la persona
        string nombre; // Nombre de la persona
        string email; // Correo electrónico de la persona
        string telefono; // Número de teléfono de la persona
        Direccion direccion; // Objeto de la clase Direccion que contiene la dirección de la persona

        /**
         * @brief Valida que el número de teléfono tenga 10 dígitos.
         * 
         * @param telefono Número de teléfono a validar.
         * @throws invalid_argument Si el número de teléfono no tiene 10 dígitos.
         */
        void validarTelefono(string telefono) {
            if (telefono.length() != 10)
                throw invalid_argument("El número de teléfono debe tener 10 dígitos.");
        }

    public:
        /**
         * @brief Constructor de la clase Persona.
         * 
         * @param id Identificación de la persona.
         * @param nombre Nombre de la persona.
         * @param email Correo electrónico de la persona.
         * @param telefono Número de teléfono de la persona.
         * @param direccion Referencia a un objeto de la clase Direccion.
         */
        Persona(string id, string nombre, string email, string telefono, Direccion& direccion): id(id), nombre(nombre), email(email), direccion(direccion) {
            validarTelefono(telefono); // Valida que el teléfono tenga 10 dígitos
            this->telefono = telefono;
        }

        // Getters y Setters
        string getId() { return id; };
        string getNombre() { return nombre; };
        string getEmail() { return email; };
        string getTelefono() { return telefono; };
        Direccion getDireccion() { return direccion; };
        void setId(string id) { this->id = id; };
        void setNombre(string nombre) { this->nombre = nombre; };
        void setEmail(string email) { this->email = email; };
        void setTelefono(string telefono) {
            validarTelefono(telefono);
            this->telefono = telefono;
        };
        void setDireccion(Direccion direccion) { this->direccion = direccion; };

        /**
         * @brief Muestra los datos completos de la persona.
         * 
         * @details Este método se sobrescribe en las clases hijas.
         */
        virtual void mostrarDatos() {
            cout << left 
                << setw(10) << "id"
                << setw(20) << "nombre"
                << setw(30) << "email"
                << setw(10) << "telefono"
                << endl;
            cout << setw(10) << id
                << setw(20) << nombre
                << setw(30) << email
                << setw(10) << telefono
                << endl;
            direccion.mostrarDireccion();
        }
};

#endif // PERSONA_H
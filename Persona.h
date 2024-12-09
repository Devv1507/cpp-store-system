#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Direccion.h"

using namespace std;


class Persona {
    private:
        string id, nombre, email, telefono;
        Direccion direccion;

        /**
         * @brief Valida que el número de teléfono tenga 10 dígitos.
         * 
         * @param telefono Número de teléfono a validar.
         * @throws invalid_argument Si el número de teléfono no tiene 10 dígitos.
         */
        void validarTelefono(string telefono) {
            if (telefono.length() != 10)
                throw invalid_argument("El numero de telefono debe tener 10 digitos.");
        }

    public:
        /**
         * @brief Constructor.
         * Esta clase representa una persona.
         * A continuación se describen los parámetros necesarios para instanciar un objeto de la clase Persona:
         * @param id Identificación de la persona. E.g, "1234567890".
         * @param nombre Nombre de la persona. E.g, "Juan Perez".
         * @param email Correo electrónico de la persona. E.g, "juan.perez@gmail.com"
         * @param telefono Número de teléfono de la persona. E.g, "3104756821"
         * @param direccion Referencia a un objeto de la clase Direccion.
         */
        Persona(string id, string nombre, string email, string telefono, Direccion& direccion): id(id), nombre(nombre), email(email), direccion(direccion) {
            validarTelefono(telefono); // Valida que el teléfono tenga 10 dígitos
            this->telefono = telefono;
        }

        // Getters
        string getId() { return id; };
        string getNombre() { return nombre; };
        string getEmail() { return email; };
        string getTelefono() { return telefono; };
        Direccion getDireccion() { return direccion; };
        // Setters
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
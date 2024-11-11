#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <iomanip>
#include "Direccion.h"

using namespace std;

class Persona {
    private:
        string id, nombre, email;
        int telefono;
        Direccion direccion;
    public:
        /* 
        * Esta clase representa una superclase persona con los siguientes atributos:
        *   id: identificación de la persona
        *   nombre: nombre de la persona
        *   email: correo electrónico de la persona
        *   telefono: número de teléfono de la persona
        *   direccion: objeto de la clase Direccion que contiene la dirección de la persona
        */
        Persona(string id, string nombre, string email, int telefono, Direccion& direccion): // creo que el paso por referencia ayudaría a evitar problemas de copia
            id(id), nombre(nombre), email(email), telefono(telefono), direccion(direccion) {};
        // Getters y Setters
        string getId() { return id; };
        string getNombre() { return nombre; };
        string getEmail() { return email; };
        int getTelefono() { return telefono; };
        void setId(string id) { this->id = id; };
        void setNombre(string nombre) { this->nombre = nombre; };
        void setEmail(string email) { this->email = email; };
        void setTelefono(int telefono) { this->telefono = telefono; };
        // Este método permite mostrar los datos completos de la persona en cuestión
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
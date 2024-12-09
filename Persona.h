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

        void validarTelefono(string telfono){
            if(telfono.length() != 10)
                throw invalid_argument("El número de telefono debe tener 10 digitos.");
        }

    public:
        /* 
        * Esta clase representa una superclase persona con los siguientes atributos:
        *   id: identificacion de la persona
        *   nombre: nombre de la persona
        *   email: correo electronico de la persona
        *   telefono: numero de telefono de la persona
        *   direccion: objeto de la clase Direccion que contiene la direccion de la persona
        */
        Persona(string id, string nombre, string email, string telefono, Direccion& direccion): id(id), nombre(nombre), email(email), direccion(direccion) {
            validarTelefono(telefono); // Valida que el telefono tenga 10 digitos
            this->telefono = telefono;
            }
        // Getters y Setters
        string getId() { return id; };
        string getNombre() { return nombre; };
        string getEmail() { return email; };
        Direccion getDireccion() { return direccion; };
        string getTelefono() { return telefono; };
        void setId(string id) { this->id = id; };
        void setNombre(string nombre) { this->nombre = nombre; };
        void setEmail(string email) { this->email = email; };
        void setTelefono(string telefono) {
            validarTelefono(telefono); // Lanzará la excepción si no es válido
            this->telefono = telefono;
        }
        // Este metodo permite mostrar los datos completos de la persona en cuestion
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
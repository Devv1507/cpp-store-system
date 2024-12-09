#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string rut; 
        string profesion; 
        string tipoCliente; 
        static vector<Cliente> clientes;

    public:
        /**
         * @brief Constructor de la clase Cliente.
         * Esta clase representa un cliente.
         * 
         * Aqui se describen los parámetros necesarios para instanciar un objeto de la clase Cliente:
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
            Persona(id, nombre, email, telefono, direccion), rut(rut), profesion(profesion), tipoCliente(tipoCliente) {
                if (tipoCliente != "pensionado" && tipoCliente != "empleado publico" && 
                    tipoCliente != "pensionada" && tipoCliente != "empresaria" &&
                    tipoCliente != "empresario" && tipoCliente != "militar") {
                throw invalid_argument("Tipo de cliente no válido. Debe ser 'pensionado', 'empleado publico', 'empresario' o 'militar'.");
                }

                this->tipoCliente = tipoCliente; 
            }

        // Getters y Setters
        string getRut(){ return rut; };
        string getProfesion() { return profesion; };
        string getTipoCliente() { return tipoCliente; };
        void setRut(string rut) { this->rut = rut; };
        void setProfesion(string profesion) { this->profesion = profesion; };
        void setTipoCliente(string tipoCliente) { this->tipoCliente = tipoCliente; };
        static void agregarCliente(const Cliente& cliente) {
            clientes.push_back(cliente);
        };
        
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

        /**
         * @brief Busca un cliente por su identificación.
         * @param idCliente Identificación del cliente a buscar.
         * @return Cliente encontrado o nullptr si no se encuentra.
         */
        static Cliente* buscarCliente(const string& idCliente) {
            for (auto& cliente : clientes) {
                if (cliente.getId() == idCliente) 
                    return &cliente; // Retorna la dirección del cliente encontrado
            }
            return nullptr; // No se encontró el cliente
        }
};

vector<Cliente> Cliente::clientes;

#endif // CLIENTE_H
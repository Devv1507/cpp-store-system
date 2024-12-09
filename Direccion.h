#include <iostream>

using namespace std;

/**
 * @class Direccion
 * @brief Esta clase representa una dirección.
 * 
 * @details La clase Direccion contiene los detalles de una dirección, incluyendo el número, barrio, ciudad y departamento.
 */
class Direccion {
    private:
        string numero; // Número de la dirección
        string barrio; // Barrio de la dirección
        string ciudad; // Ciudad de la dirección
        string departamento; // Departamento de la dirección

        /**
         * @brief Valida que la ciudad sea válida.
         * 
         * @param ciudad Ciudad a validar.
         * @throws invalid_argument Si la ciudad no es válida.
         */
        void validarCiudad(string ciudad) {
            if (ciudad != "Bogota" && ciudad != "Cali") {
                throw invalid_argument("Ciudad no permitida. Solo se permiten 'Bogota' y 'Cali'.");
            }
        }

        /**
         * @brief Valida que el departamento sea válido.
         * 
         * @param departamento Departamento a validar.
         * @throws invalid_argument Si el departamento no es válido.
         */
        void validarDepartamento(string departamento) {
            if (departamento != "Valle del Cauca" && departamento != "Cundinamarca") {
                throw invalid_argument("Departamento no permitido. Solo se permiten 'Valle del Cauca' y 'Cundinamarca'.");
            }
        }
    public:
        /**
         * @brief Constructor de la clase Direccion.
         * 
         * @param numero Número de la dirección.
         * @param barrio Barrio de la dirección.
         * @param ciudad Ciudad de la dirección.
         * @param departamento Departamento de la dirección.
         */
        Direccion(string numero, string barrio, string ciudad, string departamento): numero(numero), barrio(barrio) {
            validarCiudad(ciudad);
            validarDepartamento(departamento);
            this->ciudad = ciudad;
            this->departamento = departamento;
        };

       // Getters y Setters
        string getNumero() { return numero; };
        string getBarrio() { return barrio; };
        string getCiudad() { return ciudad; };
        string getDepartamento() { return departamento; };
        void setNumero(string numero) { this->numero = numero; };
        void setBarrio(string barrio) { this->barrio = barrio; };
        void setCiudad(string ciudad) {
            validarCiudad(ciudad);
            this->ciudad = ciudad;
        };
        void setDepartamento(string departamento) {
            validarDepartamento(departamento);
            this->departamento = departamento;
        };

        /**
         * @brief Muestra los datos completos de la dirección.
         */
        void mostrarDireccion() {
            cout << left
                << "Numero: " << numero << endl
                << "Barrio: " << barrio << endl
                << "Ciudad: " << ciudad << endl
                << "Departamento: " << departamento << endl;
        }
};
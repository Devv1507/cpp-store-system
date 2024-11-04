#include <iostream>

using namespace std;

class Direccion {
    private:
        string numero, barrio, ciudad, departamento;
        // Estos métodos permiten la validación interna de los datos permitidos para ciudad y departamento
        void validarCiudad(string ciudad) {
            if (ciudad != "Cali" && ciudad != "Bogotá") {
                throw invalid_argument("Ciudad no permitida. Solo se permiten 'Cali' y 'Bogotá'.");
            }
        }
        void validarDepartamento(string departamento) {
            if (departamento != "Valle del Cauca" && departamento != "Cundinamarca") {
                throw invalid_argument("Departamento no permitido. Solo se permiten 'Valle del Cauca' y 'Cundinamarca'.");
                // se supone que lo veremos la siguiente semana
            }
        }
    public:
        // Constructor de la clase Direccion, asumiendo que solo existen locales del negocio en Bogota y Cali
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
            if (ciudad == "Bogota" || ciudad == "Cali") {
                this->ciudad = ciudad;
            } else {
                cout << "Ciudad no valida" << endl;
            }
        };
        void setDepartamento(string departamento) {
            if (departamento == "Cundinamarca" || departamento == "Valle del Cauca") {
                this->departamento = departamento;
            } else {
                cout << "Departamento no valido" << endl;
            }
        };
        // Este método permite mostrar los datos completos de la dirección
        void mostrarDireccion() {
            cout << left
                << "Numero: " << numero << endl
                << "Barrio: " << barrio << endl
                << "Ciudad: " << ciudad << endl
                << "Departamento: " << departamento << endl;
        }
};
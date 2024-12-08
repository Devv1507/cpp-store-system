#include <iostream>

using namespace std;

class Direccion {
    private:
        string numero, barrio, ciudad, departamento;
        // Estos metodos permiten la validacion interna de los datos permitidos para ciudad y departamento
        void validarCiudad(string ciudad) {
            if (ciudad != "Cali" && ciudad != "Bogota") {
                throw invalid_argument("Ciudad no permitida. Solo se permiten 'Cali' y 'Bogota'.");
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
            validarCiudad(ciudad);
            this->ciudad = ciudad;
        };
        void setDepartamento(string departamento) {
            validarDepartamento(departamento);
            this->departamento = departamento;
        };
        // Este metodo permite mostrar los datos completos de la direccion
        void mostrarDireccion() {
            cout << left
                << "Numero: " << numero << endl
                << "Barrio: " << barrio << endl
                << "Ciudad: " << ciudad << endl
                << "Departamento: " << departamento << endl;
        }
};
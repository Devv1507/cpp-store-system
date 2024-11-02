#include <iostream>

using namespace std;

class Persona {
    private:
        string nombre;
        string apellido;
        int edad;
    public:
        Persona(string nombre, string apellido, int edad): nombre(nombre), apellido(apellido), edad(edad) {};
};

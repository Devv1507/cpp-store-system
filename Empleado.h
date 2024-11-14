#include <iostream>
#include "Persona.h"
using namespace std;

class Empleado: public Persona {
    private:
        string horario;
        int salario, ventasEmpleadoMes;
    public:
        //constructores
        Empleado(string id, string nombre, string email, int telefono, Direccion& direccion): Persona(id, nombre, email, telefono, direccion), horario(horario), salario(salario), ventasEmpleadoMes(ventasEmpleadoMes) {}
            //getters y setters
            string getHorario(); 
            int getSalario();
            int getVentasEmpleadoMes();
            void setHorario(string horario);
            void setSalario(int salario);
            void setVentasEmpleadoMes(int ventasEmpleadoMes);
            //método para mostrar los datos del empleado
            virtual void mostrarDatos() override {
                Persona::mostrarDatos();
                    cout << left 
                    << setw(10) << "horario"
                    << setw(20) << "salario"
                    << setw(30) << "ventas mes"
                    << endl;
                cout << setw(10) << horario
                    << setw(20) << salario
                    << setw(30) << ventasEmpleadoMes
                    << endl;
                direccion.mostrarDireccion();
            }
            void registrarVenta(int idFactura);
};

    //definición de getters y setters
    string Empleado::getHorario() {return horario; }
    int Empleado::getSalario() {return salario; }
    int Empleado::getVentasEmpleadoMes() {return ventasEmpleadoMes; }
    void Empleado::setHorario(string horario) { this->horario = horario; }
    void Empleado::setSalario(int salario) { this->salario = salario; }
    void Empleado::setVentasEmpleadoMes(int ventasEmpleadoMes) { this->ventasEmpleadoMes = ventasEmpleadoMes; }

    void Empleado::registrarVenta(int idFactura){}
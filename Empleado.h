#include <iostream>
#include <iomanip>
#include "Persona.h"
#include "Caja.h"
#include "Stock.h"

using namespace std;

class Empleado : public Persona {
    private:
        string horario;
        int ventasRealizadas;
        float salario;
    public:
        Empleado(string id, string nombre, string email, int telefono, Direccion& direccion, string horario, float salario, int ventasRealizadas):
            Persona(id, nombre, email, telefono, direccion), horario(horario), salario(salario), ventasRealizadas(0) {}
        //Getters y Setters
        float getSalario() { return salario; };
        string getHorario() { return horario; };
        int getVentasRealizadas() { return ventasRealizadas; };
        void setSalario(float salario) { this->salario = salario; };
        void setHorario(string horario) { this->horario = horario; };
        void setVentasRealizadas(int ventasRealizadas) { this->ventasRealizadas = ventasRealizadas; };

        // Registrar una venta usando la clase Caja
        void registrarVenta(Caja &caja, Factura &factura) {
            caja.agregarFactura(factura);
            ventasRealizadas++;
        }

        // Manejar el inventario usando la clase Stock
        void gestionarInventario(Stock &stock, string idProducto, int cantidad, string tipoOperacion) {
            stock.modificarExistencias(idProducto, cantidad, tipoOperacion);
        }

        // Mostrar información del empleado
        void mostrarInfo() {
            Persona::mostrarDatos();
            cout << left 
                << setw(10) << "Horario: " << horario << endl
                << setw(10) << "Salario: " << salario << endl
                << setw(10) << "Ventas Realizadas: " << ventasRealizadas << endl;
        }
};  
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
        /**
         * @brief Constructor de la clase Empleado.
         * 
         * Para instanciar un objeto de la clase Empleado se requieren los siguientes parámetros:
         * @param id Identificación del empleado.
         * @param nombre Nombre del empleado.
         * @param email Correo electrónico del empleado.
         * @param telefono Teléfono del empleado.
         * @param direccion Referencia a un objeto de la clase Direccion.
         * @param horario Horario de trabajo del empleado.
         * @param salario Salario del empleado.
         * @param ventasRealizadas Número de ventas realizadas por el empleado.
         */
        Empleado(string id, string nombre, string email, string telefono, Direccion& direccion, string horario, float salario, int ventasRealizadas):
            Persona(id, nombre, email, telefono, direccion), horario(horario), salario(salario), ventasRealizadas(0) {}

        //Getters y Setters
        float getSalario() { return salario; };
        string getHorario() { return horario; };
        int getVentasRealizadas() { return ventasRealizadas; };
        void setSalario(float salario) { this->salario = salario; };
        void setHorario(string horario) { this->horario = horario; };
        void setVentasRealizadas(int ventasRealizadas) { this->ventasRealizadas = ventasRealizadas; };

        /**
         * @brief Registra una venta usando la clase Caja.
         * 
         * @param caja Referencia a un objeto de la clase Caja.
         * @param factura Referencia a un objeto de la clase Factura.
         */
        void registrarVenta(Caja &caja, Factura &factura) {
            caja.agregarFactura(factura);
            ventasRealizadas++;
        }

        /**
         * @brief Maneja el inventario usando la clase Stock.
         * 
         * @param stock Referencia a un objeto de la clase Stock.
         * @param idProducto Identificación del producto.
         * @param cantidad Cantidad del producto.
         * @param tipoOperacion Tipo de operación a realizar (e.g., "agregar", "eliminar").
         */
        void gestionarInventario(Stock &stock, string idProducto, int cantidad, string tipoOperacion) {
            stock.modificarExistencias(idProducto, cantidad, tipoOperacion);
        }

        /**
         * @brief Muestra los datos completos del empleado.
         */
        void mostrarDatos() override {
            Persona::mostrarDatos();
            cout << left 
                << setw(10) << "Horario: " << horario << endl
                << setw(10) << "Salario: " << salario << endl
                << setw(10) << "Ventas Realizadas: " << ventasRealizadas << endl;
        }
};  
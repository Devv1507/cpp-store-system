#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Producto {
    private:
        static int contadorProductos; // Contador estático para generar IDs únicos
        string idProducto; // Identificador único del producto
        string nombreProducto; // Nombre del producto
        float precioUnitario; // Precio unitario del producto

        /**
         * @brief Método para generar un identificador único basado en un contador.
         * 
         * @return string Identificador único generado.
         */
        string generarIdProducto() {
            stringstream ss;
            ss << "P-" << setw(2) << setfill('0') << contadorProductos++;
            return ss.str();
        };
    public:
        /**
         * @brief Constructor de la clase Producto.
         * 
         * @param nombreProducto Nombre del producto.
         * @param precioUnitario Precio unitario del producto.
         */
        Producto(string nombreProducto, float precioUnitario):
            idProducto(generarIdProducto()), nombreProducto(nombreProducto), precioUnitario(precioUnitario) {};

        // Getters y Setters
        string getIdProducto() const { return idProducto; };
        string getNombreProducto() { return nombreProducto; };
        float getPrecioUnitario() { return precioUnitario; };
        void setIdProducto(string idProducto) { this->idProducto = idProducto; };
        void setNombreProducto(string nombreProducto) { this->nombreProducto = nombreProducto; };
        void setPrecioUnitario(float precioUnitario) { this->precioUnitario = precioUnitario; };

        /**
         * @brief Método para mostrar los datos acerca de un producto.
         */
        virtual void mostrarDatos() {
            cout << left 
                << setw(10) << "ID Producto"
                << setw(20) << "Nombre"
                << setw(10) << "Valor Unitario"
                << endl;
            cout << left 
                << setw(10) << idProducto
                << setw(20) << nombreProducto
                << setw(10) << precioUnitario
                << endl;
        }
};

#endif // PRODUCTO_H
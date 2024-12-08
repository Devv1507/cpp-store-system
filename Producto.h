#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Producto {
    private:
        static int contadorProductos;
        string idProducto, nombreProducto, idMarca;
        float precioUnitario;
        // Método para generar un identificador único basado en un contador
        string generarIdProducto() {
            stringstream ss;
            ss << "P-" << setw(2) << setfill('0') << contadorProductos++;
            return ss.str();
        };
    public:
        Producto(string nombreProducto, float precioUnitario):
            idProducto(generarIdProducto()), nombreProducto(nombreProducto), precioUnitario(precioUnitario) {};
        // Getters y Setters
        string getIdProducto() const { return idProducto; };
        string getNombreProducto() { return nombreProducto; };
        string getIdMarca() { return idMarca; };
        float getPrecioUnitario() { return precioUnitario; };
        void setIdProducto(string idProducto) { this->idProducto = idProducto; };
        void setNombreProducto(string nombreProducto) { this->nombreProducto = nombreProducto; };
        void setIdMarca(string idMarca) { this->idMarca = idMarca; };
        void setPrecioUnitario(float precioUnitario) { this->precioUnitario = precioUnitario; };
        //método para mostrar los datos acerca de un producto
        virtual void mostrarDatos() {
            cout << left 
            << setw(10) << "id producto"
            << setw(20) << "nombre"
            << setw(10) << "valor unitario"
            << setw(10) << "id marca"
            << endl;
            cout << setw(10) << idProducto
            << setw(20) << nombreProducto
            << setw(10) << precioUnitario
            << setw(10) << idMarca
            << endl;
        }
};

#endif // PRODUCTO_H
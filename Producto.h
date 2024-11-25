#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Producto {
    private:
        string idProducto, nombreProducto;
        float precioUnitario;
        int idMarca;
    public:
        Producto(string idProducto, string nombreProducto, int idMarca, float precioUnitario):
            idProducto(idProducto), nombreProducto(nombreProducto), idMarca(idMarca), precioUnitario(precioUnitario) {};
        // Getters y Setters
        string getIdProducto() { return idProducto; };
        string getNombreProducto() { return nombreProducto; };
        int getIdMarca() { return idMarca; };
        float getPrecioUnitario() { return precioUnitario; };
        void setIdProducto(string idProducto) { this->idProducto = idProducto; };
        void setNombreProducto(string nombreProducto) { this->nombreProducto = nombreProducto; };
        void setIdMarca(int idMarca) { this->idMarca = idMarca; };
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
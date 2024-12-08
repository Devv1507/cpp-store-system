#ifndef MARCA_H
#define MARCA_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Stock.h"
#include "Producto.h"
using namespace std;

class Marca {
    private:
        static int contadorMarcas; // Contador estatico para generar IDs unicos
        string idMarca, nombreMarca;
        vector<Producto> listarProductos; //vector para guardar los productos de una marca
        // Metodo para generar un identificador unico basado en un contador
        string generarIdMarca() {
            stringstream ss;
            ss << "M-" << setw(2) << setfill('0') << contadorMarcas++;
            return ss.str();
        };
    public:
        // Constructor
        Marca(string nombreMarca): 
            idMarca(generarIdMarca()), nombreMarca(nombreMarca) {}
        // Getters y setters
        string getIdMarca() { return idMarca; };
        string getNombreMarca() { return nombreMarca; };
        void setIdMarca(string idMarca) { this->idMarca = idMarca; };
        void setNombreMarca(string nombreMarca) { this->nombreMarca = nombreMarca; };
        /************************************************ Metodos especificos ************************************************/
        // Metodo para agregar un producto a una marca
        void agregarProducto(const Producto& producto) {
            listarProductos.push_back(producto);
        };
        // Metodo para mostrar todos los productos de una misma marca
        void mostrarProductos() {
            cout << "Productos de la marca " << nombreMarca << ":" << endl;
            for (size_t i = 0; i < listarProductos.size(); i++) {
                listarProductos[i].mostrarDatos();
            }
        };

        // Declaracion de la sobrecarga del operador << como funcion amiga
        friend ostream& operator<<(ostream& os, const Marca& marca);
};

#endif // MARCA_H
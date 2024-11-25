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
        static int contadorMarcas; // Contador estático para generar IDs únicos
        string idMarca, nombreMarca;
        vector<Producto> listarProductos; //vector para guardar los productos de una marca
        // Método para generar un identificador único basado en un contador
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
        /************************************************ Métodos específicos ************************************************/
        // Método para agregar un producto a una marca
        void agregarProducto(const Producto& producto) {
            listarProductos.push_back(producto);
        };
        // Método para mostrar todos los productos de una misma marca
        void mostrarProductos() {
            cout << "Productos de la marca " << nombreMarca << ":" << endl;
            for (size_t i = 0; i < listarProductos.size(); i++) {
                listarProductos[i].mostrarDatos();
            }
        };

        // Declaración de la sobrecarga del operador << como función amiga
        friend ostream& operator<<(ostream& os, const Marca& marca);
};

#endif // MARCA_H
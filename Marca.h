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
        string idMarca; // Identificador único de la marca
        string nombreMarca; // Nombre de la marca
        vector<Producto> listarProductos; // Vector para guardar los productos de una marca

        /**
         * @brief Método para generar un identificador único basado en un contador.
         * 
         * @return string Identificador único generado.
         */
        string generarIdMarca() {
            stringstream ss;
            ss << "M-" << setw(2) << setfill('0') << contadorMarcas++;
            return ss.str();
        };
    public:
        /**
         * @brief Constructor de la clase Marca.
         * 
         * @param nombreMarca Nombre de la marca.
         */
        Marca(string nombreMarca): 
            idMarca(generarIdMarca()), nombreMarca(nombreMarca) {}

        // Getters y setters
        string getIdMarca() { return idMarca; };
        string getNombreMarca() { return nombreMarca; };
        void setIdMarca(string idMarca) { this->idMarca = idMarca; };
        void setNombreMarca(string nombreMarca) { this->nombreMarca = nombreMarca; };

        /************************************************ Métodos específicos ************************************************/
        
        /**
         * @brief Método para agregar un producto a una marca.
         * 
         * @param producto Referencia a un objeto de la clase Producto.
         */
        void agregarProducto(Producto& producto) {
            listarProductos.push_back(producto);
        };

        /**
         * @brief Método para obtener la lista de productos de la marca.
         * 
         * @return vector<Producto> Lista de productos de la marca.
         */
        vector<Producto> getListarProductos() {
            return listarProductos;
        }

        // Declaracion de la sobrecarga del operador << como funcion amiga
        friend ostream& operator<<(ostream& os, const Marca& marca);
};

#endif // MARCA_H
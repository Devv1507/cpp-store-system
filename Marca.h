#ifndef MARCA_H
#define MARCA_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Marca {
    private:
        static int contadorMarcas; 
        string idMarca; 
        string nombreMarca; 
        int ventasDeMarca;
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
         * El siguiente parámetro es necesario para instanciar un objeto de la clase Marca:
         * @param nombreMarca Nombre de la marca.
         */
        Marca(string nombreMarca): 
            idMarca(generarIdMarca()), nombreMarca(nombreMarca), ventasDeMarca(0) {}
        // Getters y setters
        string getIdMarca() { return idMarca; };
        string getNombreMarca() { return nombreMarca; };
        void setIdMarca(string idMarca) { this->idMarca = idMarca; };
        void setNombreMarca(string nombreMarca) { this->nombreMarca = nombreMarca; };

        /************************************************ Métodos específicos ************************************************/
        /**
         * @brief para incrementar las ventas totales de una marca.
         * @param cantidad: cantidad de productos vendidos
         */
        void incrementarVentas(int cantidad) {
            ventasDeMarca += cantidad;
        };

        /**
         * @brief para obtener la cantidad de productos vendidos de una marca.
         * @return  Cantidad de productos vendidos de la marca.
         */
        int getVentasDeMarca() { return ventasDeMarca; };
};

#endif // MARCA_H
#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Stock {
    private:
        string idStock;            // Identificador del stock
        vector<Producto> productos; // Vector para almacenar los productos
        vector<int> existencias;    // Vector para almacenar la cantidad por producto
        vector<int> stockMinimos;   // Vector para almacenar el stock minimo por producto

    public:
        /**
         * @brief Constructor de la clase Stock.
         * 
         * @param idStock Identificador del stock.
         * @throws invalid_argument Si el identificador del stock está vacío.
         */
        Stock(string idStock) {
            if (idStock.empty()) {
            throw invalid_argument("El nombre del almacen no puede estar vacio.");
            }
            this->idStock = idStock;
        };

        // Getters y Setters
        string getIdStock() { return idStock; };
        void setIdStock(string idStock) {
            if (idStock.empty()) {
                throw invalid_argument("El nombre del almacen no puede estar vacio.");
            }
            this->idStock = idStock;
         };

        /************************************************ Metodos especificos ************************************************/
        /**
         * @brief Agrega un producto al stock.
         * 
         * @param producto Referencia a un objeto de la clase Producto.
         * @param cantidad Cantidad del producto a agregar.
         * @param stockMinimo Stock mínimo del producto.
         */
        void anadirProducto(const Producto& producto, int cantidad, int stockMinimo) {
            // Validar si el ID del producto ya existe
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].getIdProducto() == producto.getIdProducto()) {
                throw invalid_argument("Error: Ya existe un producto con el ID '" + producto.getIdProducto() + "'.");
                }
            }
            
            productos.push_back(producto);
            existencias.push_back(cantidad);
            stockMinimos.push_back(stockMinimo);
        };

        /**
         * @brief Edita la información de un producto en el stock.
         * 
         * @param idProducto Identificador del producto.
         * @param nuevoNombre Nuevo nombre del producto.
         * @param nuevoPrecio Nuevo precio del producto.
         * @throws invalid_argument Si el producto no se encuentra en el stock.
         */  
        void editarProducto(string idProducto, string nuevoNombre, float nuevoPrecio) {
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].getIdProducto() == idProducto) {
                    productos[i].setNombreProducto(nuevoNombre);
                    productos[i].setPrecioUnitario(nuevoPrecio);
                    cout << "Producto actualizado correctamente." << endl;
                    return;
                }
            }
            cout << "Producto no encontrado." << endl;
        };

        /**
         * @brief Busca el índice de un producto en el stock.
         * 
         * @param idProducto Identificador del producto.
         * @return int Índice del producto en el vector de productos, o -1 si no se encuentra.
         */
        int buscarIndiceProducto(const string& idProducto) {
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].getIdProducto() == idProducto) {
                    return i;
                }
            }
            return -1; // Producto no encontrado
        };

        /**
         * @brief Obtiene el precio unitario de un producto.
         * 
         * @param idProducto Identificador del producto.
         * @return float Precio unitario del producto.
         */
        int getExistenciasProducto(string& idProducto) {
            int index = buscarIndiceProducto(idProducto);
            return existencias[index];
        };

        /**
         * @brief Obtiene el precio unitario de un producto.
         * 
         * @param idProducto Identificador del producto.
         * @return float Precio unitario del producto.
         */
        void modificarExistencias(const string& idProducto, int cantidad, const string& tipoFactura) {
            int index = buscarIndiceProducto(idProducto);
            if (index == -1) {
                cout << "Producto no encontrado en el inventario." << endl;
                return;
            }

            if (tipoFactura == "venta") {
                if (existencias[index] >= cantidad) {
                    existencias[index] -= cantidad;
                    cout << "Producto vendido: " << cantidad << " unidades." << endl;
                } else {
                    cout << "Stock insuficiente para la venta." << endl;
                }
            } else if (tipoFactura == "compra") {
                existencias[index] += cantidad;
                cout << "Producto añadido al inventario: " << cantidad << " unidades." << endl;
            }
            verificarStockMinimo(index);
        };

        /**
         * @brief Verifica el stock mínimo de un producto.
         * 
         * @param index Índice del producto en el vector de productos.
         */
        void verificarStockMinimo(int index) {
            if (existencias[index] < stockMinimos[index]) {
                cout << "Alerta: El producto con ID '" << productos[index].getIdProducto()
                    << "' tiene un stock bajo: " << existencias[index]
                    << " unidades, minimo requerido: " << stockMinimos[index] << " unidades." << endl;
            }
        };

        /** 
         * @brief Verifica si un producto está disponible en el stock.
         * 
         * @param producto Referencia a un objeto de la clase Producto.
         * @param cantidad Cantidad del producto a verificar.
         * @return bool True si el producto está disponible, False en caso contrario.
        */
        bool productoDisponible(Producto &producto, int cantidad) {
            // Buscar el indice del producto
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].getIdProducto() == producto.getIdProducto()) {
                    // Verificar si hay suficiente stock
                    return existencias[i] >= cantidad;
                }
            }
            // Si no se encuentra el producto
            return false;
        };

        /**
         * @brief Muestra el inventario del stock.
         */
        void mostrarInventario() {
            cout << "Inventario del almacen general:" << idStock << endl;
            for (size_t i = 0; i < productos.size(); ++i) {
                cout << left
                    << "ID Producto: " << setw(10) << productos[i].getIdProducto()
                    << "Nombre: " << setw(20) << productos[i].getNombreProducto()
                    << "Precio: " << setw(10) << productos[i].getPrecioUnitario()
                    << "Cantidad: " << setw(10) << existencias[i]
                    << "Stock Minimo: " << stockMinimos[i]
                    << endl;
            }
        };
    };
#endif // STOCK_H
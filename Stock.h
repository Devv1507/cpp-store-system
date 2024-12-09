#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "Marca.h"
#include "Producto.h"

using namespace std;

class Stock {
    private:
        string idStock;
        vector<Producto> productos;
        vector<Marca> marcas;
        vector<int> existencias;    
        vector<int> stockMinimos;   

    public:
        /**
         * @brief Constructor de la clase Stock.
         * 
         * Se necesita el siguiente parámetro para instanciar un objeto de la clase Stock:
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
        vector<Producto> getProductos() { return productos; };
        vector<Marca> getMarcas() { return marcas; };
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
        void anadirProducto(Producto& producto, int cantidad, int stockMinimo) {
            // Validar si el ID del producto ya existe
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].getIdProducto() == producto.getIdProducto()) {
                throw invalid_argument("Error: Ya existe un producto con el ID '" + producto.getIdProducto() + "'.");
                }
            }
            
            productos.push_back(producto);
            Marca& marcaParticular = producto.getMarcaAsociada();
            bool marcaExiste = false;

            
            for (Marca& marca : marcas) {
                if (marca.getNombreMarca() == marcaParticular.getNombreMarca()) {
                    marca.incrementarVentas(cantidad);
                    marcaExiste = true;
                    break;
                }
            }

            // Si la marca no existía, agregarla
            if (!marcaExiste) {
                marcas.push_back(marcaParticular);
                marcas.back().incrementarVentas(cantidad);
            }

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
         * @brief Metodo para obtener una marca por su nombre.
         * 
         * @param nombreMarca Nombre de la marca a buscar.
         * @return Marca encontrada.
         * @throws runtime_error Si la marca no existe.
         */
        Marca obtenerMarcaPorNombre(string nombreMarca) {
            for (Marca& marca : marcas) {
                cout << "Marca: " << marca.getNombreMarca() << endl;
                cout << "Nombre introducido: " << nombreMarca << endl;
                if (marca.getNombreMarca() == nombreMarca) {
                    return marca;
                }
            }
            throw runtime_error("La marca no existe: " + nombreMarca);
        };

        /**
         * @brief Muestra el inventario del stock.
         */
        void mostrarInventario() {
            cout << "\nInventario del almacen: " << idStock << endl;
            cout << left
                    << setw(15) << "ID Producto" 
                    << setw(25) << "Nombre" 
                    << setw(10) << "Precio" 
                    << setw(10) << "Cantidad" 
                    << setw(10) << "Stock Minimo"<< endl;
            cout << string(75, '-') << endl;
            for (size_t i = 0; i < productos.size(); ++i) {
                cout << left
                    << setw(15) << productos[i].getIdProducto()
                    << setw(25) << productos[i].getNombreProducto()
                    << setw(10) << productos[i].getPrecioUnitario()
                    << setw(10) << existencias[i]
                    << setw(10) << stockMinimos[i] << endl;
            }
        };
    };
#endif // STOCK_H
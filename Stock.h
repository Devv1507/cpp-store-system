#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Stock {
    private:
        string idStock;
        vector<Producto> productos;
        vector<int> existencias;    // Vector para almacenar la cantidad por producto
        vector<int> stockMinimos;   // Vector para almacenar el stock mínimo por producto

    public:
        // Constructor
        Stock(string idStock) {
            if (idStock.empty()) {
            throw invalid_argument("El nombre del almacén no puede estar vacío.");
            }
            this->idStock = idStock;
        };

        // Getters y Setters
        string getIdStock() { return idStock; };
        void setIdStock(string idStock) {
            if (idStock.empty()) {
                throw invalid_argument("El nombre del almacén no puede estar vacío.");
            }
            this->idStock = idStock;
         };

        /************************************************ Métodos específicos ************************************************/
        // Método para añadir un producto al inventario
        void anadirProducto(const Producto& producto, int cantidad, int stockMinimo) {
            productos.push_back(producto);
            existencias.push_back(cantidad);
            stockMinimos.push_back(stockMinimo);
        };

        // Método para editar un producto existente
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

        // Método para buscar el índice de un producto por su ID
        int buscarIndiceProducto(const string& idProducto) {
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].getIdProducto() == idProducto) {
                    return i;
                }
            }
            return -1; // Producto no encontrado
        };

        // Método para obtener las existencias de un producto 
        int getExistenciasProducto(string& idProducto) {
            int index = buscarIndiceProducto(idProducto);
            return existencias[index];
        };

        // Método para modificar existencias (usado al comprar o vender)
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

        // Método para verificar si un producto está por debajo del stock mínimo
        void verificarStockMinimo(int index) {
            if (existencias[index] < stockMinimos[index]) {
                cout << "Alerta: El producto con ID '" << productos[index].getIdProducto()
                    << "' tiene un stock bajo: " << existencias[index]
                    << " unidades, mínimo requerido: " << stockMinimos[index] << " unidades." << endl;
            }
        };

        // Método para mostrar todos los productos
        void mostrarInventario() {
            cout << "Inventario del almacén general:" << idStock << endl;
            for (size_t i = 0; i < productos.size(); ++i) {
                cout << left
                    << "ID: " << setw(10) << productos[i].getIdProducto()
                    << "Nombre: " << setw(20) << productos[i].getNombreProducto()
                    << "Precio: " << setw(10) << productos[i].getPrecioUnitario()
                    << "Cantidad: " << setw(10) << existencias[i]
                    << "Stock Mínimo: " << stockMinimos[i]
                    << endl;
            }
        };
    };
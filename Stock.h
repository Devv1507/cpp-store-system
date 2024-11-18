#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Stock {
private:
    static int contadorStocks;
    string idStock;
    vector<Producto> productos;

    // Método para generar un identificador único basado en un contador
    string generarIdStock() {
        stringstream stringstream;
        stringstream << "F-" << setw(2) << setfill('0') << contadorStocks++;
        return stringstream.str();
    };
public:
    // Constructor
    Stock():
        idStock(generarIdStock()) {};

    // Método para añadir un producto al inventario
    void anadirProducto(const Producto& producto) {
        productos.push_back(producto);
    }

    // Método para editar un producto existente
    void editarProducto(string idProducto, string nuevoNombre, float nuevoPrecio) {
        for (auto &producto : productos) {
            if (producto.getIdProducto() == idProducto) {
                producto.setNombreProducto(nuevoNombre);
                producto.setPrecioUnitario(nuevoPrecio);
                cout << "Producto actualizado correctamente." << endl;
                return;
            }
        }
        cout << "Producto no encontrado." << endl;
    }

    // Método para buscar un producto por su ID
    Producto* buscarProducto(string idProducto) {
        for (auto &producto : productos) {
            if (producto.getIdProducto() == idProducto) {
                return &producto;
            }
        }
        return nullptr;
    }

    // Método para modificar existencias (usado al comprar o vender)
    void modificarExistencias(string idProducto, int cantidad, string tipoFactura) {
        Producto* producto = buscarProducto(idProducto);
        if (producto) {
            if (tipoFactura == "venta") {
                // Lógica de venta
                cout << "Producto vendido: " << cantidad << " unidades." << endl;
            } else if (tipoFactura == "compra") {
                // Lógica de compra
                cout << "Producto añadido al inventario: " << cantidad << " unidades." << endl;
            }
        } else {
            cout << "Producto no encontrado en el inventario." << endl;
        }
    }

    // Método para mostrar todos los productos
    void mostrarInventario() {
        cout << "Inventario actual:" << endl;
        for (const auto &producto : productos) {
            cout << "ID: " << producto.getIdProducto() << " - Nombre: " << producto.getNombreProducto() << " - Precio: " << producto.getPrecioUnitario() << endl;
        }
    }
};
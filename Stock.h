#include  <iostream>
#include <vector>
#include "Producto.h"

using namespace std;

class Stock {
    private:
        vector <Producto> productos;
        int id, existencias, stockMinimo;
    public:
        Stock(int id, int existencias, int stockMinimo): 
            id(id), existencias(existencias), stockMinimo(stockMinimo) {}
        //Getters
        int getId();

        int getExistencias();
        int getStockMinimo();
        //Setters
        void setId(int id);
        void setExistencias(int existencias);
        void setStockMinimo(int stockMinimo);   
        //Métodos
        void añadirProducto(Producto producto) {
            productos.push_back(producto);
            cout << "Producto añadido al stock." << endl;
        };
        void eliminarProducto();
        void editarProducto();
        void buscarProducto();
        void modificarExistencias(int cantidad, string tipoFactura);
        void productosPorAgotarse();
};

  /*   int Stock::getId() { return id; }
    string Stock::getExistencias() { return existencias; }
    int Stock::getStockMinimo() { return stockMinimo; }

    void Stock::setId(int id) { this->id = id; }
    void Stock::setExistencias(string existencias) { this->existencias = existencias; }
    void Stock::setStockMinimo(int stockMinimo) { this->stockMinimo = stockMinimo; }

    void Stock::añadirProducto(int cantidad) {
        existencias += cantidad;
        cout << "Se añadieron " << cantidad << " productos al stock." << endl;
    }

    void Stock::eliminarProducto(int cantidad) {
        if (existencias >= cantidad) {
            existencias -= cantidad;
            cout << "Se eliminaron " << cantidad << " productos del stock." << endl;
        } else {
            cout << "No hay suficientes productos en el stock." << endl;
        }
    }

    bool Stock::productosPorAgotarse() {
        return existencias < stockMinimo;
    }

    void Stock::modificarExistencias(int cantidad, string tipoFactura) {
        if (tipoFactura == "compra") {
            añadirProducto(cantidad);
            cout << "Compra registrada. Cantidad restante: " << existencias << endl;
        } else if (tipoFactura == "venta") {
            eliminarProducto(cantidad);
            cout << "Venta registrada. Cantidad restante: " << existencias << endl;
        } else {
            cout << "Tipo de factura inválido." << endl;
        }
    }

    void Stock::mostrarProductosPorAgotarse(vector<Stock>& stocks) {
        bool encontrado = false;
        cout << "Productos con existencias menores al stock mínimo:" << endl;
        for (Stock& stock : stocks) {
            if (stock.productosPorAgotarse()) {
                cout << "Producto: " << stock.getNombreProducto() 
                    << ", Marca: " << stock.getProductoMarca() 
                    << ", Existencias: " << stock.getExistencias() 
                    << ", Stock Mínimo: " << stock.getStockMinimo() << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No hay productos con existencias menores al stock mínimo." << endl;
        }
    } */
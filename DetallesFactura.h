#include <iostream>
#include "Producto.h"

using namespace std;

class DetallesFactura {
    private:
        Producto producto;
        int cantidad;
        float subtotalProducto;
    public:
        /** Esta clase representa los detalles de una factura, con los siguientes atributos:
         *      producto: objeto de la clase Producto que contiene los datos del producto
         *      cantidad: cantidad de productos comprados
         *      subtotalProducto: valor total de la compra de un producto
         */
        DetallesFactura(Producto &producto, int cantidad): producto(producto), cantidad(cantidad) {
            calcularSubtotal();
        };
        // Getters y Setters
        int getCantidad() { return cantidad; }
        float getSubtotalProducto() { return subtotalProducto; }
        // Métodos específicos
        void calcularSubtotal() {
            float precioProducto = producto.getPrecioUnitario();
            subtotalProducto = precioProducto * cantidad;
            this->subtotalProducto = subtotalProducto;
        };
        // Este método permite imprimir el detalle particular
        void mostrarDetalle() {
            cout << "Producto: " << producto.getNombreProducto()
             << ", Cantidad: " << cantidad
             << ", Subtotal: $" << subtotalProducto << endl;
        };
};

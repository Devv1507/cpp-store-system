#include <iostream>
#include <iomanip>
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
            validarCantidad();
            calcularSubtotal();
        };
        // Getters y Setters
        int getCantidad() { return cantidad; };
        float getSubtotalProducto() { return subtotalProducto; };
        Producto getProducto() const { return producto; };
        void setCantidad(int cantidad) {
            this->cantidad = cantidad;
            validarCantidad();
            calcularSubtotal();
        };
        void setSubtotalProducto(float subtotal) { this->subtotalProducto = subtotal; };
        /************************************************ Métodos específicos ************************************************/
        // Este método permite validar que la cantidad de productos sea positiva y mayor a 0
        void validarCantidad() {
            if (cantidad <= 0) {
                throw invalid_argument("La cantidad de productos debe ser mayor a 0.");
            }
        };
        // Este método permite calcular el subtotal de la compra de un producto
        void calcularSubtotal() {
            float precioProducto = producto.getPrecioUnitario();
            this->subtotalProducto = precioProducto * cantidad;
        };
        // Este método permite imprimir el detalle particular
        void mostrarDetalle() {
            cout << "Producto: " << producto.getNombreProducto()
            << ", Cantidad: " << cantidad
            << ", Subtotal: $" << setprecision(2) << subtotalProducto << endl;
        };
};

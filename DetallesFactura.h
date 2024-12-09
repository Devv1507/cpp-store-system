#include <iostream>
#include <iomanip>
#include "Producto.h"

using namespace std;


class DetallesFactura {
    private:
        Producto producto; // Objeto de la clase Producto que contiene los datos del producto
        int cantidad; // Cantidad de productos comprados
        float subtotalProducto; // Valor total de la compra de un producto

        /**
         * @brief Valida que la cantidad de productos sea positiva y mayor a 0.
         */
        void validarCantidad() {
            if (cantidad <= 0) {
                throw invalid_argument("La cantidad de productos debe ser mayor a 0.");
            }
        };

        /**
         * @brief Calcula el subtotal de la compra de un producto.
         */
        void calcularSubtotal() {
            float precioProducto = producto.getPrecioUnitario();
            this->subtotalProducto = precioProducto * cantidad;
        };
    public:
        /**
         * @brief Constructor de la clase DetallesFactura.
         * @param producto Referencia a un objeto de la clase Producto.
         * @param cantidad Cantidad de productos comprados.
         */
        DetallesFactura(Producto &producto, int cantidad): producto(producto), cantidad(cantidad) {
            validarCantidad();
            calcularSubtotal();
        };
        
        // Getters
        int getCantidad() { return cantidad; };
        float getSubtotalProducto() { return subtotalProducto; };
        Producto getProducto() const { return producto; };

        // Setters
        void setCantidad(int cantidad) {
            this->cantidad = cantidad;
            validarCantidad();
            calcularSubtotal();
        };
        void setSubtotalProducto(float subtotal) { this->subtotalProducto = subtotal; };

        /**
         * @brief Imprime el detalle particular.
         */
        void mostrarDetalle() {
            cout << "Producto: " << producto.getNombreProducto()
            << ", Cantidad: " << cantidad
            << ", Subtotal: $" << subtotalProducto << endl;
        };
};

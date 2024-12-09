#include <iostream>
#include <iomanip>
#include "Producto.h"

using namespace std;


class DetallesFactura {
    private:
        Producto producto; 
        int cantidad; 
        float subtotalProducto; 

        /**
         * @brief Valida que la cantidad de productos sea positiva y mayor a 0.
         * @throws invalid_argument Si la cantidad es menor o igual a 0.
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
         * Esta clase representa los detalles de una factura.
         * 
         * Se requieren los siguientes parámetros para instanciar un objeto de la clase DetallesFactura:
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
            << ", Subtotal: $" << fixed << setprecision(2) << subtotalProducto << endl;
        };
};

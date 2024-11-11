#include <iostream>
#include <iomanip>
#include <vector>
#include "DetallesFactura.h"

using namespace std;

class Factura {
    private:
        string fechaFactura, horaFactura, tipoVenta;
        string idFactura, idCliente, idProveedor;
        vector<DetallesFactura> detallesFactura;
        float totalFactura;
    public:
    /**
     * Esta clase representa una factura con los siguientes atributos:
     *      idFactura: identificación de la factura
     *      fechaFactura: fecha de la factura
     *      horaFactura: hora de la factura
     *      tipoVenta: tipo de venta (compra o venta)
     *      idCliente: identificación del cliente
     *      idProveedor: identificación del proveedor
     *      totalFactura: valor total de la factura
     *      detallesFactura: vector que contiene los detalles de la factura
     */
        Factura(string idFactura, string tipoVenta, string horaFactura, string fechaFactura):
            idFactura(idFactura), tipoVenta(tipoVenta), fechaFactura(fechaFactura), horaFactura(horaFactura), totalFactura(0) {
            if (tipoVenta == "compra") {
                cout << "Ingrese el id del proveedor: ";
                cin >> idProveedor;
            } else if (tipoVenta == "venta") {
                cout << "Ingrese el id del cliente: ";
                cin >> idCliente;
            }
        };
        // Getters y Setters
        string getIdFactura() { return idFactura; };
        string getFechaFactura() { return fechaFactura; };
        string getHoraFactura() { return horaFactura; };
        string getTipoVenta() { return tipoVenta; };
        string getIdCliente() { return idCliente; };
        string getIdProveedor() { return idProveedor; };
        float getTotalFactura() { return totalFactura; };
        void setIdFactura(string idFactura) { this->idFactura = idFactura; };
        void setFechaFactura(string fechaFactura) { this->fechaFactura = fechaFactura; };
        void setHoraFactura(string horaFactura) { this->horaFactura = horaFactura; };
        void setTipoVenta(string tipoVenta, string idEntidad) {
            this->tipoVenta = tipoVenta;
            if (tipoVenta == "compra") {
                this->idProveedor = idEntidad;
            } else if (tipoVenta == "venta") {
                this->idCliente = idEntidad;
            }
        };
        void setIdCliente(string idCliente) { this->idCliente = idCliente; };
        void setIdProveedor(string idProveedor) { this->idProveedor = idProveedor; };
        void setTotalFactura(float totalFactura) { this->totalFactura = totalFactura; };
        /************************************************************ Métodos específicos ****************/
        // Este método permite agregar un detalle a la factura
        void agregarDetalle(Producto &producto, int cantidad) {
            DetallesFactura detalle(producto, cantidad);
            detallesFactura.push_back(detalle);
            totalFactura += detalle.getSubtotalProducto();
        };
        // Este método permite calcular el total de la factura considerando todos los detalles de la misma
        float calcularTotalFactura() {
            return totalFactura;
        };
        // Este método permite filtrar por tipo de venta
        string getFacturaPorTipo(string tipoVenta) {
            if (this->tipoVenta == tipoVenta) {
                return idFactura;
            }
        }
        // Este método permite mostrar los datos completos de la factura
        void mostrarDatos() {
            cout << "Factura ID: " << idFactura << ", Fecha: " << fechaFactura
                 << ", Hora: " << horaFactura << ", Tipo: " << tipoVenta
                 << ", Total: $" << setprecision(2) << totalFactura << endl;

            if (tipoVenta == "venta" && !idCliente.empty()) {
                cout << "Cliente ID: " << idCliente << endl;
            } else if (tipoVenta == "compra" && !idProveedor.empty()) {
                cout << "Proveedor ID: " << idProveedor << endl;
            }

            cout << "--- Detalles de la Factura ---" << endl;
            for (size_t i = 0; i < detallesFactura.size(); ++i) {
                detallesFactura[i].mostrarDetalle();
            }
        };
};
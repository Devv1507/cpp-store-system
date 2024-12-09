#ifndef CAJA_H
#define CAJA_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "Factura.h"

using namespace std;

class Caja {
    private:
        static int contadorCajas; 
        string idCaja; 
        int numeroFacturasDia; 
        vector<Factura> facturas; 
        Stock* stock;

        /**
         * @brief Genera un identificador único basado en un contador.
         * @return Identificador único de la caja.
         */

        string generarIdCaja() {
            stringstream ss;
            ss << "C-" << setw(2) << setfill('0') << contadorCajas++;
            return ss.str();
        };
    public:
        /**
         * @brief Constructor de la clase Caja. 
         * Se necesita el siguiente parametro para la creacion instanciar un objeto de la clase Caja:
         * 
         * @param stock Puntero al stock asociado a la caja.
         */
        Caja(Stock* stock): idCaja(generarIdCaja()), numeroFacturasDia(0), stock(stock) {};

        // Getters y Setters
        string getIdCaja() { return idCaja; };
        int getNumeroFacturasDia() { return numeroFacturasDia; };
        vector<Factura> getFacturas() { return facturas; };
        Stock* getStock() { return stock; };
        void setIdCaja(string idCaja) { this->idCaja = idCaja; };
        /************************************************ Metodos especificos ************************************************/
        /**
         * @brief Registra una transacción en la caja.
         */
        void registrarTransaccion(Factura& factura) {
            string tipoTransaccion = factura.getTipoVenta();
        
            // Procesar los detalles de la factura
            for (DetallesFactura& detalle : factura.getDetallesFactura()) {
                Producto producto = detalle.getProducto();
                int cantidad = detalle.getCantidad();

                if (tipoTransaccion == "venta") {
                    // Validar existencia suficiente en el stock
                    if (!stock->productoDisponible(producto, cantidad)) {
                        throw invalid_argument("No hay suficiente stock para el producto: " + producto.getNombreProducto());
                    }
                }

                // Actualizar existencias en el stock
                stock->modificarExistencias(producto.getIdProducto(), cantidad, tipoTransaccion);

                // Si es una venta, actualizar estadísticas de la marca
                if (tipoTransaccion == "venta") {
                    Marca marca = producto.getMarcaAsociada();
                    marca.incrementarVentas(cantidad);
                }
            }

            // Agregar la factura a la lista de facturas de la caja
            agregarFactura(factura);

            // Incrementar el contador de facturas diarias
            numeroFacturasDia++;

            // Mostrar un mensaje de confirmación
            string transaccion = (tipoTransaccion == "venta") ? "Venta" : "Compra";
            cout << transaccion << " registrada exitosamente. Total: $"
                << fixed << setprecision(2) << factura.getTotalFactura() << endl; 
        };

        /**
         * @brief Agrega una factura a la caja.
         * @param factura Factura a agregar.
         */
        void agregarFactura(Factura factura) {
            facturas.push_back(factura);
            numeroFacturasDia++;
        };

        /**
         * @brief Obtiene el mes de una fecha.
         * @param fecha Fecha en formato YYYY-MM-DD.
         * @return Mes de la fecha.
         */
        int obtenerMes(const string &fecha) {
            return stoi(fecha.substr(5, 2)); // asume el formato YYYY-MM-DD
        };

        /**
         * @brief Calcula el total de ventas mensuales.
         * @param mes Mes para el cual se calculan las ventas.
         * @return Total de ventas del mes.
         */
        float calcularTotalVentasMensuales(int mes) {
            float totalVentas = 0;
            for (size_t i = 0; i < facturas.size(); i++) {
                if (obtenerMes(facturas[i].getFechaFactura()) == mes && facturas[i].getTipoVenta() == "venta") {
                    totalVentas += facturas[i].getTotalFactura();
                }
            }
            return totalVentas;
        };

        /**
         * @brief Muestra la información de las facturas almacenadas.
        */
        void mostrarFacturas() {
            cout << string(75, '-') << endl;
            cout << "\nFacturas registradas para la caja " << idCaja << ": " << endl;
            for (size_t i = 0; i < facturas.size(); i++) {
                cout << "\nFactura " << i + 1 << endl;
                facturas[i].mostrarDatos();
            }
            cout << string(75, '-') << endl;
        };

        /**
         * @brief Lista las facturas por tipo de venta.
         * @param tipoFactura Tipo de venta (compra o venta).
         */
        void listarFacturasPorTipo(string tipoFactura) {
            cout << "--- Facturas del tipo: " << tipoFactura << " ---" << endl;
            for (size_t i = 0; i < facturas.size(); i++) {
                if (facturas[i].getTipoVenta() == tipoFactura) {
                    cout << "Factura " << i + 1 << endl;
                    facturas[i].mostrarDatos();
                }
            }
        };

        /**
        * @brief Muestra la cantidad y el valor total de las facturas de venta y compra, y calcula las ganancias.
        */
        void mostrarResumenFacturas() {
            int cantidadVentas = 0, cantidadCompras = 0;
            float totalVentas = 0.0, totalCompras = 0.0;

            // Iterar sobre las facturas y acumular totales según el tipo
            for (Factura& factura : facturas) {
                if (factura.getTipoVenta() == "venta") {
                    cantidadVentas++;
                    totalVentas += factura.getTotalFactura();
                } else if (factura.getTipoVenta() == "compra") {
                    cantidadCompras++;
                    totalCompras += factura.getTotalFactura();
                }
            }

            // Mostrar resumen
            cout << "\n     Resumen de Facturas:    \n";
            cout << string(75, '-') << endl;
            cout << "Ventas:\n";
            cout << " - Cantidad de facturas: " << cantidadVentas << endl;
            cout << " - Total de ventas: $" << fixed << setprecision(2) << totalVentas << endl;
            cout << "\nCompras:\n";
            cout << " - Cantidad de facturas: " << cantidadCompras << endl;
            cout << " - Total de compras: $" << fixed << setprecision(2) << totalCompras << endl;

            // Calcular y mostrar ganancias
            float ganancias = totalVentas - totalCompras;
            cout << "\nGanancias totales: $" << fixed << setprecision(2) << ganancias << endl;
        };
};

#endif // CAJA_H
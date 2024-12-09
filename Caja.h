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
        static int contadorCajas; // Contador estatico para generar IDs unicos
        string idCaja; // Identificación de la caja.
        int numeroFacturasDia; // Número de facturas registradas en el día.
        vector<Factura> facturas; // Vector de facturas registradas en la caja.
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
         */
        Caja(Stock* stock): idCaja(generarIdCaja()), numeroFacturasDia(0), stock(stock) {};
        // Getters y Setters
        string getIdCaja() { return idCaja; };
        int getNumeroFacturasDia() { return numeroFacturasDia; };
        vector<Factura> getFacturas() { return facturas; };
        Stock* getStock() { return stock; };
        void setIdCaja(string idCaja) { this->idCaja = idCaja; };
        /************************************************ Metodos especificos ************************************************/
        
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
         * @brief Abre la caja para iniciar operaciones diarias.
         */
        void abrirCaja() {
            numeroFacturasDia = 0;
            // Initialize daily operations
        };
        
        /**
         * @brief Cierra la caja y calcula el total de ventas del día.
         */
        void cerrarCaja() {
            // Calcular el total de las ventas del dia
            float totalDiario = 0;
            for (Factura &factura : facturas) {
                if (factura.getTipoVenta() == "venta") {
                    totalDiario += factura.getTotalFactura();
                }
            }

            // Mostrar el total diario
            cout << "Caja cerrada. Total de ventas del dia: $" << fixed << setprecision(2) << totalDiario << endl;

            // TO_DO: Aca podria haber mas logica, como guardar el total en un archivo, un reporte, etc.
            numeroFacturasDia = 0;
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
            for (size_t i = 0; i < facturas.size(); i++) {
                cout << "Factura " << i + 1 << endl;
                facturas[i].mostrarDatos();
            }
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
};

#endif // CAJA_H
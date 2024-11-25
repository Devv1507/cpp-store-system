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
        static int contadorCajas; // Contador estático para generar IDs únicos
        string idCaja;
        int numeroFacturasDia;
        vector<Factura> facturas;

        // Método para generar un identificador único basado en un contador
        string generarIdCaja() {
            stringstream ss;
            ss << "C-" << setw(2) << setfill('0') << contadorCajas++;
            return ss.str();
        };
    public:
        // Constructor
        Caja(): idCaja(generarIdCaja()), numeroFacturasDia(0) {};
        // Getters y Setters
        string getIdCaja() { return idCaja; };
        int getNumeroFacturasDia() { return numeroFacturasDia; };
        vector<Factura> getFacturas() { return facturas; };
        void setIdCaja(string idCaja) { this->idCaja = idCaja; };
        /************************************************ Métodos específicos ************************************************/
        void abrirCaja() {
            numeroFacturasDia = 0;
            // Initialize daily operations
        }
        
        void cerrarCaja() {
            // Calcular el total de las ventas del día
            float totalDiario = 0;
            for (Factura &factura : facturas) {
                if (factura.getTipoVenta() == "venta") {
                    totalDiario += factura.getTotalFactura();
                }
            }

            // Mostrar el total diario
            cout << "Caja cerrada. Total de ventas del día: $" << fixed << setprecision(2) << totalDiario << endl;

            // TO_DO: Acá podría haber más lógica, como guardar el total en un archivo, un reporte, etc.
            numeroFacturasDia = 0;
        }

        // Este método permite agregar una factura a la caja
        void agregarFactura(Factura factura) {
            facturas.push_back(factura);
            numeroFacturasDia++;
        };

         // Método auxiliar para obtener el mes
        int obtenerMes(const string &fecha) {
            return stoi(fecha.substr(5, 2)); // asume el formato YYYY-MM-DD
        };

        // Este método permite calcular el total de ventas mensuales
        float calcularTotalVentasMensuales(int mes) {
            float totalVentas = 0;
            for (size_t i = 0; i < facturas.size(); i++) {
                if (obtenerMes(facturas[i].getFechaFactura()) == mes && facturas[i].getTipoVenta() == "venta") {
                    totalVentas += facturas[i].getTotalFactura();
                }
            }
            return totalVentas;
        };

        // Este método permite imprimir la información de las facturas almacenadas
        void mostrarFacturas() {
            for (size_t i = 0; i < facturas.size(); i++) {
                cout << "Factura " << i + 1 << endl;
                facturas[i].mostrarDatos();
            }
        };

        // Este método permite listar las facturas por tipo de venta
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
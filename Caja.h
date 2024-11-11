#include <iostream>
#include <vector>
#include <string>
#include "Factura.h"

using namespace std;

class Caja {
    private:
        vector<Factura> facturas;
        string idVenta;
        int numeroFacturasDia;
    public:
        Caja(string idVenta): idVenta(idVenta), numeroFacturasDia(0) {};
        void agregarFactura(Factura factura) {
            facturas.push_back(factura);
            numeroFacturasDia++;
        };
        // Getters y Setters
        string getIdVenta() { return idVenta; };
        int getNumeroFacturasDia() { return numeroFacturasDia; };
        void setIdVenta(string idVenta) { this->idVenta = idVenta; };
        void setNumeroFacturasDia(int numeroFacturasDia) { this->numeroFacturasDia = numeroFacturasDia; };
        /************************************************************ Métodos específicos ****************/
         // Método auxiliar para obtener el mes
        int obtenerMes(const string &fecha) {
            return stoi(fecha.substr(5, 2)); // asume el formato YYYY-MM-DD
        };
        // Este método permite calcular el total de ventas mensuales
        float calcularTotalVentasMensuales(int mes) {
            float totalVentas = 0;
            for (size_t i = 0; i < facturas.size(); i++) {
                if (obtenerMes(facturas[i].getFechaFactura()) == mes && facturas[i].getTipoVenta() == "venta") {
                    totalVentas += facturas[i].calcularTotalFactura();
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
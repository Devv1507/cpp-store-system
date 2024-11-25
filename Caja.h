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
            stringstream stringstream;
            stringstream << "C-" << setw(2) << setfill('0') << contadorCajas++;
            return stringstream.str();
        };
    public:
        // Constructor
        Caja(): idCaja(generarIdCaja()), numeroFacturasDia(0) {};
        // Getters y Setters
        string getIdCaja() { return idCaja; };
        int getNumeroFacturasDia() { return numeroFacturasDia; };
        void setIdCaja(string idCaja) { this->idCaja = idCaja; };
        void setNumeroFacturasDia(int numeroFacturasDia) { this->numeroFacturasDia = numeroFacturasDia; };
        /************************************************ Métodos específicos ************************************************/
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
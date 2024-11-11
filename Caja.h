#include <iostream>
#include <vector>
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
        // Métodos espcíficos
        void mostrarFacturas() {
            for (int i = 0; i < facturas.size(); i++) {
                cout << "Factura " << i + 1 << endl;
                facturas[i].mostrarDatos();
            }
        };
        void listarFacturasPorTipo(string tipoFactura) {
            for (int i = 0; i < facturas.size(); i++) {
                if (facturas[i].getTipoVenta() == tipoFactura) {
                    cout << "Factura " << i + 1 << endl;
                    facturas[i].mostrarDatos();
                }
            }
        };


};
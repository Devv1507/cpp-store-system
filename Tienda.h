#include <algorithm> // Se implementa esta libreria para usar max_element
#include <iostream>
#include <unordered_map> // Se implementa esta libreria para usar unordered_map
#include <vector>
#include "Caja.h"
#include "Cliente.h"
using namespace std;

class Tienda {
    // TO_DO: revisar si es necesario definir alguna clase Mes o Dia para manejar este tipo de datos
    // ["Enero", "Febrero", Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre]
    private:
        vector<Caja> cajas; // Arreglo de cajas de la tienda
        unordered_map<string, float> totalComprasPorCliente; // Mapa para almacenar clientes por ID
        vector<float> ventasPorMes = vector<float>(12, 0); // Vector para almacenar las ventas por mes. Se inicializa con 12 elementos en 0
    public:
        // Constructor
        Tienda() {};
        /************************************************ Métodos específicos ************************************************/
        // Método para agregar una caja a la tienda
        void agregarCaja(Caja caja) {
            cajas.push_back(caja);
        };
        // Método para definir el mes con mayor ventas
        string mesMayorVenta() {
            for (size_t i = 0; i < cajas.size(); i++) {
                for (int j = 1; j <= 12; j++) {
                    ventasPorMes[j - 1] += cajas[i].calcularTotalVentasMensuales(j);
                }
            }
            int mesMayor = distance(ventasPorMes.begin(), max_element(ventasPorMes.begin(), ventasPorMes.end())); //se utiliza para encontrar el índice del elemento con el valor máximo en el vector ventasPorMes.
            return obtenerNombreMes(mesMayor + 1);
        };

        string obtenerNombreMes(int mes) { // Método auxiliar para obtener el nombre del mes
            static const char* nombresMes[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
            return nombresMes[mes - 1];
        };

        // Método para calcular el total de compras de un cliente
        void calcularTotalComprasPorCliente() {
            for (Caja& caja : cajas) {
                for (Factura& factura : caja.getFacturas()) {
                    int idCliente = factura.getClienteId();
                    totalComprasPorCliente[idCliente] += factura.getTotalFactura();
                }
            }
        };
        
        string tresMejoresClientes() {
            // Verificar que hay datos en el mapa
            if (totalComprasPorCliente.empty()) {
                cout << "No hay datos de clientes disponibles." << endl;
                return;
            }

            // Convertir el mapa en un vector para ordenar
            vector<pair<string, float>> comprasPorCliente(totalComprasPorCliente.begin(), totalComprasPorCliente.end());

            // Ordenar el vector en orden descendente por el total de compras
            sort(comprasPorCliente.begin(), comprasPorCliente.end(),
                [](const pair<string, float>& a, const pair<string, float>& b) {
                    return a.second > b.second; // Orden descendente por valor
                });

            // Mostrar los tres mejores clientes
            cout << "Los tres mejores clientes son:" << endl;
            for (size_t i = 0; i < comprasPorCliente.size() && i < 3; ++i) {
                string idCliente = comprasPorCliente[i].first;
                float totalCompras = comprasPorCliente[i].second;
                cout << "Cliente ID: " << idCliente << ", Total Compras: $" << totalCompras << endl;
            }
        };
    
        void empleadoDelMes() {
            /* Necesitamos iterar sobre las cajas, probablemente
            Necesitamos pensar en una forma de usar el contador ventasRealizadas que tiene cada empleado para definir el empleado del mes*/
        };
        void marcaMasVendida() {
            // Necesitamos iterar sobre todas las cajas, y encontrar una forma de definir las ventasPorMarca. Será necesario algún método adicional en Factura o DetallesFactura?
        };
}; 
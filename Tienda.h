#include <iostream>
#include <vector>
#include <algorithm> // Se implementa esta libreria para usar max_element
#include <string>
#include <map>
#include "Caja.h"
#include "Cliente.h"
using namespace std;

class Tienda {
    // TO_DO: revisar si es necesario definir alguna clase Mes o Dia para manejar este tipo de datos
    // ["Enero", "Febrero", Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre]
    private:
        vector<Caja> cajas; // Arreglo de cajas de la tienda
        vector<float> ventasPorMes = vector<float>(12, 0); // Vector para almacenar las ventas por mes. Se inicializa con 12 elementos en 0
        vector<float> ventasPorCliente; // Vector para almacenar las ventas por cliente
        vector<Cliente> clientes;
    public:
        // Constructor
        Tienda() {};
        // Método para agregar una caja a la tienda
        void agregarCaja(Caja caja) {
            cajas.push_back(caja);
        };
        
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
        }
        
        string tresMejoresClientes(){
            /*Se necesita iterar sobre todas las cajas y sus facturas para calcular las ventas mensuales. 
            La caja ya tiene un método caja.calcularTotalVentasMensuales(mes) que retorna el total de ventas de un mes. 
            A partir de eso, se necesita encontrar el mes con mayor ventas. Finalmente, se necesita devolver el nobmre del mes con mayor ventas*/
            return "";
        };
    
        void empleadoDelMes() {
            /* Necesitamos iterar sobre las cajas, probablemente
            Necesitamos pensar en una forma de usar el contador ventasRealizadas que tiene cada empleado para definir el empleado del mes*/
        };
        void marcaMasVendida() {
            // Necesitamos iterar sobre todas las cajas, y encontrar una forma de definir las ventasPorMarca. Será necesario algún método adicional en Factura o DetallesFactura?
        };
}; 
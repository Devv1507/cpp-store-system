#include <iostream>
#include "Caja.h"

using namespace std;

class Tienda {
    // TO_DO: revisar si es necesario definir alguna clase Mes o Dia para manejar este tipo de datos
    // ["Enero", "Febrero", Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre]
    private:
        vector<Caja> cajas; // Arreglo de cajas de la tienda
        vector<int> ventasPorMes; // Vector para almacenar las ventas por mes
        vector<float> ventasPorCliente; // Vector para almacenar las ventas por cliente
    public:
        // Constructor
        Tienda() {};
        // Método para agregar una caja a la tienda
        void agregarCaja(Caja caja) {
            cajas.push_back(caja);
        };
        string mesMayorVenta() {
            // Se necesita iterar sobre todas las cajas y sus facturas para calcular las ventas mensuales
            // la caja ya tiene un método caja.calcularTotalVentasMensuales(mes) que retorna el total de ventas de un mes
            // a partir de eso, se necesita encontrar el mes con mayor ventas
            // finalmente, se necesita devolver el nobmre del mes con mayor ventas
            
        };
        void tresMejoresClientes() {
            // Necesitamos iterar sobre todas las cajas y sus facturas de venta, i.e. factura[i].getFacturaPorTipo("venta")
            // Y a partir de eso se necesita definir utilizar el vector de ventasPorCliente para almacenar las ventas de de forma separada para cliente, ventasPorCliente[factura.getIdCliente] += factura[i].getTotalFactura()
            // Finalmente, se necesita encontrar los tres clientes con mayores ventas y mostrar sus datos
        };
        void empleadoDelMes() {
            // Necesitamos iterar sobre las cajas, probablemente
            // Necesitamos pensar en una forma de usar el contador ventasRealizadas que tiene cada empleado para definir el empleado del mes
        };
        void marcaMasVendida() {
            // Necesitamos iterar sobre todas las cajas, y encontrar una forma de definir las ventasPorMarca. Será necesario algún método adicional en Factura o DetallesFactura?
        };
};
#ifndef TIENDA_H
#define TIENDA_H

#include <algorithm> // Se implementa esta libreria para usar max_element
#include <iostream>
#include <unordered_map> // Se implementa esta libreria para usar unordered_map
#include <vector>
#include "Caja.h"
#include "Cliente.h"
#include "Empleado.h"

using namespace std;

class Tienda {
    private:
        string nombre;
        vector<Caja> cajas; 
        vector<Empleado> empleados; 
        unordered_map<string, float> totalComprasPorCliente;
        unordered_map<string, float> conteoPorProveedor;
        vector<float> ventasPorMes = vector<float>(12, 0);
    public:
        /**
         * @brief Constructor de la clase Tienda.
         * 
         * Solo necesita el nombre de la tienda para instanciar un objeto de la clase Tienda.
         * @param nombre Nombre de la tienda.
         */
        Tienda(string nombre): nombre(nombre) {};

        // Getters y Setters
        string getNombre() { return nombre; };
        void setNombre(string nombre) { this->nombre = nombre; };
        vector<Caja> getCajas() { return cajas; };
        /************************************************ Metodos especificos ************************************************/
        /**
         * @brief Agrega una caja a la tienda.
         * @param caja Caja a agregar.
         */
        void agregarCaja(Caja caja) {
            cajas.push_back(caja);
        };

        /**
         * @brief Agrega un empleado a la tienda.
         * @param empleado Empleado a agregar.
         */
        void agregarEmpleado(Empleado empleado) {
            empleados.push_back(empleado);
        };

        /**
         * @brief Define el mes con mayor ventas.
         * @return Nombre del mes con mayor ventas.
         */
        string mesMayorVenta() {
            for (size_t i = 0; i < cajas.size(); i++) {
                for (int j = 1; j <= 12; j++) {
                    ventasPorMes[j - 1] += cajas[i].calcularTotalVentasMensuales(j);
                }
            }
            int mesMayor = distance(ventasPorMes.begin(), max_element(ventasPorMes.begin(), ventasPorMes.end())); //se utiliza para encontrar el indice del elemento con el valor maximo en el vector ventasPorMes.
            return obtenerNombreMes(mesMayor + 1);
        };

        /**
         * @brief Obtiene el nombre del mes.
         * @param mes Número del mes (1-12).
         * @return Nombre del mes.
         */
        string obtenerNombreMes(int mes) { // Metodo auxiliar para obtener el nombre del mes
            static const char* nombresMes[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
            return nombresMes[mes - 1];
        };

        /**
         * @brief Calcula el total de compras de un cliente.
         */
        void calcularTotalComprasPorCliente() {
            for (Caja& caja : cajas) {
                for (Factura& factura : caja.getFacturas()) {
                    string idCliente = factura.getIdCliente();
                    totalComprasPorCliente[idCliente] += factura.getTotalFactura();
                }
            }
        };
        
        /**
         * @brief Muestra la información de los tres mejores clientes (aquellos con mayor total de compras).
         */        
        void tresMejoresClientes() {
            // Actualizar el mapa de total de compras por cliente
            calcularTotalComprasPorCliente();
            // Verificar si hay datos en el mapa
            if (totalComprasPorCliente.empty()) {
                string mensajeFallo = "No hay datos de clientes disponibles.";
                cout << mensajeFallo << endl;
            }

            // Convertir el mapa en un vector para ordenar
            vector<pair<string, float>> comprasPorCliente(totalComprasPorCliente.begin(), totalComprasPorCliente.end());

            // Ordenar el vector en orden descendente por el total de compras
            sort(comprasPorCliente.begin(), comprasPorCliente.end(),
                [](const pair<string, float>& a, const pair<string, float>& b) {
                    return a.second > b.second; // Orden descendente por valor
            });

            // Mostrar los tres mejores clientes
            string resultado = "Los tres mejores clientes son:\n";
            for (size_t i = 0; i < comprasPorCliente.size() && i < 3; ++i) {
                string idCliente = comprasPorCliente[i].first;
                float totalCompras = comprasPorCliente[i].second;
                ostringstream streamTotalCompras;
                streamTotalCompras << fixed << setprecision(2) << totalCompras;
                // Concatenar al resultado
                resultado += "Cliente ID: " + idCliente + ", Total Compras: $" + streamTotalCompras.str() + "\n";
                }
            cout << resultado << endl;
        };
    
        /**
         * @brief Obtiene el empleado del mes.
         * @return Nombre del empleado del mes.
         */
        string empleadoDelMes() {
            // Verificar si la tienda tiene empleados
            if (empleados.empty()) {
                return "No hay empleados registrados.";
            }

            // Inicializamos el empleado del mes con el primer empleado
            Empleado empleadoDelMes = empleados[0];

            // Iterar sobre los empleados para encontrar al que mas ventas ha realizado
            for (size_t i = 1; i < empleados.size(); ++i) {
                if (empleados[i].getVentasRealizadas() > empleadoDelMes.getVentasRealizadas()) {
                    empleadoDelMes = empleados[i];
                }
            }

            // Mostrar el nombre o el id del empleado del mes
            return "Empleado del mes: " + empleadoDelMes.getNombre();
        };

        /**
         * @brief Obtiene la marca más vendida de la tienda.
         */
        void marcaMasVendida() {
            // Verificar si hay marcas registradas
            if (cajas.empty()) {
                throw runtime_error("No hay cajas registradas en la tienda.");
            }

            vector<Marca> marcas = cajas[0].getStock()->getMarcas();

            // Verificar si hay marcas registradas
            if (marcas.empty()) {
                throw runtime_error("No hay marcas registradas en la tienda.");
            }
        
            // Inicializar variables para encontrar la marca más vendida
            Marca marcaMasVendida = marcas[0];
            int ventasMaximas = marcaMasVendida.getVentasDeMarca();

            // Iterar sobre las marcas para determinar la más vendida
            for (Marca& marca : marcas) {
                cout << "A ver: " << marca.getVentasDeMarca() << endl;
                cout << "Nombre " << marca.getNombreMarca() << endl;
                if (marca.getVentasDeMarca() > ventasMaximas) {
                    ventasMaximas = marca.getVentasDeMarca();
                    marcaMasVendida = marca;
                }
            }

            // Imprimir resultados
            cout << "La marca mas vendida es: " << marcaMasVendida.getNombreMarca() << endl;
            cout << "Productos vendidos de esta marca: " << ventasMaximas << endl;
        };

        /**
        * @brief Muestra la cantidad de facturas de compra por cada proveedor.
        */
        void mostrarCantidadFacturasPorProveedor() {
            for (Caja& caja : cajas) {
                for (Factura& factura : caja.getFacturas()) {
                    if (factura.getIdProveedor() != "") {
                        string idProveedor = factura.getIdProveedor();

                        if (conteoPorProveedor.find(idProveedor) == conteoPorProveedor.end()) {
                            conteoPorProveedor[idProveedor] = 1;
                        } else {
                            conteoPorProveedor[idProveedor]++;
                        }
                    }
                }
            }

            // Mostrar el resultado
            cout << "\nCantidad de facturas de compra por proveedor:" << endl;
            for (const auto& par : conteoPorProveedor) {
                cout << "Proveedor ID: " << par.first << ", Facturas: " << par.second << endl;
            }
        };
};

#endif // TIENDA_H
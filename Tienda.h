#ifndef TIENDA_H
#define TIENDA_H

#include <algorithm> // Se implementa esta libreria para usar max_element
#include <iostream>
#include <unordered_map> // Se implementa esta libreria para usar unordered_map
#include <vector>
#include "Caja.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Marca.h"

using namespace std;

class Tienda {
    string nombre;
    // TO_DO: revisar si es necesario definir alguna clase Mes o Dia para manejar este tipo de datos
    // ["Enero", "Febrero", Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre]
    private:
        vector<Caja> cajas; // Arreglo de cajas de la tienda
        vector<Empleado> empleados; // Arreglo de empleados de la tienda
        vector<Marca> marcas; // Arreglo de marcas de la tienda
        unordered_map<string, float> totalComprasPorCliente; // Mapa para almacenar clientes por ID
        unordered_map<string, int> ventasPorMarca; // Mapa para acumular las ventas por marca
        unordered_map<string, Marca*> productoAMarca; // Relación producto -> marca
        vector<float> ventasPorMes = vector<float>(12, 0); // Vector para almacenar las ventas por mes. Se inicializa con 12 elementos en 0
    public:
        // Constructor
        Tienda(string nombre): nombre(nombre) {};
        string getNombre() { return nombre; };
        void setNombre(string nombre) { this->nombre = nombre; };
        /************************************************ Metodos especificos ************************************************/
        // Metodo para agregar una caja a la tienda
        void agregarCaja(Caja caja) {
            cajas.push_back(caja);
        };
        // Metodo para agregar un empleado a la tienda
        void agregarEmpleado(Empleado empleado) {
            empleados.push_back(empleado);
        };
        // Metodo para agregar una marca a la tienda
        void agregarMarca(Marca marca) {
            marcas.push_back(marca);
        };
        // Metodo para definir el mes con mayor ventas
        string mesMayorVenta() {
            for (size_t i = 0; i < cajas.size(); i++) {
                for (int j = 1; j <= 12; j++) {
                    ventasPorMes[j - 1] += cajas[i].calcularTotalVentasMensuales(j);
                }
            }
            int mesMayor = distance(ventasPorMes.begin(), max_element(ventasPorMes.begin(), ventasPorMes.end())); //se utiliza para encontrar el indice del elemento con el valor maximo en el vector ventasPorMes.
            return obtenerNombreMes(mesMayor + 1);
        };

        string obtenerNombreMes(int mes) { // Metodo auxiliar para obtener el nombre del mes
            static const char* nombresMes[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
            return nombresMes[mes - 1];
        };

        // Metodo para calcular el total de compras de un cliente
        void calcularTotalComprasPorCliente() {
            for (Caja& caja : cajas) {
                for (Factura& factura : caja.getFacturas()) {
                    string idCliente = factura.getIdCliente();
                    totalComprasPorCliente[idCliente] += factura.getTotalFactura();
                }
            }
        };

        void registrarProductoEnMarca(Producto& producto, Marca& marca) {
            marca.agregarProducto(producto); // Asocia el producto con la marca
            productoAMarca[producto.getIdProducto()] = &marca; // Almacena la relación
        };

        Marca* obtenerMarcaDeProducto(const Producto& producto) {
            auto it = productoAMarca.find(producto.getIdProducto());
            if (it != productoAMarca.end()) {
                return it->second;
            }
            return nullptr;
        };
        
        // Metodo para obtener los tres mejores clientes, depende del mapa totalComprasPorCliente
        string tresMejoresClientes() {
            // Actualizar el mapa de total de compras por cliente
            calcularTotalComprasPorCliente();
            // Verificar si hay datos en el mapa
            if (totalComprasPorCliente.empty()) {
                string mensajeFallo = "No hay datos de clientes disponibles.";
                return mensajeFallo;
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
            string resultado = "Los tres mejores clientes son:\n";
            for (size_t i = 0; i < comprasPorCliente.size() && i < 3; ++i) {
                string idCliente = comprasPorCliente[i].first;
                float totalCompras = comprasPorCliente[i].second;
                resultado += "Cliente ID: " + idCliente + ", Total Compras: $" + to_string(totalCompras) + "\n";
            }
            return resultado;
        };
    
        // Metodo para obtener el empleado del mes
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

        // Metodo para obtener la marca mas vendida de la tienda, depende del mapa ventasPorMarca
        Marca marcaMasVendida() {
            // Verificar si hay marcas registradas
            if (marcas.empty()) {
                throw runtime_error("No hay marcas registradas en la tienda.");
            }
    
            // Recorrer todas las cajas y sus facturas
            for (Caja caja : cajas) {
                const auto& facturas = caja.getFacturas();
    
                for (Factura factura : facturas) {
                    const auto& detallesFactura = factura.getDetallesFactura();
    
                    for (DetallesFactura detalle : detallesFactura) {
                        Producto producto = detalle.getProducto();
                        Marca* marca = obtenerMarcaDeProducto(producto);
    
                        if (marca) {
                            ventasPorMarca[marca->getIdMarca()] += detalle.getCantidad();
                        }
                    }
                }
            }
    
            // Encontrar la marca con más ventas
            string idMarcaMasVendida;
            int maxVentas = 0;
    
            for (const auto& venta : ventasPorMarca) {
                if (venta.second > maxVentas) {
                    maxVentas = venta.second;
                    idMarcaMasVendida = venta.first;
                }
            }
    
            // Buscar la marca correspondiente
            for (Marca marca : marcas) {
                if (marca.getIdMarca() == idMarcaMasVendida) {
                    return marca;
                }
            }
            throw runtime_error("No se pudo determinar la marca más vendida.");
    }
};
#endif // TIENDA_H
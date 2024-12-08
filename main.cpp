/**
 * Programa principal para la gestión de un comercio electrónico
 * Este main.cpp representa un CLI para interactuar con el sistema de gestión de un comercio electrónico.
 * 
 * Autores:
 *  - David Esteban Valencia Valencia   -   2415092
 *  - Jeremy Andres Astaiza             -   2420580
 *  - Juan Pablo Escamilla              -   2415667
 *  - Nicolle Andrea Paz                -   2419714
 * 
 * Fecha de entrega: 08 de diciembre de 2024
 * Tecnología en Desarrollo de Software (2724)
 * Universidad del Valle
 */


#include <iostream>
#include <vector>
#include <limits>
#include "Tienda.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Marca.h"

using namespace std;

// Definición de la sobrecarga del operador << para Marca
ostream& operator<<(ostream& os, const Marca& marca) {
    os << "ID: " << marca.idMarca << ", Nombre: " << marca.nombreMarca;
    return os;
}

// Variables globales para mantener el estado del programa
Stock stockGeneral("STOCK-01");
Tienda tienda("SuperTech");
vector<Cliente> clientes;
vector<Proveedor> proveedores;
vector<Caja> cajas;
int Caja::contadorCajas = 1;
int Marca::contadorMarcas = 1;

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    cout << "\n=== Bienvenid@ al CLI del sistema de gestión del comercio electrónico " << tienda.getNombre() << " ===\n";
    cout << "1. Gestión de Stock\n";
    cout << "2. Gestión de Cajas\n";
    cout << "3. Gestión de Clientes\n";
    cout << "4. Gestión de Proveedores\n";
    cout << "5. Informes\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";
}

// Función para el menú de gestión de stock
void gestionStock() {
    while (true) {
        cout << "\n************************* GESTIÓN DE STOCK *************************\n";
        cout << "1. Agregar producto\n";
        cout << "2. Editar producto\n";
        cout << "3. Mostrar inventario\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                string id, nombre, idMarca;
                int cantidad, stockMinimo;
                float precio;
                
                cout << "ID del producto: ";
                cin >> id;
                cin.ignore();
                cout << "Nombre del producto: ";
                getline(cin, nombre);
                cout << "ID de la marca del producto: ";
                cin >> idMarca;
                cin.ignore();
                cout << "Precio unitario: ";
                cin >> precio;
                cout << "Cantidad inicial: ";
                cin >> cantidad;
                cout << "Stock mínimo: ";
                cin >> stockMinimo;

                Producto nuevoProducto(id, nombre, idMarca, precio);
                stockGeneral.anadirProducto(nuevoProducto, cantidad, stockMinimo);
                cout << "Producto agregado exitosamente.\n";
                break;
            }
            case 2: {
                string id, nombre;
                float precio;
                
                cout << "ID del producto a editar: ";
                getline(cin, id);
                cout << "Nuevo nombre: ";
                getline(cin, nombre);
                cout << "Nuevo precio: ";
                cin >> precio;

                stockGeneral.editarProducto(id, nombre, precio);
                break;
            }
            case 3:
                stockGeneral.mostrarInventario();
                break;
            case 0:
                return;
            default:
                cout << "Opción inválida.\n";
        }
    }
}

// Función para el menú de gestión de cajas
void gestionCajas() {
    while (true) {
        cout << "\n************************* GESTIÓN DE CAJAS *************************\n";
        cout << "1. Abrir nueva caja\n";
        cout << "2. Cerrar caja\n";
        cout << "3. Registrar venta\n";
        cout << "4. Ver facturas del día\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                Caja nuevaCaja;
                nuevaCaja.abrirCaja();
                cajas.push_back(nuevaCaja);
                cout << "Caja " << nuevaCaja.getIdCaja() << " abierta.\n";
                break;
            }
            case 2: {
                if (cajas.empty()) {
                    cout << "No hay cajas abiertas.\n";
                    break;
                }
                // Por simplicidad, cerramos la última caja
                cajas.back().cerrarCaja();
                break;
            }
            case 3: {
                if (cajas.empty()) {
                    cout << "No hay cajas abiertas.\n";
                    break;
                }
                // Aquí iría la lógica para registrar una venta
                cout << "Funcionalidad en desarrollo.\n";
                break;
            }
            case 4: {
                if (cajas.empty()) {
                    cout << "No hay cajas abiertas.\n";
                    break;
                }
                cajas.back().mostrarFacturas();
                break;
            }
            case 0:
                return;
            default:
                cout << "Opción inválida.\n";
        }
    }
}

// Función para el menú de gestión de clientes
void gestionClientes() {
    while (true) {
        cout << "\n************************* GESTIÓN DE CLIENTES *************************\n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Ver lista de clientes\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                string id, nombre, email, rut, profesion, tipoCliente;
                int telefono;
                float totalCompras = 0;
                
                cout << "ID del cliente: ";
                getline(cin, id);
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Email: ";
                getline(cin, email);
                cout << "Teléfono: ";
                cin >> telefono;
                limpiarBuffer();
                cout << "RUT: ";
                getline(cin, rut);
                cout << "Profesión: ";
                getline(cin, profesion);
                cout << "Tipo de cliente: ";
                getline(cin, tipoCliente);

                // Crear dirección (simplificado)
                Direccion dirGenerica("123", "Centro", "Cali", "Valle del Cauca");
                
                Cliente nuevoCliente(id, nombre, email, telefono, dirGenerica, rut, profesion, tipoCliente, totalCompras);
                clientes.push_back(nuevoCliente);
                cout << "Cliente registrado exitosamente.\n";
                break;
            }
            case 2: {
                cout << "\nLista de clientes:\n";
                for (const auto& cliente : clientes) {
                    const_cast<Cliente&>(cliente).mostrarDatos();
                    cout << "------------------------\n";
                }
                break;
            }
            case 0:
                return;
            default:
                cout << "Opción inválida.\n";
        }
    }
}

// Función para el menú de informes
void mostrarInformes() {
    while (true) {
        cout << "\n************************* INFORMES *************************\n";
        cout << "1. Mes con mayores ventas\n";
        cout << "2. Tres mejores clientes\n";
        cout << "3. Empleado del mes\n";
        cout << "4. Marca más vendida\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1:
                cout << "Mes con mayores ventas: " << tienda.mesMayorVenta() << endl;
                break;
            case 2:
                tienda.tresMejoresClientes();
                break;
            case 3:
                cout << tienda.empleadoDelMes() << endl;
                break;
            case 4:
                cout << tienda.marcaMasVendida() << endl;
                break;
            case 0:
                return;
            default:
                cout << "Opción inválida.\n";
        }
    }
}

int main() {
    while (true) {
        mostrarMenuPrincipal();
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1:
                gestionStock();
                break;
            case 2:
                gestionCajas();
                break;
            case 3:
                gestionClientes();
                break;
            case 4:
                cout << "Gestión de proveedores en desarrollo.\n";
                break;
            case 5:
                mostrarInformes();
                break;
            case 0:
                cout << "¡Gracias por usar el sistema!\n";
                return 0;
            default:
                cout << "Opción inválida.\n";
        }
    }
}

/*
    int main() {
        Direccion direccionJuan("123", "Centro", "Cali", "Valle del Cauca");
        Direccion direccionProveedorX("456", "Sur", "Cali", "Valle del Cauca");
        Cliente juan("122346", "Juan Perez", "juan.perez@gmail.com", 3143677337, direccionJuan, "13457", "Jefe", "Empleado Público", 1245);
        Proveedor proveedorX("245968", "Bancolombia", "11109458", "Ahorros", "133467", "Proveedor X", "provedor.x@gmail.com", 3158932781, direccionProveedorX);
        juan.mostrarDatos();

        Producto pc("5867", "PC", "4856", 100000);
        pc.mostrarDatos();
    }
*/


    // // Crear el stock
    // Stock almacenGeneral("Almacen Central");
    // Producto laptop("001", "Laptop", 1200.50f);
    // Producto mouse("002", "Mouse", 25.00f);
    // almacenGeneral.anadirProducto(laptop, 10, 2);  // 10 unidades, stock mínimo de 2
    // almacenGeneral.anadirProducto(mouse, 50, 5);  // 50 unidades, stock mínimo de 5

    // // Crear una factura de venta
    // Factura facturaVenta("venta", &juan); // Pasamos el cliente
    // Producto producto1("Laptop", 1200.50f);
    // facturaVenta.agregarDetalle(producto1, 1); // Agregar 1 Laptop
    // facturaVenta.mostrarDatos(); // Mostrar los detalles de la factura

    // // Crear una factura de compra
    // Factura facturaCompra("compra", &proveedorX); // Pasamos el proveedor
    // Producto producto2("Mouse", 25.30f);
    // facturaCompra.agregarDetalle(producto2, 2); // Agregar 2 Mouse
    // facturaCompra.mostrarDatos(); // Mostrar los detalles de la factura

    // // Crear una marca
    // Marca marca("001", "Lenovo");
    // Producto prod1("P001", "Telefono móvil", 1, 1000000);
    // Producto prod2("P002", "Portatil", 1, 2000000);
    // marca.agregarProducto(prod1);
    // marca.agregarProducto(prod2);
    // marca.mostrarProductos();

    // Caja caja("V001");
    // caja.agregarFactura(facturaVenta);
    // caja.agregarFactura(facturaCompra);
    // caja.mostrarFacturas();

    // almacenCentral.mostrarInventario();
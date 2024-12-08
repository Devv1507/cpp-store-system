/**
 * Programa principal para la gestion de un comercio electronico
 * Este main.cpp representa un CLI para interactuar con el sistema de gestion de un comercio electronico.
 * 
 * Autores:
 *  - David Esteban Valencia Valencia   -   2415092
 *  - Jeremy Andres Astaiza             -   2420580
 *  - Juan Pablo Escamilla              -   2415667
 *  - Nicolle Andrea Paz                -   2419714
 * 
 * Fecha de entrega: 09 de diciembre de 2024
 * Tecnologia en Desarrollo de Software (2724)
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

// Definicion de la sobrecarga del operador << para Marca
ostream& operator<<(ostream& os, const Marca& marca) {
    os << "ID: " << marca.idMarca << ", Nombre: " << marca.nombreMarca;
    return os;
}

// Variables globales para mantener el estado del programa
Stock stockGeneral("STOCK-01");
Tienda tienda("SuperCommerce");
vector<Cliente> clientes;
vector<Proveedor> proveedores;
vector<Caja> cajas;
int Caja::contadorCajas = 1;
int Factura::contadorFacturas = 1;
int Marca::contadorMarcas = 1;
int Producto::contadorProductos = 1;

// Funcion para limpiar el buffer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funcion para leer un entero de la entrada estandar
int leerEntero() {
    int valor;
    while (true) {
        try {
            cin >> valor;
            if (cin.fail()) {
                throw invalid_argument("Entrada no válida. Por favor, ingrese un número entero.");
            }
            return valor;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
        }
    }
}

// Funcion para mostrar el menu principal
void mostrarMenuPrincipal() {
    cout << "\n=== Bienvenid@ al CLI del sistema de gestion del comercio electronico " << tienda.getNombre() << " ===\n";
    cout << "1. Gestion de Stock\n";
    cout << "2. Gestion de Cajas\n";
    cout << "3. Gestion de Clientes\n";
    cout << "4. Gestion de Proveedores\n";
    cout << "5. Informes\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Funcion para el menu de gestion de stock
void gestionStock() {
    while (true) {
        cout << "\n************************* GESTIoN DE STOCK *************************\n";
        cout << "1. Agregar producto\n";
        cout << "2. Editar producto\n";
        cout << "3. Mostrar inventario\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                string id, nombre, idMarca;
                int cantidad, stockMinimo;
                float precio;
                
                cout << "Nombre del producto: ";
                getline(cin, nombre);
                cout << "Precio unitario: ";
                cin.ignore();
                cin >> precio;
                cout << "Cantidad inicial: ";
                cin >> cantidad;
                cout << "Stock minimo: ";
                cin >> stockMinimo;

                Producto nuevoProducto(nombre, precio);
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
                cout << "Opcion invalida.\n";
        }
    }
}

// Funcion para el menu de gestion de cajas
void gestionCajas() {
    while (true) {
        cout << "\n************************* GESTIoN DE CAJAS *************************\n";
        cout << "1. Abrir nueva caja\n";
        cout << "2. Cerrar caja\n";
        cout << "3. Registrar venta\n";
        cout << "4. Ver facturas del dia\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
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
                // Por simplicidad, cerramos la ultima caja
                cajas.back().cerrarCaja();
                break;
            }
            case 3: {
                if (cajas.empty()) {
                    cout << "No hay cajas abiertas.\n";
                    break;
                }
                // Aqui iria la logica para registrar una venta
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
                cout << "Opcion invalida.\n";
        }
    }
}

// Funcion para el menu de gestion de clientes
void gestionClientes() {
    while (true) {
        cout << "\n************************* GESTIoN DE CLIENTES *************************\n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Ver lista de clientes\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion = leerEntero();

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
                cout << "Telefono: ";
                cin >> telefono;
                limpiarBuffer();
                cout << "RUT: ";
                getline(cin, rut);
                cout << "Profesion: ";
                getline(cin, profesion);
                cout << "Tipo de cliente: ";
                getline(cin, tipoCliente);

                // Crear direccion (simplificado)
                Direccion dirGenerica("123", "Centro", "Cali", "Valle del Cauca");
                
                Cliente nuevoCliente(id, nombre, email, telefono, dirGenerica, rut, profesion, tipoCliente);
                clientes.push_back(nuevoCliente);
                cout << "Cliente registrado exitosamente.\n";
                break;
            }
            case 2: {
                cout << "\nLista de clientes:\n";
                if (clientes.empty()) {
                    cout << "No hay clientes registrados.\n";
                    break;
                }
                else {
                    for (Cliente cliente : clientes) {
                        cliente.mostrarDatos();
                    }
                }
                break;
            }
            case 0:
                return;
            default:
                cout << "Opcion invalida.\n";
        }
    }
}

// Funcion para el menu de informes
void mostrarInformes() {
    while (true) {
        cout << "\n************************* INFORMES *************************\n";
        cout << "1. Mes con mayores ventas\n";
        cout << "2. Tres mejores clientes\n";
        cout << "3. Empleado del mes\n";
        cout << "4. Marca mas vendida\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion = leerEntero();

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
                cout << "Opcion invalida.\n";
        }
    }
}

int main() {
    // Crear una marca
    Marca lenovo("Lenovo");
    Producto laptop("Laptop", 1200.50f);
    Producto smarthPhone("SmarthPhone Z10", 500);
    lenovo.agregarProducto(laptop);
    lenovo.agregarProducto(smarthPhone);
    lenovo.mostrarProductos();

    // Crear el stock
    Stock almacenGeneral("Almacen Central");
    almacenGeneral.anadirProducto(laptop, 10, 2);  // 10 unidades, stock minimo de 2
    almacenGeneral.anadirProducto(smarthPhone, 50, 5);  // 50 unidades, stock minimo de 5
    almacenGeneral.mostrarInventario();

    // Crear empleadops
    Direccion direccionDavid("123", "Norte", "Cali", "Valle del Cauca");
    Empleado david("1107526634", "David Perez", "david@supercommerce.com", 5551234, direccionDavid, "9am-6pm", 5000.0f, 0);

    // Crear clientes
    Direccion direccionJuan("123", "Centro", "Cali", "Valle del Cauca");
    Direccion direccionMaria("456", "Sur", "Cali", "Valle del Cauca");
    Cliente juan("1107526814", "Juan Perez", "juan.perez@gmail.com", 3143677337, direccionJuan, "ABC135965", "Ingeniero", "militar");
    Cliente maria("1107526815", "Maria Rodriguez", "maria.rodriguez@gmail.com", 3143677338, direccionMaria, "ABC135966", "Veterinaria", "pensionada");

    // Crear una factura de venta
    Factura facturaJuan("venta", &juan, &almacenGeneral); // Pasamos el cliente y el stock
    facturaJuan.agregarDetalle(laptop, 1); // Agregar 1 Laptop
    facturaJuan.agregarDetalle(smarthPhone, 1); // Agregar 1 SmathPhone
    facturaJuan.mostrarDatos(); // Mostrar los detalles de la factura

    Factura facturaMaria("venta", &maria, &almacenGeneral); // Pasamos el cliente y el stock
    facturaMaria.agregarDetalle(smarthPhone, 10); // Agregar 10 SmathPhone

    // Crear una caja y agregar las facturas
    Caja caja1;
    caja1.agregarFactura(facturaJuan);
    caja1.agregarFactura(facturaMaria);
    caja1.mostrarFacturas();

    // Crear un proveedor
    Direccion direccionGerardoTech("123", "Chapinero", "Bogota", "Cundinamarca");
    Proveedor gerardopTech("245968", "Bancolombia", "11109458", "Ahorros", "1108926814", "Gerardo Tech+", "gerardo.tech@gmail.com", 3158932781, direccionGerardoTech);
    
    // Crear una factura de compra
    Factura facturaCompra("compra", &gerardopTech, &almacenGeneral); // Pasamos el proveedor
    Producto mouse("Mouse", 25.30f);
    facturaCompra.agregarDetalle(mouse, 20); // Agregar 2 Mouse
    facturaCompra.mostrarDatos(); // Mostrar los detalles de la factura
    
    while (true) {
        mostrarMenuPrincipal();
        
        int opcion = leerEntero();

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
                // Lógica para gestionar proveedores
                break;
            case 5:
                mostrarInformes();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }
    }
}
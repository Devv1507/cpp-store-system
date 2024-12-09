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

using namespace std;

// Variables globales para mantener el estado del programa
Stock almacenGeneral("Almacen Central");
Tienda tienda("SuperCommerce");
vector<Cliente> clientes;
vector<Proveedor> proveedores;
vector<Caja> cajas;
int Caja::contadorCajas = 1;
int Factura::contadorFacturas = 1;
int Marca::contadorMarcas = 1;
int Producto::contadorProductos = 1;

/**
 * @brief Función para limpiar el buffer de entrada.
 */
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

/**
 * @brief Función para leer un entero de la entrada estándar.
 * @return int El valor entero leído.
 */
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
};

/**
 * @brief Función para gestionar proveedores.
 */
void gestionProveedores() {
    while (true) {
        cout << "*******************************************************" << endl;
        cout << "\n     Submenu de Gestion de Proveedores     \n";
        cout << "1. Registrar nuevo proveedor\n";
        cout << "2. Ver lista de proveedores\n";
        cout << "0. Volver al menu anterior\n";
        cout << "Seleccione una opcion: ";
        
        int opcion = leerEntero();

        switch (opcion) {
            case 1: {
                string id, nombre, email, banco, cuenta, tipoCuenta, telefono;
                Direccion direccionGenerica("123", "Centro", "Bogota", "Cundinamarca");
                try {
                    cout << "ID del proveedor: ";
                    limpiarBuffer();
                    getline(cin, id);
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    cout << "Email: ";
                    getline(cin, email);
                    cout << "Banco: ";
                    getline(cin, banco);
                    cout << "Numero de cuenta: ";
                    getline(cin, cuenta);
                    cout << "Tipo de cuenta (Ahorros/Corriente): ";
                    getline(cin, tipoCuenta);
                    cout << "Telefono: ";
                    getline(cin, telefono);

                    Proveedor nuevoProveedor(id, banco, cuenta, tipoCuenta, id, nombre, email, telefono, direccionGenerica);
                    proveedores.push_back(nuevoProveedor);

                    cout << "Proveedor registrado exitosamente.\n";
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    cout << "Por favor, ingrese nuevamente los datos.\n";
                }
                break;
            }
            case 2: {
                cout << "\nLista de proveedores:\n";
                if (proveedores.empty()) {
                    cout << "No hay proveedores registrados.\n";
                } else {
                    for (Proveedor proveedor : proveedores) {
                        proveedor.mostrarDatos();
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

/**
 * @brief Función para gestionar el stock.
 */
void gestionStock() {
    while (true) {
        cout << "*******************************************************" << endl;
        cout << "\n     Submenu de Gestion de Inventario     \n";
        cout << "1. Mostrar inventario\n";
        cout << "2. Editar producto\n";
        cout << "3. Agregar producto\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1:
                almacenGeneral.mostrarInventario();
                break;
            case 2: {
                string id, nombre;
                float precio;
                
                cout << "ID del producto a editar: ";
                getline(cin, id);
                cout << "Nuevo nombre: ";
                getline(cin, nombre);
                cout << "Nuevo precio: ";
                cin >> precio;

                almacenGeneral.editarProducto(id, nombre, precio);
                break;
            }
            case 3: {
                string id, nombreProducto;
                int cantidad, stockMinimo;
                float precio;

                Marca marca("random");
                
                cout << "Nombre del producto: ";
                getline(cin, nombreProducto);
                cout << "Precio unitario: ";
                cin.ignore();
                cin >> precio;
                cout << "Cantidad inicial: ";
                cin >> cantidad;
                cout << "Stock minimo: ";
                cin >> stockMinimo;

                Producto nuevoProducto(nombreProducto, precio, marca);
                almacenGeneral.anadirProducto(nuevoProducto, cantidad, stockMinimo);
                cout << "Producto agregado exitosamente.\n";
                break;
            }
            case 0:
                return;
            default:
                cout << "Opcion invalida.\n";
        }
    }
}

/**
 * @brief Función para gestionar las cajas.
 */
void gestionCajas() {
    while (true) {
        cout << "*******************************************************" << endl;
        cout << "\n     Submenu de Gestion de Cajas     \n";
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
                Caja nuevaCaja(&almacenGeneral);
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

/**
 * @brief Función para gestionar los clientes.
 */
// Funcion para el menu de gestion de clientes
void gestionClientes() {
    while (true) {
        cout << "*******************************************************" << endl;
        cout << "\n     Submenu de Gestion de Clientes     \n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Ver lista de clientes\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion = leerEntero();

        switch (opcion) {
            case 1: {
                while (true) {
                    string id, nombre, email, rut, profesion, tipoCliente, telefono;
                    float totalCompras = 0;
                    try {
                        cout << "ID del cliente: ";
                        getline(cin, id);
                        limpiarBuffer();
                        cout << "Nombre: ";
                        getline(cin, nombre);
                        cout << "Email: ";
                        getline(cin, email);
                        cout << "Telefono: ";
                        getline(cin, telefono);
                        cout << "RUT: ";
                        getline(cin, rut);
                        cout << "Profesion: ";
                        getline(cin, profesion);
                        cout << "Tipo de cliente: ";
                        getline(cin, tipoCliente);

                        Direccion dirGenerica("123", "Centro", "Cali", "Valle del Cauca");

                        Cliente nuevoCliente(id, nombre, email, telefono, dirGenerica, rut, profesion, tipoCliente);
                        clientes.push_back(nuevoCliente);

                        cout << "Cliente registrado exitosamente.\n";
                        break;
                    } catch (const invalid_argument& e) {
                        cout << "Error: " << e.what() << endl;
                        cout << "Por favor, ingrese nuevamente los datos.\n";
                    }
                }
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

/**
 * @brief Función para mostrar los reportes de la tienda.
 */
void mostrarReportes() {
    while (true) {
        cout << "*******************************************************" << endl;
        cout << "\n     Submenu de Gestion de Reportes     \n";
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
                tienda.empleadoDelMes();
                break;
            case 4:
                tienda.marcaMasVendida();
                break;
            case 0:
                return;
            default:
                cout << "Opcion invalida.\n";
        }
    }
}


/**
 * @brief Función para imprimir las opciones del menu administrativo
 */
void mostrarMenuAdministrativo() {
    cout << "*******************************************************" << endl;
    cout << "\n     Menu Administrativo     \n";
    cout << "1. Gestion de Inventario\n";
    cout << "2. Gestion de Cajas\n";
    cout << "3. Reportes\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
};

/**
 * @brief Función para definir la lógica del menú administrativo.
 */
void menuAdministrativo() {
    while (true) {
        mostrarMenuAdministrativo(); 
        int opcion = leerEntero();

        switch (opcion) {
            case 1:
                gestionStock();
                break;
            case 2:
                gestionCajas();
                break;
            case 3:
                mostrarReportes();
                break;
            case 0:
                return;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
        }
    }
}

void opcionesMenuUsuarios() {
    cout << "*******************************************************" << endl;
    cout << "\n     Menu de Usuarios     \n";
    cout << "1. Gestion de Clientes\n";
    cout << "2. Gestion de Proveedores\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
};

/**
 * @brief Función para mostrar el menú de usuarios (clientes y proveedores).
 */
void menuUsuarios() {
    while (true) {
        opcionesMenuUsuarios();
        int opcion = leerEntero();

        switch (opcion) {
            case 1:
                gestionClientes();
                break;
            case 2:
                gestionProveedores();
                break;
            case 0:
                return;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
        }
    }
}

/**
 * @brief Función para mostrar el menu principal.
 */
void mostrarMenuPrincipal() {
    cout << "\n     Bienvenid@ al CLI del Sistema de Gestion de E-commerce     " << tienda.getNombre() << " ===\n";
    cout << "1. Menu Administrativo\n";
    cout << "2. Menu de Usuarios\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
};

/**
 * @brief Función principal del programa.
 * @return int Código de estado de la ejecución del programa.
 */
int main() {
    // Crear una marca
    Marca lenovo("Lenovo");

    // Crear productos y agregarlos a la marca
    Producto laptop("Laptop", 1200.50f, lenovo);
    Producto smarthPhone("SmarthPhone Z10", 500, lenovo);

    // Crear el stock
    Stock almacenGeneral("Almacen Central");
    almacenGeneral.anadirProducto(laptop, 10, 2);  // 10 unidades, stock minimo de 2
    almacenGeneral.anadirProducto(smarthPhone, 50, 5);  // 50 unidades, stock minimo de 5
    almacenGeneral.mostrarInventario();

    // Crear empleadops
    Direccion direccionDavid("123", "Norte", "Cali", "Valle del Cauca");
    Empleado david("1107526634", "David Pérez", "david@supercommerce.com", "5551234678", direccionDavid, "9am-6pm", 5000.0f, 0);
    tienda.agregarEmpleado(david);

    // Crear clientes
    Direccion direccionJuan("123", "Centro", "Cali", "Valle del Cauca");
    Direccion direccionMaria("456", "Sur", "Cali", "Valle del Cauca");
    Direccion direccionEsteban("789", "Norte", "Cali", "Valle del Cauca");
    Direccion direccionMiguel("045", "Sur", "Cali", "Valle del Cauca");
    Cliente juan("1107526814", "Juan Perez", "juan.perez@gmail.com", "3143677337", direccionJuan, "ABC135965", "Ingeniero", "militar");
    Cliente maria("1107526815", "Maria Rodriguez", "maria.rodriguez@gmail.com", "3143677338", direccionMaria, "ABC135966", "Veterinaria", "pensionada");
    Cliente esteban("1110385638", "Esteban Muñoz", "esteban.muñoz@gmail.com", "3187560912", direccionEsteban, "ABC135967", "Abogado", "Empleado público");
    Cliente miguel("1049358695", "Miguel Duarte", "miguel.duarte@gmail.com", "3174679435", direccionMiguel, "ABC135968", "Contador", "Empleado público");

    // Crear una factura de venta
    Factura facturaJuan("venta", &juan);
    facturaJuan.agregarDetalle(laptop, 1); // Agregar 1 Laptop
    facturaJuan.agregarDetalle(smarthPhone, 1); // Agregar 1 SmathPhone
    facturaJuan.mostrarDatos(); // Mostrar los detalles de la factura

    Factura facturaMaria("venta", &maria); 
    facturaMaria.agregarDetalle(smarthPhone, 10); // Agregar 10 SmathPhone
    facturaMaria.mostrarDatos();

    Factura facturaEsteban("venta", &esteban);
    facturaEsteban.agregarDetalle(laptop, 5); // Agregar 5 laptop's
    facturaEsteban.mostrarDatos();

    Factura facturaMiguel("venta", &miguel);
    facturaMiguel.agregarDetalle(smarthPhone, 10);
    facturaMiguel.mostrarDatos();


    // Crear una caja y agregar las facturas
    Caja caja1(&almacenGeneral);
    caja1.registrarTransaccion(facturaJuan);
    caja1.registrarTransaccion(facturaMaria);
    caja1.agregarFactura(facturaEsteban);
    caja1.agregarFactura(facturaMiguel);
    caja1.mostrarFacturas();
    tienda.agregarCaja(caja1);

    // Crear un proveedor
    Direccion direccionGerardoTech("123", "Chapinero", "Bogota", "Cundinamarca");
    Proveedor gerardopTech("245968", "Bancolombia", "11109458", "Ahorros", "1108926814", "Gerardo Tech+", "gerardo.tech@gmail.com", "3158932781", direccionGerardoTech);
    
    // Crear una factura de compra
    Factura facturaCompra("compra", &gerardopTech); // Pasamos el proveedor
    Producto mouse("Mouse", 25.30f, lenovo);
    facturaCompra.agregarDetalle(mouse, 20); // Agregar 2 Mouse
    facturaCompra.mostrarDatos(); // Mostrar los detalles de la factura

    almacenGeneral.mostrarInventario();
    cout << tienda.tresMejoresClientes() << endl;

   while (true) {
        mostrarMenuPrincipal();
        int opcion = leerEntero();

        switch (opcion) {
            case 1:
                menuAdministrativo();
                break;
            case 2:
                menuUsuarios();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
        }
    }
}
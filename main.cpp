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
        cout << string(75, '-') << endl;
        cout << "\n     Submenu de Gestion de Proveedores     \n";
        cout << "1. Registrar nuevo proveedor\n";
        cout << "2. Registrar venta a proveedor\n";
        cout << "3. Imprimir cantidad de facturas de compra por proveedor\n";
        cout << "0. Volver al menu anterior\n";
        cout << "Seleccione una opcion: ";
        
        int opcion = leerEntero();

        switch (opcion) {
            case 1: {
                string id, nombre, email, banco, cuenta, tipoCuenta, telefono;
                Direccion direccionGenerica("123", "Centro", "Bogota", "Cundinamarca");
                try {
                    cout << "Por favor, ingrese los siguientes campos para registrarse como proveedor:\n";
                    cout << "ID del proveedor: ";
                    cin >> id;
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    limpiarBuffer();
                    cout << "Email: ";
                    cin >> email;
                    cout << "Banco: ";
                    cin >> banco;
                    cout << "Numero de cuenta: ";
                    cin >> cuenta;
                    cout << "Tipo de cuenta (Ahorros/Corriente): ";
                    getline(cin, tipoCuenta);
                    limpiarBuffer();
                    cout << "Telefono: ";
                    getline(cin, telefono);

                    Proveedor nuevoProveedor(id, banco, cuenta, tipoCuenta, id, nombre, email, telefono, direccionGenerica);
                    cout << "Proveedor registrado exitosamente.\n";
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    cout << "Por favor, ingrese nuevamente los datos.\n";
                }
                break;
            }
            case 2: {
                cout << "Por favor, ingrese los siguientes campos para registrar la venta:\n";
                string idProveedor, nombreMarca, nombreProducto, descripcionProducto;
                int cantidad, stockMinimo;
                float precioUnitario;
                cout << "ID del proveedor: ";
                cin >> idProveedor;
                cout << "Nombre del producto: ";
                getline(cin, nombreProducto);
                limpiarBuffer();
                cout << "Descripcion: ";
                getline(cin, descripcionProducto);
                cout << "Precio Unitario: ";
                cin >> precioUnitario;
                cout << "Marca del producto: ";
                cin >> nombreMarca;
                cout << "Cantidad: ";
                cin >> cantidad;
                cout << "Stock mínimo";
                cin >> stockMinimo;
                Marca newMarca(nombreMarca);
                Producto newProducto(nombreProducto, descripcionProducto, precioUnitario, newMarca);
                almacenGeneral.anadirProducto(newProducto, precioUnitario, cantidad, stockMinimo);
                cout << "Producto comprado y agregado al inventario exitosamente.\n";
                break;
            }
            case 3: {
                tienda.mostrarCantidadFacturasPorProveedor();
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
        cout << string(75, '-') << endl;
        cout << "\n     Submenu de Gestion de Inventario     \n";
        cout << "1. Mostrar inventario\n";
        cout << "2. Editar producto\n";
        cout << "3. Agregar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Buscar producto\n";
        cout << "6. Filtrar productos por marca\n";
        cout << "7. Agregar marca\n";
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
                string id, nombreProducto, descripcionProducto;
                int cantidad, stockMinimo;
                float precio;

                Marca marca("random");
                
                cout << "Nombre del producto: ";
                getline(cin, nombreProducto);
                cout << "Breve descripcion del producto: ";
                getline(cin, descripcionProducto);
                cout << "Precio unitario: ";
                cin.ignore();
                cin >> precio;
                cout << "Cantidad inicial: ";
                cin >> cantidad;
                cout << "Stock minimo: ";
                cin >> stockMinimo;

                Producto nuevoProducto(nombreProducto, descripcionProducto, precio, marca);
                almacenGeneral.anadirProducto(nuevoProducto, precio, cantidad, stockMinimo);
                cout << "Producto agregado exitosamente.\n";
                break;
            }
            case 4: {
                cout << "Ingrese el ID del producto a eliminar: ";
                string idProducto;
                cin >> idProducto;

                try {
                almacenGeneral.eliminarProducto(idProducto);
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: {
                string id;
                cout << "ID del producto a buscar: ";
                getline(cin, id);
                almacenGeneral.buscarIndiceProducto(id);
                break;
            }
            case 6: {
                string marca;
                cout << "Nombre de la marca: ";
                getline(cin, marca);
                almacenGeneral.filtrarPorMarca(marca);
                break;
            }
            case 7: {
                string nombreMarca;
                cout << "Nombre de la marca: ";
                getline(cin, nombreMarca);
                almacenGeneral.agregarMarca(nombreMarca);
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
        cout << string(75, '-') << endl;
        cout << "\n     Submenu de Gestion de Cajas     \n";
        cout << "1. Imprimir resumen ejecutivo (ganancias) \n";
        cout << "2. Imprimir todas las facturas\n";
        cout << "3. Imprimir facturas de compra (proveedores)\n";
        cout << "4. Imprimir facturas de venta (clientes)\n";
        cout << "5. Imprimir facturas de un mes\n";
        cout << "6. Imprimir facturas del mes de mayo\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion;
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                tienda.getCajas()[0].mostrarResumenFacturas();
                break;
            }
            case 2: {
                tienda.getCajas()[0].mostrarFacturas();
                break;
            }
            case 3: {
                tienda.getCajas()[0].listarFacturasPorTipo("compra");
                break;
            }
            case 4: {
                tienda.getCajas()[0].listarFacturasPorTipo("venta");
                break;
            }
            case 5: {
                cout << "Facturas de un mes particular:\n";
                // tienda.getCajas()[0].listarFacturasPorMes("mayo");
                break;
            }
            case 6: {
                cout << "Facturas del mes de mayo:\n";
                // tienda.getCajas()[0].listarFacturasPorMes("mayo");
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
        cout << string(75, '-') << endl;
        cout << "\n     Submenu de Gestion de Clientes     \n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Registrar compra a cliente\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        
        int opcion = leerEntero();

        switch (opcion) {
            case 1: {
                string id, nombre, email, rut, profesion, tipoCliente, telefono;
                Direccion dirGenerica("123", "Centro", "Cali", "Valle del Cauca");
                float totalCompras = 0;

                try {
                    cout << "ID del cliente: ";
                    cin >> id;
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    limpiarBuffer();
                    cout << "Email: ";
                    cin >> email;
                    cout << "Telefono: ";
                    cin >> telefono;
                    cout << "RUT: ";
                    cin >> rut;
                    limpiarBuffer();
                    cout << "Profesion: ";
                    getline(cin, profesion);
                    cout << "Tipo de cliente: ";
                    getline(cin, tipoCliente);

                    Cliente nuevoCliente(id, nombre, email, telefono, dirGenerica, rut, profesion, tipoCliente);
                    Cliente::agregarCliente(nuevoCliente);
                    cout << "Cliente registrado exitosamente.\n";
                    break;
                } catch(const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    cout << "Por favor, ingrese nuevamente los datos.\n";
                }
            }
            case 2: {
                cout << "Por favor, ingrese los siguientes campos para registrar la compra:\n";
                string idCliente, idProducto;
                float cantidad;
                cout << "ID del cliente: ";
                cin >> idCliente;
                Cliente* cliente = Cliente::buscarCliente(idCliente);
                cout << "Cliente encontrado: " << endl;

                almacenGeneral.mostrarInventario();

                cout << "ID del producto que desea comprar: ";
                cin >> idProducto;

                // Buscar el producto en el inventario
                int indiceProducto = almacenGeneral.buscarIndiceProducto(idProducto);
                if (indiceProducto == -1) {
                    cout << "Producto no encontrado.\n";
                    break;
                }

                Producto& producto = almacenGeneral.getProductos()[indiceProducto];

                cout << "Cantidad: ";
                cin >> cantidad;

                // Verificar si el producto está disponible
                if (almacenGeneral.productoDisponible(producto, cantidad)) {
                    Factura facturaCliente("venta", cliente);
                    facturaCliente.agregarDetalle(producto, cantidad);

                    // Actualizar existencias en el inventario
                    almacenGeneral.modificarExistencias(producto.getIdProducto(), cantidad, "venta");
                    cout << "Factura generada para el cliente.\n";
                } else {
                    cout << "No hay suficiente stock.";
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
        cout << string(75, '-') << endl;
        cout << "\n     Submenu de Gestion de Indicadores/Reportes     \n";
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
    cout << "3. Indicadores del Negocio\n";
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
    cout << string(75, '-') << endl;
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
    cout << "\n     Bienvenid@ al CLI del Sistema de Gestion de E-commerce " << tienda.getNombre() << "     \n";
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
    Marca samsung("Samsung");

    // Crear productos y agregarlos a la marca
    Producto laptop("Laptop", "Laptop Plus Ultra", 1200.50f, lenovo);
    Producto smarthPhone("SmarthPhone Z10", "SmarthPhone con DirectX", 500, lenovo);
    Producto smarthPhone2("SmarthPhone S20", "SmathPhone tematica Arcane", 800, samsung);

    // Crear el stock
    Stock almacenGeneral("Almacen Central");
    almacenGeneral.anadirProducto(laptop, 50000.0, 10, 2);  // 10 unidades, stock minimo de 2
    almacenGeneral.anadirProducto(smarthPhone, 30000.0, 50, 5);  // 50 unidades, stock minimo de 5
    almacenGeneral.anadirProducto(smarthPhone2, 30000.0, 30, 5);  // 30 unidades, stock minimo de 5
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
    facturaJuan.agregarDetalle(smarthPhone2, 1); // Agregar 1 SmathPhone
    cout << endl;
    facturaJuan.mostrarDatos(); // Mostrar los detalles de la factura

    Factura facturaMaria("venta", &maria); 
    facturaMaria.agregarDetalle(smarthPhone, 10); // Agregar 10 SmathPhone
    cout << endl;
    facturaMaria.mostrarDatos();

    Factura facturaEsteban("venta", &esteban);
    facturaEsteban.agregarDetalle(laptop, 5); // Agregar 5 laptop's
    cout << endl;
    facturaEsteban.mostrarDatos();

    Factura facturaMiguel("venta", &miguel);
    facturaMiguel.agregarDetalle(smarthPhone2, 10);
    cout << endl;
    facturaMiguel.mostrarDatos();


    // Crear una caja y agregar las facturas
    Caja caja1(&almacenGeneral);
    caja1.registrarTransaccion(facturaJuan);
    caja1.registrarTransaccion(facturaMaria);
    caja1.agregarFactura(facturaEsteban);
    caja1.agregarFactura(facturaMiguel);
    caja1.mostrarFacturas();
   
    // Crear un proveedor
    Direccion direccionGerardoTech("123", "Chapinero", "Bogota", "Cundinamarca");
    Proveedor gerardopTech("245968", "Bancolombia", "11109458", "Ahorros", "1108926814", "Gerardo Tech+", "gerardo.tech@gmail.com", "3158932781", direccionGerardoTech);
    
    // Crear una factura de compra
    Factura facturaCompra("compra", &gerardopTech); // Pasamos el proveedor
    Producto mouse("Mouse", "Mouse Ergonomico Vertical", 25.3, lenovo);
    facturaCompra.agregarDetalle(mouse, 20); // Agregar 2 Mouse
    cout << endl;
    facturaCompra.mostrarDatos();
    caja1.agregarFactura(facturaCompra);
    tienda.agregarCaja(caja1);

    almacenGeneral.mostrarInventario();
    cout << endl;
    tienda.tresMejoresClientes();

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
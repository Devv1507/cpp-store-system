#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <ctime>
#include "DetallesFactura.h"
#include "Persona.h"
#include "Stock.h"
#include "Marca.h"

using namespace std;

class Factura {
    private:
        static int contadorFacturas; 
        string fechaFactura, horaFactura, tipoVenta; 
        string idFactura, idCliente, idProveedor; 
        float totalFactura; 
        Persona* persona;  
        vector<DetallesFactura> detallesFactura; 


        /**
         * @brief Genera un identificador único basado en un contador.
         * Se basa en la fusión de un prefijo, la fecha actual y un contador.
         * @return Identificador único de la factura.
         */
        string generarIdFactura() {
            stringstream ss;
            time_t t = time(nullptr);
            tm* now = localtime(&t);
        
            ss << "F-" 
               << setw(2) << setfill('0') << (now->tm_mon + 1)
               << setw(2) << setfill('0') << now->tm_mday  
               << "-" 
               << setw(5) << setfill('0') << contadorFacturas++;
        
            return ss.str();
        };

        /**
         * @brief Obtiene la fecha actual en formato YYYY-MM-DD.
         * @return Fecha actual.
         */
        string obtenerFechaActual() {
            time_t t = time(0);
            tm* now = localtime(&t);
            stringstream stringstream;
            stringstream << (now->tm_year + 1900) << "-"
                << (now->tm_mon + 1) << "-"
                << now->tm_mday;
            return stringstream.str();
        }

        /**
         * @brief Obtiene la hora actual en formato HH:MM:SS.
         * @return Hora actual.
         */
        string obtenerHoraActual() {
            time_t t = time(0);
            tm* now = localtime(&t);
            stringstream stringstream;
            stringstream << now->tm_hour << ":"
                << now->tm_min << ":"
                << now->tm_sec;
            return stringstream.str();
        }
    public:
        /**
         * @brief Constructor de la clase Factura.
         * Necesita los siguientes parámetros para instanciar un objeto de la clase Factura:
         * 
         * @param tipoVenta Tipo de venta (compra o venta).
         * @param persona Puntero a un objeto Persona (Cliente o Proveedor).
         * @param stock Puntero al stock asociado a la factura.
         */
        Factura(string tipoVenta, Persona* persona):
            tipoVenta(tipoVenta),
            persona(persona),
            idFactura(generarIdFactura()),
            fechaFactura(obtenerFechaActual()),
            horaFactura(obtenerHoraActual()),
            totalFactura(0) {
                // Determinar si se trata de una compra o venta
                if (tipoVenta == "venta") {
                    idCliente = persona->getId();
                } else if (tipoVenta == "compra") {
                    idProveedor = persona->getId();
                } else {
                    throw invalid_argument("El tipo de venta debe ser 'venta' o 'compra'.");
                }
            };
        // Getters y Setters
        string getIdFactura() { return idFactura; };
        string getFechaFactura() { return fechaFactura; };
        string getHoraFactura() { return horaFactura; };
        string getTipoVenta() { return tipoVenta; };
        string getIdCliente() { return idCliente; };
        string getIdProveedor() { return idProveedor; };
        float getTotalFactura() { return totalFactura; };
        vector<DetallesFactura> getDetallesFactura() { return detallesFactura; };
        void setIdFactura(string idFactura) { this->idFactura = idFactura; };
        void setFechaFactura(string fechaFactura) { this->fechaFactura = fechaFactura; };
        void setHoraFactura(string horaFactura) { this->horaFactura = horaFactura; };
        void setTipoVenta(string tipoVenta) { 
            if (tipoVenta == "venta") {
                idCliente = persona->getId();
            } else if (tipoVenta == "compra") {
                idProveedor = persona->getId();
            } else {
                throw invalid_argument("El tipo de venta debe ser 'venta' o 'compra'.");
            }
        };
        void setIdCliente(string idCliente) { this->idCliente = idCliente; };
        void setIdProveedor(string idProveedor) { this->idProveedor = idProveedor; };
        void setTotalFactura(float totalFactura) { this->totalFactura = totalFactura; };
        /************************************************ Metodos especificos ************************************************/
        
        /**
         * @brief Agrega un detalle a la factura.
         * @param producto Referencia al producto.
         * @param cantidad Cantidad del producto.
         */
        void agregarDetalle(Producto &producto, int cantidad) {
            // Verificar si la cantidad es valida antes de modificar existencias
            if (cantidad <= 0) {
                throw invalid_argument("La cantidad debe ser mayor que cero.");
            }

            // Crear el detalle de la factura y agregarlo
            DetallesFactura detalle(producto, cantidad);
            detallesFactura.push_back(detalle);

            // Actualizar el total de la factura
            totalFactura += detalle.getSubtotalProducto();
        };

        /**
         * @brief Filtra la factura por tipo de venta.
         * @param tipoVenta Tipo de venta (compra o venta).
         * @return Identificador de la factura si coincide con el tipo de venta.
         */
        string getFacturaPorTipo(string tipoVenta) {
            if (this->tipoVenta == tipoVenta) {
                return idFactura;
            }
        };

        /**
         * @brief Muestra los datos completos de la factura.
         */
        void mostrarDatos() {
            cout << "Factura ID: " << idFactura << ", Fecha: " << fechaFactura
                << ", Hora: " << horaFactura << ", Tipo: " << tipoVenta
                << ", Total: $" << totalFactura << endl;

            if (tipoVenta == "venta") {
                cout << "Cliente ID: " << persona->getId() << endl;
            } else if (tipoVenta == "compra") {
                cout << "Proveedor ID: " << persona->getId() << endl;
            }

            cout << "--- Detalles de la Factura ---" << endl;
            for (size_t i = 0; i < detallesFactura.size(); ++i) {
                detallesFactura[i].mostrarDetalle();
            }
        };
};
#endif // FACTURA_H
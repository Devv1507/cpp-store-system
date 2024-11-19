#include <iostream>
using namespace std;

class Producto {
    private:
        string idProducto, nombreProducto;
        float precioUnitario;
    public:
        Producto(string idProducto, string nombreProducto, float precioUnitario):
            idProducto(idProducto), nombreProducto(nombreProducto), precioUnitario(precioUnitario) {};
        // Getters y Setters
        string getIdProducto() { return idProducto; };
        string getNombreProducto() { return nombreProducto; };
        float getPrecioUnitario() { return precioUnitario; };
        void setIdProducto(string idProducto) { this->idProducto = idProducto; };
        void setNombreProducto(string nombreProducto) { this->nombreProducto = nombreProducto; };
        void setPrecioUnitario(float precioUnitario) { this->precioUnitario = precioUnitario; };
};
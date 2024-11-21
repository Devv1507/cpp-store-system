#include <iostream>
#include <vector>
#include <string>
#include "Stock.h"
#include "Producto.h"
using namespace std;

class Marca {
    private:
        int idMarca;
        string nombreMarca;
        vector<Producto> listarProductos; //vector para guardar los productos de una marca
    public:
        //constructores
        Marca(): idMarca(0), nombreMarca("") {}
        Marca(int idMarca, string nombreMarca): idMarca(idMarca), nombreMarca(nombreMarca) {}
            //getters y setters
            int getIdMarca();
            string getNombreMarca();
            int setIdMarca();
            string setNombreMarca();

            void agregarProducto(const Producto& producto);
            void mostrarProductos();
};

    //definición de getters y setters
    int Marca::getIdMarca() {return idMarca; }
    string Marca::getNombreMarca() {return nombreMarca; }
    int Marca::setIdMarca() { this->idMarca = idMarca; }
    string Marca::setNombreMarca() { this->nombreMarca = nombreMarca; }

    //método para agregar un producto a una marca
    void Marca::agregarProducto(const Producto& producto) {
        listarProductos.push_back(producto);
    }

    //método para mostar todos los productos de una marca
    void Marca::mostrarProductos() {
        cout << "Productos de la marca " << nombreMarca << ":" << endl;
        for (size_t i = 0; i < listarProductos.size(); i++) {
            listarProductos[i].mostrarDatos();
        }
    }
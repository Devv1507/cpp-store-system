#include <iostream>
#include <vector>
#include <string>
#include "Stock.h"
using namespace std;

class Marca {
    private:
        int idMarca;
        string nombreMarca;
    public:
        //constructores
        Marca(): idMarca(0), nombreMarca("") {}
        Marca(int idMarca, string nombreMarca): idMarca(idMarca), nombreMarca(nombreMarca) {}
            //getters y setters
            int getIdMarca();
            string getNombreMarca();
            int setIdMarca();
            string setNombreMarca();

            void listarProductos();
};

    //definición de getters y setters
    int Marca::getIdMarca() {return idMarca; }
    string Marca::getNombreMarca() {return nombreMarca; }
    int Marca::setIdMarca() { this->idMarca = idMarca; }
    string Marca::setNombreMarca() { this->nombreMarca = nombreMarca; }
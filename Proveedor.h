#include <iostream>
using namespace std;

class Proveedor {
    private:
        string rut, banco, numeroCuenta, tipoCuenta;
    public:
        Proveedor(string, string, string, string);
        string getRut();
        string getBanco();
        string getNumeroCuenta();
        string getTipoCuenta();
        void setRut(string);
        void setBanco(string);
        void setNumeroCuenta(string);
        void setTipoCuenta(string);
        void mostrarDatos();
    };
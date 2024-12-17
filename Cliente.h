#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "Producto.h"
#include "Carritocompras.h"
using namespace std;
class Cliente{
    private:
        int idCliente;
        string nombre;
        string direccion;
        static const int maxcompras=100;
        int historialCompras[maxcompras];
        int numCompras;
    public:
        Cliente();
        Cliente(int idCliente, string nombre, string direccion, int numCompras);
        ~Cliente(){
        }
        int getIDCliente();
        void setIDCliente(int idCliente);
        string getNombre();
        void setNombre(string nombre);
        string getDireccion();
        void setDireccion(string direccion);
        int* getHistorialCompras() const;
        int getNumCompras();
        void setNumCompras(int numCompras);
        void realizarCompra(Producto productos[], int cantidad);
        virtual double aplicarDescuento(double totalCompra);
        void displayInfo();
};
Cliente::Cliente(){
    idCliente = 0;
    nombre = "";
    direccion = "";
    numCompras = 0;
}
Cliente::Cliente(int idCliente, string nombre, string direccion, int numCompras){
    this->idCliente=idCliente;
    this->nombre=nombre;
    this->direccion=direccion;
    this->numCompras=numCompras;
}
int Cliente::getIDCliente(){
    return idCliente;
}
void Cliente::setIDCliente(int idCliente){
    this->idCliente=idCliente;
}
string Cliente::getNombre(){
    return nombre;
}
void Cliente::setNombre(string nombre){
    this->nombre=nombre;
}
string Cliente::getDireccion(){
    return direccion;
}
void Cliente::setDireccion(string direccion){
    this->direccion=direccion;
}
int* Cliente::getHistorialCompras() const {
    return (int*)historialCompras;
}
int Cliente::getNumCompras(){
    return numCompras;
}
void Cliente::setNumCompras(int numCompras){
    this->numCompras=numCompras;
}
void Cliente::realizarCompra(Producto productos[], int cantidad){           //ACÁ NO ENTIENDO. YA LE ENTENDÍ.
    if (cantidad==0) {
        cout << "Su carrito está vacío." << endl;
    }
    else{
        cout<<"Compra exitosa."<<endl;
        cout<<"Compras."<<endl;
        for(int i=0;i<cantidad;i++){
            historialCompras[numCompras]=productos[i].getIDProducto();
            numCompras+=1;
            cout<<"Producto: "<<productos[i].getNombre()<<endl;
        }
    }
}
double Cliente::aplicarDescuento(double totalCompra){
    if (numCompras>=5) {
        double descuento = 0.05 * totalCompra;
        totalCompra -= descuento;
        cout << "Descuento aplicado del 5%. Total original: " << totalCompra + descuento<<endl;
        cout << "Nuevo total después del descuento: " << totalCompra << endl;
    }
    return totalCompra; 
}
void Cliente::displayInfo(){
    cout<<"Información del Cliente."<<endl;
    cout<<"ID del cliente: "<<idCliente<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Dirección: "<<direccion<<endl;
    cout<<"Historial de Compras: "<<endl;
    for (int i = 0; i < numCompras; i++) {
        cout << historialCompras[i] << endl;
    }
}

#endif
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>

using namespace std;
class Producto{
    private:
        int idProducto;
        string nombre;
        double precio;
    public:
        Producto();
        Producto(int idProducto,string nombre, double precio);
        ~Producto(){
        }
        int getIDProducto();
        void setIDProducto(int);
        string getNombre();
        void setNombre(string);
        double getPrecio();
        void setPrecio(double);
};
Producto::Producto(){
    idProducto= 0;
    nombre= "";
    precio= 0.0;
}
Producto::Producto(int idProducto,string nombre, double precio){
    this->idProducto=idProducto;
    this->nombre=nombre;
    this->precio=precio;
}
int Producto::getIDProducto(){
    return idProducto;
}
void Producto::setIDProducto(int idProducto){
    this->idProducto=idProducto;
}
string Producto::getNombre(){
    return nombre;
}
void Producto::setNombre(string nombre){
    this->nombre=nombre;
}
double Producto::getPrecio(){
    return precio;
}
void Producto::setPrecio(double precio){
    this->precio=precio;
}
#endif
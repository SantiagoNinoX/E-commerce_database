#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Producto.h"
using namespace std;
class Carritocompras{
    private:
        static const int MAX_PRODUCTOS=10;
        Producto productos[MAX_PRODUCTOS];
        int numProductos;
    public:
        Carritocompras();
        Carritocompras(int numProductos);
        ~Carritocompras(){
        }
        void agregarProducto(Producto productoparaAgregar);
        double calcularTotalCompra();
        void mostrarCarrito();
        void eliminarProducto(int idProducto);
};
Carritocompras::Carritocompras(){
    numProductos=0;
}
Carritocompras::Carritocompras(int numProductos){
    this->numProductos=numProductos;
}
void Carritocompras::agregarProducto(Producto productoparaAgregar){
    if (numProductos>=MAX_PRODUCTOS){
        cout<<"Carrito lleno, ya no se pueden agregar más cosas."<<endl;
    }
    else{
        productos[numProductos]=productoparaAgregar;
        numProductos+=1;
        cout << "Producto agregado con exito al carrito." << endl;
    }
}
double Carritocompras::calcularTotalCompra(){
    double total=0.0;
    for(int i=0;i<numProductos;i++){
        total+=productos[i].getPrecio();
    }
    return total;
}
void Carritocompras::mostrarCarrito(){
    for(int i=0;i<numProductos;i++){
        cout<<"Producto "<<i+1<<": "<<endl;
        cout<<"ID: "<<productos[i].getIDProducto()<<endl;
        cout<<"Nombre: "<<productos[i].getNombre()<<endl;
        cout<<"Precio: "<<productos[i].getPrecio()<<endl;
    }
    cout<<"Total compra: "<<calcularTotalCompra()<<endl;
}
void Carritocompras::eliminarProducto(int idProducto){
    for(int i=0;i<numProductos;i++){
        if (idProducto==productos[i].getIDProducto()){
           for (int j = i; j < numProductos -1; j++) {
                productos[j] = productos[j + 1];
            }
            numProductos-1;
            cout << "Producto eliminado con exito del carrito." << endl;
        }
        else{
            cout << "El producto no se encuentra en el carrito." << endl;
        }
    }
}
#endif
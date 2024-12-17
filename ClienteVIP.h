#ifndef CLIENTEVIP_H
#define CLIENTEVIP_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Carritocompras.h"
#include "Producto.h"
using namespace std;
class ClienteVIP:public Cliente{
    private:
        string tipoClienteVIP;
    public:
        ClienteVIP();
        ClienteVIP(int idCliente,string nombre,string direccion,int numCompras,string tipoClienteVIP);
        ~ClienteVIP(){
        }
        string getTipoClienteVIP();
        void setTipoClienteVIP(string);
        double aplicarDescuento(double totalCompra)override;
        void displayInfo2();
};
ClienteVIP::ClienteVIP():Cliente(){
    Cliente();
    tipoClienteVIP=" ";
}
ClienteVIP::ClienteVIP(int idCliente,string nombre,string direccion,int numCompras,string tipoClienteVIP):Cliente(idCliente,nombre,direccion,numCompras){
    this->tipoClienteVIP=tipoClienteVIP;
}
string ClienteVIP::getTipoClienteVIP(){
    return tipoClienteVIP;
}
void ClienteVIP::setTipoClienteVIP(string tipoClienteVIP){
    this->tipoClienteVIP=tipoClienteVIP;
}
double ClienteVIP::aplicarDescuento(double totalCompra){
    double descuento=0.0;
    if (tipoClienteVIP == "Oro") {
        descuento = 0.10;
    } 
    else if (tipoClienteVIP == "Platino") {
        descuento = 0.15;
    } 
    else if (tipoClienteVIP == "Diamante") {
        descuento = 0.20;
    }
    if (descuento > 0.0) {
        double descuentoAplicado = descuento * totalCompra;
        totalCompra -= descuentoAplicado;

        cout << "Descuento VIP del " << descuento * 100 << "%"<<endl;
        cout<<"Total original: " << totalCompra + descuentoAplicado<<endl;
        cout<<"Nuevo total después del descuento: " << totalCompra <<endl;
    } 
    else {
        cout << "Cliente VIP sin descuento aplicable. Total original: " << totalCompra <<endl;
    }
    return totalCompra;
}
void ClienteVIP::displayInfo2(){
    Cliente::displayInfo();
    cout<<"Tipo de Cliente VIP: "<<tipoClienteVIP<<endl;
}
#endif
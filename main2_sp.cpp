#include <iostream>
#include <cctype>
#include <string>
#include "Producto.h"
#include "Carritocompras.h"
#include "Cliente.h"
#include "ClienteVIP.h"
using namespace std;

void displayTienda(Producto arregloTienda[]);

int main() {
    ClienteVIP clientesvip[5];
    Carritocompras carritos[5];
    Producto producto1(123,"Sueter",234.99);
    Producto producto2(234,"Chamarra",1000.00);
    Producto producto3(345,"Sudadera",410.50);
    Producto producto4(456,"Abrigo",1500.00);
    Producto producto5(567,"Capa",250.00);
    Producto producto6(678,"Jeans",500.00);
    Producto producto7(789,"Pants",600.00);
    Producto producto8(890,"Zapatos",750.99);
    Producto producto9(901,"Chanclas",150.00);
    Producto producto10(246,"Lentes",450.50);
    Producto producto11(135,"Reloj",875.99);
    Producto producto12(802,"Playera",350.00);
    Producto producto13(791,"Calcetines",75.99);
    Producto producto14(235,"Polo",400.00);
    Producto producto15(255,"Chaleco",930.85);
    Producto arregloTienda[15]={producto1,producto2,producto3,producto4,producto5,producto6,producto7,producto8,producto9,producto10,producto11,producto12,producto13,producto14,producto15};

    for(int i=0;i<5;i++){
        string nombreCliente, direccionCliente, tipoClienteVIP;
        int idCliente;

        cout<<"Ingresa tu ID: "<<endl;
        cin>>idCliente;
        cout<<"Ingresa tu nombre: "<<endl;
        cin.ignore(); 
        getline(cin, nombreCliente);
        cout<<"Ingresa tu dirección: "<<endl;
        getline(cin, direccionCliente);
        cout<<"Ingresa el tipo de cliente VIP (Oro, Platino, Diamante)"<<endl;
        cin>>tipoClienteVIP;

        clientesvip[i]=ClienteVIP(idCliente, nombreCliente, direccionCliente, 0, tipoClienteVIP);  

        for (int j = i * 3; j < (i + 1) * 3; j++) {
            carritos[i].agregarProducto(arregloTienda[j]);
        }

        cout<<"Cliente VIP "<<i+1<<": "<<endl;
        clientesvip[i].displayInfo2();
        cout<<"Carrito: "<<endl;
        carritos[i].mostrarCarrito();

        cout<<"Compra: "<<endl;
        Producto productos[3];
        for(int s=0;s<3;s++){
            productos[s]=arregloTienda[i * 3 + s];
        }
        clientesvip[i].realizarCompra(productos,3);
        
        cout<<"Carrito después de la compra: "<<endl;
        carritos[i].mostrarCarrito();

        double totalpagarfinal = carritos[i].calcularTotalCompra();
        cout<<"Total de la compra: "<<totalpagarfinal<<endl;
        clientesvip[i].aplicarDescuento(totalpagarfinal);
        cout<<"Información del cliente después de la compra."<<endl;
        clientesvip[i].displayInfo2();
    }

    return 0;
}
#ifndef PRUEBAS_H
#define PRUEBAS_H

#include "E_S_Listas.h"

void pruebas(listaCircular<int>& lista)
{
    cout<<"Sea la lista circular simple:" <<endl;
    muestraLista(lista);
    cout<<endl;

    cout<<"El siguiente al tercero es: "<<lista.elemento(lista.siguiente(lista.buscar(3)))<<endl;
    cout<<"El anterior al segundo es: "  <<lista.elemento(lista.anterior(lista.buscar(2)))<<endl;
    cout<<"El siguiente del siguiente del tercero es: "<<lista.elemento(lista.siguiente(lista.siguiente(lista.buscar(3))))  <<endl;

    cout << endl;

    cout<<"El anterior al anterior del ultimo es: "  <<lista.elemento(lista.anterior(lista.anterior(lista.inipos())))          <<endl;
    cout<<"El anterior al ultimo es: "  <<lista.elemento(lista.anterior(lista.inipos()))                                       <<endl;
    cout<<"El ultimo es : "             <<lista.elemento(lista.inipos())                                                       <<endl;
    cout<<"El siguiente al ultimo es: " <<lista.elemento(lista.siguiente(lista.inipos()))                                      <<endl;
    cout<<"El siguiente del siguiente al ultimo es: " <<lista.elemento(lista.siguiente(lista.siguiente(lista.inipos())))       <<endl;

    cout << endl;

    cout<<"El anterior al anterior del primero es: "  <<lista.elemento(lista.anterior(lista.anterior(lista.inipos())))     <<endl;
    cout<<"El anterior al primero es: "  <<lista.elemento(lista.anterior(lista.inipos()))                                  <<endl;
    cout<<"El primero es : "             <<lista.elemento(lista.inipos())                                                  <<endl;
    cout<<"El siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.inipos()))                                 <<endl;
    cout<<"El siguiente del siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.siguiente(lista.inipos())))  <<endl;

    int numero_a_eliminar;
    do
    {
        cout<<"Numero a eliminar : ";
        cin>>numero_a_eliminar;
        cout<<"Eliminamos el numero "<<numero_a_eliminar<<endl;
        lista.eliminar(lista.buscar(numero_a_eliminar));
        muestraLista(lista);
        pruebas(lista);
    }
    while(lista.inipos());

    cout<<"Se ha vaciado la lista"<<endl;
}
#endif // PRUEBAS_H

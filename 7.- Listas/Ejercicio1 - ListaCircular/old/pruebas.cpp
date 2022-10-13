#include "pruebas.h"
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

    cout<<"El anterior al anterior del ultimo es: "  <<lista.elemento(lista.anterior(lista.anterior(ultimo(lista))))          <<endl;
    cout<<"El anterior al ultimo es: "  <<lista.elemento(lista.anterior(ultimo(lista)))                                       <<endl;
    cout<<"El ultimo es : "             <<lista.elemento(ultimo(lista))                                                       <<endl;
    cout<<"El siguiente al ultimo es: " <<lista.elemento(lista.siguiente(ultimo(lista)))                                      <<endl;
    cout<<"El siguiente del siguiente al ultimo es: " <<lista.elemento(lista.siguiente(lista.siguiente(ultimo(lista))))       <<endl;

    cout << endl;

    cout<<"El anterior al anterior del primero es: "  <<lista.elemento(lista.anterior(lista.anterior(lista.inipos())))     <<endl;
    cout<<"El anterior al primero es: "  <<lista.elemento(lista.anterior(lista.inipos()))                                  <<endl;
    cout<<"El primero es : "             <<lista.elemento(lista.inipos())                                                  <<endl;
    cout<<"El siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.inipos()))                                 <<endl;
    cout<<"El siguiente del siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.siguiente(lista.inipos())))  <<endl;


/*    cout<<"\tEl numero de elementos que tiene la lista es "<<lista.nElementos()                                             <<endl;
    cout << endl;

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
    while(lista.nElementos());

    cout<<"Se ha vaciado la lista"<<endl;*/
}
/*
template <typename T> void pruebas(ListaCirDobleSinCabecera<T>& lista)
{
    cout<<"Sea la lista circular doble sin cabecera:" <<endl;
    muestraLista(lista);
    cout<<endl;

    cout<<"El siguiente al tercero es: "<<lista.elemento(lista.siguiente(lista.buscar(3)))<<endl;
    cout<<"El anterior al segundo es: "  <<lista.elemento(lista.anterior(lista.buscar(2)))<<endl;
    cout<<"El siguiente del siguiente del tercero es: "<<lista.elemento(lista.siguiente(lista.siguiente(lista.buscar(3))))  <<endl;

    cout << endl;

    cout<<"El anterior al anterior del ultimo es: "  <<lista.elemento(lista.anterior(lista.anterior(ultimo(lista))))          <<endl;
    cout<<"El anterior al ultimo es: "  <<lista.elemento(lista.anterior(ultimo(lista)))                                       <<endl;
    cout<<"El ultimo es : "             <<lista.elemento(ultimo(lista))                                                       <<endl;
    cout<<"El siguiente al ultimo es: " <<lista.elemento(lista.siguiente(ultimo(lista)))                                      <<endl;
    cout<<"El siguiente del siguiente al ultimo es: " <<lista.elemento(lista.siguiente(lista.siguiente(ultimo(lista))))       <<endl;

    cout << endl;

    cout<<"El anterior al anterior del primero es: "  <<lista.elemento(lista.anterior(lista.anterior(lista.inipos())))     <<endl;
    cout<<"El anterior al primero es: "  <<lista.elemento(lista.anterior(lista.inipos()))                                  <<endl;
    cout<<"El primero es : "             <<lista.elemento(lista.inipos())                                                  <<endl;
    cout<<"El siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.inipos()))                                 <<endl;
    cout<<"El siguiente del siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.siguiente(lista.inipos())))  <<endl;


    cout<<"\tEl numero de elementos que tiene la lista es "<<lista.nElementos()                                             <<endl;
    cout << endl;

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
    while(lista.nElementos());

    cout<<"Se ha vaciado la lista"<<endl;
}

template <typename T> void pruebas(ListaCirDobleConCabecera<T>& lista)
{
    cout<<"Sea la lista circular doble con cabecera:" <<endl;
    muestraLista(lista);
    cout<<endl;

    cout<<"El siguiente al tercero es: "<<lista.elemento(lista.siguiente(lista.buscar(3)))<<endl;
    cout<<"El anterior al segundo es: "  <<lista.elemento(lista.anterior(lista.buscar(2)))<<endl;
    cout<<"El siguiente del siguiente del tercero es: "<<lista.elemento(lista.siguiente(lista.siguiente(lista.buscar(3))))  <<endl;

    cout << endl;

    cout<<"El anterior al anterior del ultimo es: "  <<lista.elemento(lista.anterior(lista.anterior(ultimo(lista))))          <<endl;
    cout<<"El anterior al ultimo es: "  <<lista.elemento(lista.anterior(ultimo(lista)))                                       <<endl;
    cout<<"El ultimo es : "             <<lista.elemento(ultimo(lista))                                                       <<endl;
    cout<<"El siguiente al ultimo es: " <<lista.elemento(lista.siguiente(ultimo(lista)))                                      <<endl;
    cout<<"El siguiente del siguiente al ultimo es: " <<lista.elemento(lista.siguiente(lista.siguiente(ultimo(lista))))       <<endl;

    cout << endl;

    cout<<"El anterior al anterior del primero es: "  <<lista.elemento(lista.anterior(lista.anterior(lista.inipos())))     <<endl;
    cout<<"El anterior al primero es: "  <<lista.elemento(lista.anterior(lista.inipos()))                                  <<endl;
    cout<<"El primero es : "             <<lista.elemento(lista.inipos())                                                  <<endl;
    cout<<"El siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.inipos()))                                 <<endl;
    cout<<"El siguiente del siguiente al primero es: " <<lista.elemento(lista.siguiente(lista.siguiente(lista.inipos())))  <<endl;


    cout<<"\tEl numero de elementos que tiene la lista es "<<lista.nElementos()                                             <<endl;
    cout << endl;

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
    while(lista.nElementos());

    cout<<"Se ha vaciado la lista"<<endl;
}
*/
typename listaCircular<int>::posicion ultimo(listaCircular<int> lista)
{
    typename listaCircular<int >::posicion pos = lista.inipos();
    auto q = pos;
        for (; q->sig!=pos;q = q->sig);
        return q;
}


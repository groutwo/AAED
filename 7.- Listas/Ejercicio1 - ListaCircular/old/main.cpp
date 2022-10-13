#include "pruebas.h"
#include "E_S_Listas.h"

int main()
{
    listaCircular<int> lista1;
   /* ListaCirDobleSinCabecera<int>lista2;
    ListaCirDobleConCabecera<int>lista3;*/

    typename listaCircular<int>::posicion p = lista1.inipos() ;
    lista1.insertar(3,p);
    lista1.insertar(7,lista1.siguiente(p));

    //inicializa(lista1);
   /* inicializa(lista2);
    inicializa(lista3);*/

    muestraLista(lista1);

    // pruebas(lista1);
   /* pruebas(lista2);
    pruebas(lista3);*/

    return 0;
}

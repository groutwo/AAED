#include <iostream>
#include "Bicola.h"
using namespace std;

int main()
{
    Bicola<char> pila;

    pila.pushPila('H');
    pila.pushPila('o');
    pila.pushPila('l');
    pila.pushPila('a');
    muestraBicola(pila);
}

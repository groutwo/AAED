#include <iostream>
#include "operaciones.h"
using namespace std;

void avanzar(Pila<char>& P1, Pila<char>& P2)
{
    if(!P2.vacia()) P1.push(P2.tope()),P2.pop();
}

void retroceder(Pila<char>& P1, Pila<char>& P2)
{
    if(!P1.vacia()) P2.push(P1.tope()),P1.pop();
}

void principio(Pila<char>& Pila1, Pila<char>& Pila2)
{
    while(!Pila1.vacia())Pila2.push(Pila1.tope()), Pila1.pop();
}

void fin(Pila<char>& Pila1, Pila<char>& Pila2)
{
    while(!Pila2.vacia())Pila1.push(Pila2.tope()), Pila2.pop();
}

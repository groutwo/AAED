#ifndef BicolaEnlazada
#define BicolaEnlanzada

#include "Pila.h"
#include "Cola.h"

template<typename tEle> class Bicola
{
public:
    void popCola();
    void popPila();
    void pushCola(const tEle& x);
    void pushPila(const tEle& x);
    tEle primerElemento();
    tEle ultimoElemento();
    void muestraBicola();
    /**
    Bicola(const Pila<tEle>&);
    Bicola<tEle>& operator =(const Pila<tEle>&);
    Bicola(const Cola<tEle>&);
    Bicola<tEle>& operator =(const Cola<tEle>&);
    */
private:
 struct nodo
    {
        tEle elemento;
        nodo* sig;
        nodo(const tEle& e,nodo* p=0):
            elemento(e),sig(p){}
    };
    nodo *inicio, *fin;
    void copiar(const Cola<tEle>&);
};

template <typename tEle> void Bicola<tEle>::popCola()
{
    Cola<tEle> cola = (Cola<tEle>)*this;
    cola.pop();
    *this = cola;
}

template <typename tEle> void Bicola<tEle>::popPila()
{
    Pila<tEle> pila = (Pila<tEle>)*this;
    pila.pop();
    *this = pila;
}

template <typename tEle> void Bicola<tEle>::pushCola(const tEle& x)
{
    Cola<tEle> cola = (Cola<tEle>)*this;
    cola.push(x);
    *this = cola;
}

template <typename tEle> void Bicola<tEle>::pushPila(const tEle& x)
{
    Pila<tEle> pila = (Pila<tEle>)*this;
    pila.push(x);
    *this = pila;
}

template <typename tEle> tEle Bicola<tEle>::primerElemento()
{
    Cola<tEle> cola = (Cola<tEle>)*this;
    return cola.frente();
}

template <typename tEle> tEle Bicola<tEle>::ultimoElemento()
{
    Pila<tEle> pila = (Pila<tEle>)*this;
    return pila.tope();
}

template <typename tEle> void Bicola<tEle>::muestraBicola()
{
    Cola<tEle> cola = (Cola<tEle>)*this;
    muestraCola(cola);
}

/**
template <typename tEle>
Bicola<tEle>::Bicola(const Pila<tEle>& P) : tope_(0) { copiar(P); }

template <typename tEle>
Bicola<tEle>& Bicola<tEle>::operator =(const Pila<tEle>& P)
{if (this != &P) this->~Pila(), copiar(P); return *this; }


template <typename tEle>
Bicola<tEle>::Bicola(const Cola<tEle>& C):inicio(0),fin(0){copiar(C);}

template <typename tEle>
Bicola<tEle>& Bicola<tEle>::operator =(const Cola<tEle>& C)
{if (this != &C) this->~Cola(), copiar(C); return *this; }
*/
#endif // BicolaEnlazada

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <cassert>

#define A system("pause");

using namespace std;
template <typename T> class listaCircular
{
    struct nodo;
public:
    typedef nodo* posicion;
    listaCircular();
    listaCircular(const listaCircular<T>& l);
    listaCircular<T>& operator =(const listaCircular<T>& l);
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion buscar(const T& x) const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion inipos() const;
    ~listaCircular();
private:
    struct nodo
    {
        T elto;
        nodo *ant, *sig;
        nodo(const T& e, nodo* a = 0, nodo* s = 0) :
            elto(e), ant(a), sig(s) {}
    };
    nodo* primerNodo;
    void copiar(const listaCircular<T>& l);
};


// Métodos privado
template <typename T>void listaCircular<T>::
copiar(const listaCircular<T> &l)
{
    primerNodo = new nodo();
    primerNodo->ant = primerNodo->sig = primerNodo;
    for (nodo* q = l.primerNodo->sig; q != l.primerNodo; q = q->sig)
        primerNodo->ant = primerNodo->ant->sig = new nodo(q->elto, primerNodo->ant, primerNodo);
}


template <typename T> inline listaCircular<T>::
listaCircular() :  primerNodo {nullptr} { }


template <typename T> inline listaCircular<T>::
listaCircular(const listaCircular<T>& l)
{ copiar(l); }


template <typename T> listaCircular<T>& listaCircular<T>::
operator =(const listaCircular<T>& l)
{ if (this != &l) this->~listaCircular(), copiar(l);
    return *this;
}


template <typename T> inline void listaCircular<T>::
insertar(const T& x, listaCircular<T>::posicion p)
{
    if (primerNodo == nullptr)
    {
        cout<<"El primer nodo es nulo"<<endl;
        primerNodo = new nodo (x);
        primerNodo->ant = primerNodo;
        primerNodo->sig = primerNodo;
        cout<<"Hemos creado el primer nodo"<<endl;
    }
    else
    {
        cout<<"Insertamos en una posicion intermedia"<<endl;
        nodo* nuevo = new nodo(x, p->ant, p);
        p->ant->sig = nuevo;
        p->ant = nuevo;
    }
}


template <typename T> inline void listaCircular<T>::
eliminar(listaCircular<T>::posicion q)
{
    nodo* p = q->ant;
    nodo* r = q->sig;
    p->sig = r;
    r->ant = p;
    q=nullptr;
}


template <typename T> inline const T& listaCircular<T>::
elemento(listaCircular<T>::posicion p) const
{ return p->elto; }

template <typename T> inline T& listaCircular<T>::
elemento(listaCircular<T>::posicion p)
{ return p->elto; }

template <typename T> typename listaCircular<T>::posicion listaCircular<T>::
buscar(const T& x) const
{
    nodo* q = primerNodo;
    bool encontrado = false;
    while (q->sig != primerNodo && !encontrado)
        if (q->elto == x)
            return q;
        else q = q->sig;
    return nullptr;
}


template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
siguiente(listaCircular<T>::posicion p) const
{   cout<<"Aqui hemos llamado al siguiente cuando p vale: ";
    cout<<p->elto<<endl;
    cout<<"Vamos al siguiente"<<endl; return p->sig; }

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
anterior(listaCircular<T>::posicion p) const
{ return p->ant; }

template <typename T> inline typename listaCircular<T>:: posicion listaCircular<T>::
inipos() const { return primerNodo; }



template <typename T> listaCircular<T>::
~listaCircular()
{
    nodo* nodoAux;
    while (primerNodo->sig != primerNodo)
        nodoAux= primerNodo->sig,
        primerNodo->sig = nodoAux->sig,
           delete nodoAux;
    delete primerNodo;
}
#endif // LISTACIRCULAR_H



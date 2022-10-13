#ifndef listaCircular_HPP
#define listaCircular_HPP
#include <cassert>
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
    posicion inipos() const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    int nElementos();
    ~listaCircular();
private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T& e, nodo* s = nullptr) :
            elto(e), sig(s) {}
    };
    const int POS_NULA = 0;
    nodo* cabecera;
    void copiar(const listaCircular<T>& l);
};


// Métodos privado
template <typename T>void listaCircular<T>::
copiar(const listaCircular<T> &l)
{
    cabecera = new nodo(T());
    nodo* nDestino = cabecera;
    nodo* nOrigen = l.cabecera->sig;
    while ( nOrigen )
    {
        nDestino->sig = new nodo(nOrigen->elto);
        nDestino = nDestino->sig;
        nOrigen = nOrigen->sig;
    }
}


template <typename T> inline listaCircular<T>::
listaCircular() : cabecera(new nodo(T())) { }


template <typename T> inline listaCircular<T>::
listaCircular(const listaCircular<T>& l)
{
    copiar(l);
}


template <typename T> listaCircular<T>& listaCircular<T>::
operator =(const listaCircular<T>& l)
{
    if (this != &l)
        this->~listaCircular(), copiar(l);
    return *this;
}


template <typename T> inline void listaCircular<T>::
insertar(const T& x, listaCircular<T>::posicion p)
{

    if(p->sig==nullptr) //Insertamos en una lista vacia
    {
        p->sig  = new nodo (x,p);
        cout<<"Insertamos en una lista vacia"<<endl;
    }
    else
    {
        p->sig =  new nodo (x, cabecera->sig);
        cout<<"Insertamos en una lista que no esta vacia"<<endl;
    }
}

template <typename T> inline void listaCircular<T>::
eliminar(listaCircular<T>::posicion p)
{
    assert(cabecera!=0);
    nodo* q;
    if(cabecera->sig!=cabecera)
        q = p->sig,
        p->sig = q->sig,
           delete q;
    else
        q=cabecera,
        delete q,
        cabecera=0;
}


template <typename T> inline const T& listaCircular<T>::
elemento(listaCircular<T>::posicion p) const
{
    assert(p->sig); // p no es fin
    cout<<"no se usa"<<endl;
    return p->sig->elto;
}

template <typename T> inline T& listaCircular<T>::
elemento(listaCircular<T>::posicion p)
{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T> typename listaCircular<T>:: posicion listaCircular<T>::
buscar(const T& x) const
{
    nodo* q = cabecera;
    bool encontrado = POS_NULA; //POS_NULA = 0; 0 es falso
    while (q->sig != inipos() && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    return q;
}


template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
siguiente(listaCircular<T>::posicion p) const
{
    assert(p->sig); // p no es fin

    cout<<"--El elemento en la pos p es " <<   p->elto<<endl;
    cout<<"--El elemento siguiente de p es " <<p->sig->elto<<endl;
    return p->sig;
}

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
anterior(listaCircular<T>::posicion p) const
{
    assert(p==inipos()); //Comprobamos que la lista no esté vacía

    if(p == p->sig)
    {
        cout<<"La lista solo tiene un elemento"<<endl;
        return p;
    }

    nodo* q = cabecera;
    if(p == cabecera->sig) //estoy en el utlimo
        return cabecera->sig;//Devolvemos el primer elemento de la lista
        //for (q = cabecera->sig; q->sig != cabecera; q = q->sig);
    else
    {
        while( q->sig != cabecera->sig )
            q = q->sig,
            system("pause"),
            cout<<"Entramos en el while de anterior"<<endl;
    }
    return q;
}

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
inipos() const
{
    return cabecera;
}


template <typename T> int listaCircular<T>::
nElementos()
{
    int cont = 0;
    posicion p = inipos();
    while(p->sig != inipos())
        ++cont;
    return cont;
}

template <typename T> listaCircular<T>::
~listaCircular()
{
    nodo* q;
    while (cabecera)
    {
        q = cabecera->sig,
        delete cabecera;
        cabecera = q;
    }
}

#endif // listaCircular_HPP


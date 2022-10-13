#ifndef ListaCirDobleSinCabecera_SIMPE_H
#define ListaCirDobleSinCabecera_SIMPE_H
#include <cassert>
using namespace std;
template <typename T> class ListaCirDobleSinCabecera
{
    struct nodo;
public:
    typedef nodo* posicion;
    ListaCirDobleSinCabecera();
    ListaCirDobleSinCabecera(const ListaCirDobleSinCabecera<T>& l);
    ListaCirDobleSinCabecera<T>& operator =(const ListaCirDobleSinCabecera<T>& l);
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion buscar(const T& x) const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion inipos() const;
    posicion ultimo() const;
    ~ListaCirDobleSinCabecera();
    int nElementos();
private:
    struct nodo
    {
        T elto;
        nodo *ant, *sig;
        nodo(const T& e, nodo* a = nullptr, nodo* s = nullptr) :
            elto(e), ant(a), sig(s) {}
    };
    int nElementos_;
    nodo* L;
    void copiar(const ListaCirDobleSinCabecera<T>& l);
};


// Métodos privado
template <typename T>void ListaCirDobleSinCabecera<T>::
copiar(const ListaCirDobleSinCabecera<T> &l)
{
    L = new nodo(T());
    L->ant = L->sig = L;
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}


template <typename T> inline ListaCirDobleSinCabecera<T>::
ListaCirDobleSinCabecera() : L(new nodo(T()))
{
    L->ant = L->sig = L;
    nElementos_=0;
}


template <typename T> inline ListaCirDobleSinCabecera<T>::
ListaCirDobleSinCabecera(const ListaCirDobleSinCabecera<T>& l)
{
    copiar(l);
}


template <typename T> ListaCirDobleSinCabecera<T>& ListaCirDobleSinCabecera<T>::
operator =(const ListaCirDobleSinCabecera<T>& l)
{
    if (this != &l)
        this->~ListaCirDobleSinCabecera(), copiar(l);
    return *this;
}


template <typename T> inline void ListaCirDobleSinCabecera<T>::
insertar(const T& x, ListaCirDobleSinCabecera<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    inipos()->ant = inipos()->ant->ant;
}


template <typename T> inline void ListaCirDobleSinCabecera<T>::
eliminar(ListaCirDobleSinCabecera<T>::posicion q)
{
    nodo* p = q->ant;
    nodo* r = q->sig;
    p->sig = r;
    r->ant = p;
    q=nullptr;
}


template <typename T> inline const T& ListaCirDobleSinCabecera<T>::
elemento(ListaCirDobleSinCabecera<T>::posicion p) const
{
    return p->sig->elto;
}

template <typename T> inline T& ListaCirDobleSinCabecera<T>::
elemento(ListaCirDobleSinCabecera<T>::posicion p)
{
    return p->sig->elto;
}

template <typename T> typename ListaCirDobleSinCabecera<T>:: posicion ListaCirDobleSinCabecera<T>::
buscar(const T& x) const
{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    return q;
}


template <typename T> inline typename ListaCirDobleSinCabecera<T>::posicion ListaCirDobleSinCabecera<T>::
siguiente(ListaCirDobleSinCabecera<T>::posicion p) const
{
    if(p->sig == inipos())
        return p->sig->sig;
    return p->sig;
}

template <typename T> inline typename ListaCirDobleSinCabecera<T>::posicion ListaCirDobleSinCabecera<T>::
anterior(ListaCirDobleSinCabecera<T>::posicion p) const
{
    if(p->sig==inipos()) return inipos()->ant;
    return p->ant;
}

template <typename T> inline typename ListaCirDobleSinCabecera<T>:: posicion ListaCirDobleSinCabecera<T>::
inipos() const { return L; }

template <typename T> inline typename ListaCirDobleSinCabecera<T>:: posicion ListaCirDobleSinCabecera<T>::
ultimo() const
{
    return L->ant;
}

template <typename T>int ListaCirDobleSinCabecera<T>::
nElementos()
{
    int cont = 0;
    posicion p = inipos();
    while(p->sig != inipos())
        ++cont;
    return cont;
}

template <typename T> ListaCirDobleSinCabecera<T>::
~ListaCirDobleSinCabecera()
{
    nodo* q;
    while (L->sig != L)
        q = L->sig,
        L->sig = q->sig,
           delete q;
    delete L;
}
#endif // ListaCirDobleSinCabecera_SIMPE_H



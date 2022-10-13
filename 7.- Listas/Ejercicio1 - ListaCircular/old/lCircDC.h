#ifndef ListaCirDobleConCabecera_HPP
#define ListaCirDobleConCabecera_HPP
#include <cassert>
using namespace std;
template <typename T> class ListaCirDobleConCabecera
{
    struct nodo;
public:
    typedef nodo* posicion;
    ListaCirDobleConCabecera();
    ListaCirDobleConCabecera(const ListaCirDobleConCabecera<T>& l);
    ListaCirDobleConCabecera<T>& operator =(const ListaCirDobleConCabecera<T>& l);
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion buscar(const T& x) const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion inipos() const;
    posicion ultimo() const;
    ~ListaCirDobleConCabecera();
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
    void copiar(const ListaCirDobleConCabecera<T>& l);
};


// Métodos privado
template <typename T>void ListaCirDobleConCabecera<T>::
copiar(const ListaCirDobleConCabecera<T> &l)
{
    L = new nodo(T());
    L->ant = L->sig = L;
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}


template <typename T> inline ListaCirDobleConCabecera<T>::
ListaCirDobleConCabecera() : L(new nodo(T()))
{
    L->ant = L->sig = L;
    nElementos_=0;
}


template <typename T> inline ListaCirDobleConCabecera<T>::
ListaCirDobleConCabecera(const ListaCirDobleConCabecera<T>& l)
{
    copiar(l);
}


template <typename T> ListaCirDobleConCabecera<T>& ListaCirDobleConCabecera<T>::
operator =(const ListaCirDobleConCabecera<T>& l)
{
    if (this != &l)
        this->~ListaCirDobleConCabecera(), copiar(l);
    return *this;
}


template <typename T> inline void ListaCirDobleConCabecera<T>::
insertar(const T& x, ListaCirDobleConCabecera<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    inipos()->ant = inipos()->ant->ant;
}


template <typename T> inline void ListaCirDobleConCabecera<T>::
eliminar(ListaCirDobleConCabecera<T>::posicion q)
{
    nodo* p = q->ant;
    nodo* r = q->sig;
    p->sig = r;
    r->ant = p;
    q=nullptr;
}


template <typename T> inline const T& ListaCirDobleConCabecera<T>::
elemento(ListaCirDobleConCabecera<T>::posicion p) const
{
    return p->sig->elto;
}

template <typename T> inline T& ListaCirDobleConCabecera<T>::
elemento(ListaCirDobleConCabecera<T>::posicion p)
{
    return p->sig->elto;
}

template <typename T> typename ListaCirDobleConCabecera<T>:: posicion ListaCirDobleConCabecera<T>::
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


template <typename T> inline typename ListaCirDobleConCabecera<T>::posicion ListaCirDobleConCabecera<T>::
siguiente(ListaCirDobleConCabecera<T>::posicion p) const
{
    if(p->sig == inipos())
        return p->sig->sig;
    return p->sig;
}

template <typename T> inline typename ListaCirDobleConCabecera<T>::posicion ListaCirDobleConCabecera<T>::
anterior(ListaCirDobleConCabecera<T>::posicion p) const
{
    if(p->sig==inipos()) return inipos()->ant->ant;
    return p->ant;
}

template <typename T> inline typename ListaCirDobleConCabecera<T>:: posicion ListaCirDobleConCabecera<T>::
inipos() const
{
    return L;
}

template <typename T> inline typename ListaCirDobleConCabecera<T>:: posicion ListaCirDobleConCabecera<T>::
ultimo() const
{
    return L->ant;
}

template <typename T> int ListaCirDobleConCabecera<T>::
nElementos()
{
    int cont = 0;
    posicion p = inipos();
    while(p->sig != inipos())
        ++cont;
    return cont;
}

template <typename T> ListaCirDobleConCabecera<T>::
~ListaCirDobleConCabecera()
{
    nodo* q;
    while (L->sig != L)
        q = L->sig,
        L->sig = q->sig,
           delete q;
    delete L;
}
#endif // ListaCirDobleConCabecera_HPP



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
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    ~listaCircular();
    void mostrarLista(int pos = 0);
    int nElementos(){return nElementos_;}
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
    void copiar(const listaCircular<T>& l);
};


// Métodos privado
template <typename T>void listaCircular<T>::
    copiar(const listaCircular<T> &l)
{   L = new nodo(T());
    L->ant = L->sig = L;
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}


template <typename T> inline listaCircular<T>::
    listaCircular() : L(new nodo(T()))
{ L->ant = L->sig = L; nElementos_=0;}


template <typename T> inline listaCircular<T>::
    listaCircular(const listaCircular<T>& l)
{ copiar(l); }


template <typename T> listaCircular<T>& listaCircular<T>::
    operator =(const listaCircular<T>& l)
{   if (this != &l)
        this->~listaCircular(), copiar(l);
    return *this;
}


template <typename T> inline void listaCircular<T>::
    insertar(const T& x, listaCircular<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    primera()->ant = fin()->ant;
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
{ return p->sig->elto; }

template <typename T> inline T& listaCircular<T>::
    elemento(listaCircular<T>::posicion p)
{ return p->sig->elto; }

template <typename T> typename listaCircular<T>:: posicion listaCircular<T>::
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


template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
    siguiente(listaCircular<T>::posicion p) const
{
    if(p->sig == primera())
        return p->sig->sig;
    return p->sig;
}

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
    anterior(listaCircular<T>::posicion p) const
{
    if(p->sig==primera()) return fin();
    return p->ant;
}

template <typename T> inline typename listaCircular<T>:: posicion listaCircular<T>::
    primera() const
{ return L; }

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
    fin() const
{ return L->ant; }


template <typename T> listaCircular<T>::
    ~listaCircular()
{
    nodo* q;
    while (L->sig != L)
        q = L->sig,
        L->sig = q->sig,
        delete q;
    delete L;
}

template <typename T> inline void listaCircular<T>::
    mostrarLista(int pos)
{
    listaCircular<T>::posicion p = buscar(pos);
    int nElementosLocal = nElementos();
    while(nElementosLocal)
    {
        --nElementosLocal;
        std::cout<<"Con i="<<elemento(buscar(p->elto))
        <<" Su anterior es "<<elemento(anterior(buscar(p->elto)))
        <<" Su siguiente es "<<elemento(siguiente(buscar(p->elto)))<<std::endl;
        p=p->sig;
         if(elemento(buscar(p->elto)) == 0) p=p->sig;
    }
}
#endif // listaCircular_HPP


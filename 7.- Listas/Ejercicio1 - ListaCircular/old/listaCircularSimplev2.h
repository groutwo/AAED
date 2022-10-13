#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <cassert>

using namespace std;
template <typename T> class listaCircular
{
    struct nodo; // declaración adelantada privada
public:
    typedef nodo* posicion; // posición de un elemento
    listaCircular(); // constructor, requiere ctor. T()
    listaCircular(const listaCircular<T>& l); // ctor. de copia, requiere ctor. T()
    listaCircular<T>& operator =(const listaCircular<T>& l); // asignación de listaCirculars
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion inipos() const;
    posicion fin() const; // posición después del último
    ~listaCircular(); // destructor
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = nullptr): elto(e), sig(p) {}
    };
    nodo* L; // listaCircular enlazada de nodos
    void copiar(const listaCircular<T>& l);
};

// Método privado
template <typename T> void listaCircular<T>::
copiar(const listaCircular<T> &l)
{
    L = new nodo(T()); // crear el nodo cabecera
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig)
    {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T> inline listaCircular<T>::
listaCircular() : L(new nodo(T())) // crear cabecera {}
{ }

template <typename T> inline listaCircular<T>::
listaCircular(const listaCircular<T>& l)
{
    copiar(l);
}

template <typename T> listaCircular<T>& listaCircular<T>::
operator =(const listaCircular<T>& l)
{
    if (this != &l)   // evitar autoasignación
    {
        this->~listaCircular(); // vaciar la listaCircular actual
        copiar(l);
    }
    return *this;
}

template <typename T> inline void listaCircular<T>::
insertar(const T& x, listaCircular<T>::posicion p)
{
    if(p==L)
    {
        nodo* nuevo = new nodo(x);
        nuevo ->sig = nuevo ;
        p->sig = nuevo ;
    }
    if(p==fin())
        p->sig = new nodo(x, L->sig);
    else
        p->sig = new nodo (x, p->sig);


// el nuevo nodo con x queda en la posición p
}

template <typename T> inline void listaCircular<T>::
eliminar(listaCircular<T>::posicion p)
{
    assert(p->sig); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
// el nodo siguiente queda en la posición p
}

template <typename T> inline const T& listaCircular<T>::
elemento(listaCircular<T>::posicion p) const
{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T> inline T& listaCircular<T>::
elemento(listaCircular<T>::posicion p)
{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T> typename listaCircular<T>::posicion listaCircular<T>::
buscar(const T& x) const
{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    return q;
}

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
siguiente(listaCircular<T>::posicion p) const
{
    assert(p->sig); // p no es fin
    return p->sig;
}

template <typename T> typename listaCircular<T>::posicion listaCircular<T>::
anterior(listaCircular<T>::posicion p) const
{
    /*nodo* q;
    cout<<"fwfewfwef";
    assert(p!=L);

    if(p->sig == L) // Si p es la cabecera, devolvemos el ultimo
    {
        cout<<"p->sig==L"<<endl;
        for (q = L; q->sig != L; q = q->sig);
    }
    else
    {
        cout<<"p==L"<<endl;
        for (q = L; q->sig != p; q = q->sig);
    }
    return q;*/
    nodo* q;
    assert(p != L); // p no es la primera posición
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T> inline typename listaCircular<T>::posicion listaCircular<T>::
inipos() const
{
    return L;
}

template <typename T> typename listaCircular<T>::posicion listaCircular<T>::
fin() const
{
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

// Destructor: destruye el nodo cabecera y vacía la listaCircular
template <typename T> listaCircular<T>::
~listaCircular()
{
    nodo* q;
    while (L)
    {
        q = L->sig;
        delete L;
        L = q;
    }
}
#endif // listaCircular_ENLA_H

#ifndef LISTA_ENLA_H
#define LISTA_ENLA_H
#include <cassert>
template <typename T> class Lista
{
    struct nodo; // declaración adelantada privada
public:
    typedef nodo* posicion; // posición de un elemento
    Lista(); // constructor, requiere ctor. T()
    Lista(const Lista<T>& l); // ctor. de copia, requiere ctor. T()
    Lista<T>& operator =(const Lista<T>& l); // asignación de
    listas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~Lista(); // destructor
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = ): elto(e), sig(p) {}
    };
    nodo* L; // lista enlazada de nodos
    void copiar(const Lista<T>& l);
};

// Método privado
template <typename T> void Lista<T>::
copiar(const Lista<T> &l)
{
    L = new nodo(T()); // crear el nodo cabecera
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig)
    {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T> inline Lista<T>::
Lista() : L(new nodo(T())) // crear cabecera {}

    template <typename T> inline Lista<T>::
    Lista(const Lista<T>& l)
{
    copiar(l);
}

template <typename T> Lista<T>& Lista<T>::
operator =(const Lista<T>& l)
{
    if (this != &l)   // evitar autoasignación
    {
        this->~Lista(); // vaciar la lista actual
        copiar(l);
    }
    return *this;
}

template <typename T> inline void Lista<T>::
insertar(const T& x, Lista<T>::posicion p)
{
    p->sig = new nodo(x, p->sig);
// el nuevo nodo con x queda en la posición p
}

template <typename T> inline void Lista<T>::
eliminar(Lista<T>::posicion p)
{
    assert(p->sig); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
// el nodo siguiente queda en la posición p
}

template <typename T> inline const T& Lista<T>::
elemento(Lista<T>::posicion p) const
{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T> inline T& Lista<T>::
elemento(Lista<T>::posicion p)
{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T> typename Lista<T>::posicion Lista<T>::
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

template <typename T> inline typename Lista<T>::posicion Lista<T>::
siguiente(Lista<T>::posicion p) const
{
    assert(p->sig); // p no es fin
    return p->sig;
}

template <typename T> typename Lista<T>::posicion Lista<T>::
anterior(Lista<T>::posicion p) const
{
    nodo* q;
    assert(p != L); // p no es la primera posición
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::
primera() const
{
    return L;
}

template <typename T> typename Lista<T>::posicion Lista<T>::
fin() const
{
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

// Destructor: destruye el nodo cabecera y vacía la lista
template <typename T> Lista<T>::
~Lista()
{
    nodo* q;
    while (L)
    {
        q = L->sig;
        delete L;
        L = q;
    }
}
#endif // LISTA_ENLA_H

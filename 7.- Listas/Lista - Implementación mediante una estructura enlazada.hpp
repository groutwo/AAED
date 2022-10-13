template <typename T> class Lista
{
    struct nodo; // declaración adelantada privada
public:
    typedef nodo* posicion; // posición de un elemento
    Lista(); // constructor
    void insertar(const T& x, posicion& p);
    void eliminar(posicion& p);
// ......
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(T e, nodo* p = 0): elto(e), sig(p) {}
    };
    nodo* L; // lista enlazada de nodos
    void copiar(const Lista<T>& l);
};

template <typename T> inline Lista<T>::
Lista() : L(0) {}

/** v1
template <typename T> void Lista<T>::
    insertar(const T& x, Lista<T>::posicion& p)
{
    nodo* q;
    if (p == L) // inserción al principio
        p = L = new nodo(x, p);
    else   // inserción en cualquier otra posición, incluso fin
    {
// recorrer la lista hasta el nodo q anterior a p
        for (q = L; q->sig != p; q = q->sig);
        p = q->sig = new nodo(x, p);
    }
// el nuevo nodo con x queda en la posición p
}
*/

template <typename T> void Lista<T>::
eliminar(Lista<T>::posicion& p)
{
    nodo* q;
    assert(p); // p no es fin
    if (p == L)   /* primera posición */
    {
        L = p->sig;
        delete p;
        p = L;
    }
    else
    {
// recorrer la lista hasta el nodo q anterior a p
        for (q = L; q->sig != p; q = q->sig);
        q->sig = p->sig;
        delete p;
        p = q->sig;
    }
// el nodo siguiente queda en la posición p
}

template <typename T> void Lista<T>::
insertar(const T& x, Lista<T>::posicion& p)
{
    nodo* q;
    if (p)   // p no es fin
    {
        q = new nodo(p->elto, p->sig); // copia *p en *q
        p->elto = x;
        p->sig = q;
    }
    else // inserción al final
        if (L == 0) // lista vacía
            p = L = new nodo(x);
        else
        {
// recorrer la lista hasta el último nodo
            for (q = L; q->sig; q = q->sig);
            q->sig = new nodo(x);
            p = q;
        }
}

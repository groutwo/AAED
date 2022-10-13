#ifndef ListaOrdenada_H
#define ListaOrdenada_H
#include <cassert>

template <typename T> class ListaOrdenada
{
    struct nodo; // declaración adelantada privada
public:
    typedef nodo* posicion; // posición de un elemento
    ListaOrdenada(); // constructor, requiere ctor. T()
    ListaOrdenada(const ListaOrdenada<T>& l); // ctor. de copia, requiere ctor. T()
    ListaOrdenada<T>& operator =(const ListaOrdenada<T>& l); // asignación entre ListaOrdenadas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    //const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~ListaOrdenada(); // destructor
    void mostrarLista(int pos = 0);
    int nElementos(){return nElementos_;}
private:
    struct nodo
    {
        T elto;
        nodo *ant, *sig;
        nodo(const T& e=nullptr, nodo* a = nullptr, nodo* s = nullptr) :
            elto(e), ant(a), sig(s) {}
    };
    int nElementos_;
    nodo* L; // ListaOrdenada doblemente enlazada de nodos
    void copiar(const ListaOrdenada<T>& l);
};


// Método privado
template <typename T>
void ListaOrdenada<T>::copiar(const ListaOrdenada<T> &l)
{   L = new nodo(T()); // crear el nodo cabecera
    L->ant = L->sig = L; // estructura circular
        // Copiar elementos de l
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}


template <typename T>
inline ListaOrdenada<T>::ListaOrdenada() : L(new nodo(T())) // crear cabecera
{ L->ant = L->sig = L; nElementos_=0;/* estructura circular*/ }


template <typename T>
inline ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada<T>& l)
{ copiar(l); }


template <typename T>
ListaOrdenada<T>& ListaOrdenada<T>::operator =(const ListaOrdenada<T>& l)
{   if (this != &l)   // evitar autoasignación
        this->~ListaOrdenada(), // vaciar la ListaOrdenada actual
        copiar(l);
    return *this;
}


template <typename T> inline
void ListaOrdenada<T>::insertar(const T& x, ListaOrdenada<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    this->primera()->ant = this->fin()->ant;
    ++nElementos_;
// el nuevo nodo con x queda en la posición p
}


template <typename T>
inline void ListaOrdenada<T>::eliminar(ListaOrdenada<T>::posicion q)
{
    q = q->sig;
    nodo* p = q->ant;
    nodo* r = q->sig;

    p->sig = r;
    r->ant = p;
    // el nodo siguiente queda en la posición p
    --nElementos_;
}

/*
template <typename T> inline
const T& ListaOrdenada<T>::elemento(ListaOrdenada<T>::posicion p) const
{
    //assert(p->sig != L); // p no es fin
    return p->sig->elto;
}*/

template <typename T>
inline T& ListaOrdenada<T>::elemento(ListaOrdenada<T>::posicion p)
{
    //assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T>
typename ListaOrdenada<T>::posicion
ListaOrdenada<T>::buscar(const T& x) const
{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    return q;
}


template <typename T> inline
typename ListaOrdenada<T>::posicion
ListaOrdenada<T>::siguiente(ListaOrdenada<T>::posicion p) const
{
    if(p->sig == this->primera())
        return p->sig->sig;
    return p->sig;
}

template <typename T> inline
typename ListaOrdenada<T>::posicion
ListaOrdenada<T>::anterior(ListaOrdenada<T>::posicion p) const
{
    return p->ant;
}


template <typename T>
inline typename ListaOrdenada<T>::posicion ListaOrdenada<T>::primera() const
{ return L; }

template <typename T>
inline typename ListaOrdenada<T>::posicion ListaOrdenada<T>::fin() const
{ return L->ant; }


template <typename T>   // Destructor: Vacía la ListaOrdenada
ListaOrdenada<T>::~ListaOrdenada()      // y destruye el nodo cabecera
{nodo* q;
    while (L->sig != L)
        q = L->sig,
        L->sig = q->sig,
        delete q;
    delete L;
}

template <typename T>
inline void ListaOrdenada<T>::mostrarLista(int pos)
{
    ListaOrdenada<T>::posicion p = primera();

    while(p!=fin())
    {

        std::cout<<"Con i="<<pos<<":"<<elemento(buscar(pos))
        <<" Su anterior es "<<elemento(anterior(buscar(pos)))
        <<" Su siguiente es "<<elemento(siguiente(buscar(pos)))<<std::endl;
        pos++;
        p=p->sig;
    }
    std::cout<<"Con i="<<pos<<":"<<elemento(buscar(pos))
        <<" Su anterior es "<<elemento(anterior(buscar(pos)))
        <<" Su siguiente es "<<elemento(siguiente(buscar(pos)))<<std::endl;
}
#endif // ListaOrdenada

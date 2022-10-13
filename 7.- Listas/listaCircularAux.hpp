#ifndef ListaCir_DOBLE_H
#define ListaCir_DOBLE_H
#include <cassert>
using namespace std;
template <typename T> class ListaCir
{
    struct nodo; // declaración adelantada privada
public:
    typedef nodo* posicion; // posición de un elemento
    ListaCir(); // constructor, requiere ctor. T()
    ListaCir(const ListaCir<T>& l); // ctor. de copia, requiere ctor. T()
    ListaCir<T>& operator =(const ListaCir<T>& l); // asignación entre ListaCirs
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~ListaCir(); // destructor
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
    nodo* L; // ListaCir doblemente enlazada de nodos
    void copiar(const ListaCir<T>& l);
};


// Método privado
template <typename T>
void ListaCir<T>::copiar(const ListaCir<T> &l)
{   L = new nodo(T()); // crear el nodo cabecera
    L->ant = L->sig = L; // estructura circular
        // Copiar elementos de l
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}


template <typename T>
inline ListaCir<T>::ListaCir() : L(new nodo(T())) // crear cabecera
{ L->ant = L->sig = L; nElementos_=0;/* estructura circular*/ }


template <typename T>
inline ListaCir<T>::ListaCir(const ListaCir<T>& l)
{ copiar(l); }


template <typename T>
ListaCir<T>& ListaCir<T>::operator =(const ListaCir<T>& l)
{   if (this != &l)   // evitar autoasignación
        this->~ListaCir(), // vaciar la ListaCir actual
        copiar(l);
    return *this;
}


template <typename T> inline
void ListaCir<T>::insertar(const T& x, ListaCir<T>::posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    this->primera()->ant = this->fin()->ant;
    ++nElementos_;
// el nuevo nodo con x queda en la posición p
}


template <typename T>
inline void ListaCir<T>::eliminar(ListaCir<T>::posicion p)
{
   /**
    if(buscar(elemento(q))==L)
    return; //No hacemos nada porque no hay elemento en esa posicion
    q = q->sig;
    nodo* p = q->ant;
    nodo* r = q->sig;

    nodo* o = p->ant;
    nodo* s = r->sig;

    //o->sig = p;
    p->sig = r;
    r->ant = p;
    //r->sig = s;

    delete q;
    if (s->ant->elto==q->elto)
        s->ant->elto = elemento(fin()),
        cout<<"dqwd";
            cout<<o->ant->ant->elto<<" "<<o->ant->elto<<" "<<o->elto<<" "<<o->sig->elto<<" "<<o->sig->sig->elto<<endl;
    cout<<p->ant->ant->elto<<" "<<p->ant->elto<<" "<<p->elto<<" "<<p->sig->elto<<" "<<p->sig->sig->elto<<endl;
    cout<<q->ant->ant->elto<<" "<<q->ant->elto<<" "<<q->elto<<" "<<q->sig->elto<<" "<<q->sig->sig->elto<<endl;
    cout<<r->ant->ant->elto<<" "<<r->ant->elto<<" "<<r->elto<<" "<<r->sig->elto<<" "<<r->sig->sig->elto<<endl;
    cout<<s->ant->ant->elto<<" "<<s->ant->elto<<" "<<s->elto<<" "<<s->sig->elto<<" "<<s->sig->sig->elto<<endl;
    delete q;


    */


    --nElementos_;

    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;

    delete q;
}


template <typename T> inline /** no se usa */
const T& ListaCir<T>::elemento(ListaCir<T>::posicion p) const
{
    //assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T>
inline T& ListaCir<T>::elemento(ListaCir<T>::posicion p)
{
    //assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T>
typename ListaCir<T>::posicion
ListaCir<T>::buscar(const T& x) const
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
typename ListaCir<T>::posicion
ListaCir<T>::siguiente(ListaCir<T>::posicion p) const
{
    if(p->sig == primera())
        return p->sig->sig;
    return p->sig;
}

template <typename T> inline
typename ListaCir<T>::posicion
ListaCir<T>::anterior(ListaCir<T>::posicion p) const
{
    if(p->sig==primera()) return fin();
    return p->ant;
}


template <typename T>
inline typename ListaCir<T>::posicion ListaCir<T>::primera() const
{ return L; }

template <typename T>
inline typename ListaCir<T>::posicion ListaCir<T>::fin() const
{ return L->ant; }


template <typename T>   // Destructor: Vacía la ListaCir
ListaCir<T>::~ListaCir()      // y destruye el nodo cabecera
{nodo* q;
    while (L->sig != L)
        q = L->sig,
        L->sig = q->sig,
        delete q;
    delete L;
}

template <typename T>
inline void ListaCir<T>::mostrarLista(int pos)
{
    ListaCir<T>::posicion p = buscar(pos);
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
    /*std::cout<<"Con i="<<pos<<":"<<elemento(buscar(pos))
        <<" Su anterior es "<<elemento(anterior(buscar(pos)))
        <<" Su siguiente es "<<elemento(siguiente(buscar(pos)))<<std::endl;*/
}
#endif // ListaCir_DOBLE_H

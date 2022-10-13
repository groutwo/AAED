#ifndef PILA_ENLA_H
#define PILA_ENLA_H
#include <cassert>
using namespace std;
template <typename T>
class Pila
{
public:
    Pila(): tope_(0) {}; // constructor
    Pila(const Pila<T>& P); // ctor. de copia
    Pila<T>& operator =(const Pila<T>& P); // asignación
    bool vacia() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
    ~Pila(); // destructor
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0): elto(e), sig(p) {}
    };
    nodo* tope_;
    void copiar(const Pila<T>& P);
};


template <typename T>Pila<T>::Pila(const Pila<T>& P) : tope_(0)
{
    copiar(P);
}

template <typename T>Pila<T>& Pila<T>::operator =(const Pila<T>& P)
{
    if (this != &P)   // evitar autoasignación
    {
        this->~Pila(); // vaciar la pila actual
        copiar(P);
    }
    return *this;
}

template <typename T>inline bool Pila<T>::vacia() const
{
    return (!tope_);
}

template <typename T>inline const T& Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    delete p;
}

template <typename T>inline void Pila<T>::push(const T& x)
{
    tope_ = new nodo(x, tope_);
}

// Destructor: vacía la pila
template <typename T>Pila<T>::~Pila()
{
    nodo* p;
    while (tope_)
    {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}

// Método privado
template <typename T>void Pila<T>::copiar(const Pila<T>& P)
{
    if (!P.vacia())
    {
        tope_ = new nodo(P.tope()); // copiar el primer elto
        // Copiar el resto de elementos hasta el fondo de la pila.
        nodo* p = tope_; // recorre la pila destino
        nodo* q = P.tope_->sig; // 2º nodo, recorre la pila origen
        while (q)
        {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}

template <typename T> void muestraPila(Pila <T> P1)
{
    while(!P1.vacia())
        cout<<P1.tope()<<" ", P1.pop();
    cout << endl;

}

template <typename T> Pila<T> sumaPilas(const Pila <T>& P2, const Pila <T>& Q2)
{
    Pila<int> P = P2;
    Pila<int> Q=Q2;
    /*Invertimos las cadenas originales
        Pila<int> aux;
        while(!P.vacia()) aux.push(P.tope()),P.pop();
        P=aux;
        while(!aux.vacia())aux.pop();
        while(!Q.vacia()) aux.push(Q.tope()),Q.pop();
        Q=aux;
        while(!aux.vacia())aux.pop();
            */

    cout<<"La pila P es : ";
    muestraPila(P);

    cout<<"La pila Q es : ";
    muestraPila(Q);
    system("pause");

    bool ac= false;
    int auxInt;
    Pila<int> R;

    while(!P.vacia() || !Q.vacia())
    {
        if(!P.vacia() && !Q.vacia())
        {
            if(ac)
                R.push(1+P.tope()+Q.tope()), ac=false;
            else
                R.push(P.tope()+Q.tope());

            if(R.tope() >= 10)
                auxInt=R.tope()-10,
                ac = true,
                R.pop(),
                R.push(auxInt);
            P.pop(),Q.pop();
        }
        if(P.vacia())
            R.push(Q.tope()),Q.pop();

        if(Q.vacia())
            R.push(P.tope()),P.pop();

        cout<<"La pila P es : "; muestraPila(P);
        cout<<"La pila Q es : "; muestraPila(Q);
        cout<<"La pila R es : "; muestraPila(R);

        cout<<endl; system("pause");
    }
     cout<<"La pila R al acabar la funcion es : ";muestraPila(R);
    return R;
}
#endif

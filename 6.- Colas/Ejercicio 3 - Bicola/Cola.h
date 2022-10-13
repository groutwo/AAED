#ifndef ColaEnlazada
#define ColaEnlazada
#include <cassert>
using namespace std;
template <typename tEle> class Cola
{
public:
    Cola();
    Cola(const Cola<tEle>&); // ctor. de copia
    Cola<tEle>& operator =(const Cola<tEle>&); // asignación entre Cola
    bool vacia() const;
    const tEle& frente() const;
    void pop();
    void push(const tEle& x);
    ~Cola(); // destructor
private:
    struct nodo
    {
        tEle elemento;
        nodo* sig;
        nodo(const tEle& e,nodo* p=0):
            elemento(e),sig(p){}
    };
    nodo *inicio, *fin;
    void copiar(const Cola<tEle>&);
};

template <typename tEle> inline Cola<tEle>::Cola():inicio(0),fin(0){}

template <typename tEle>
Cola<tEle>::Cola(const Cola<tEle>& C):inicio(0),fin(0){copiar(C);}

template <typename tEle>
Cola<tEle>& Cola<tEle>::operator =(const Cola<tEle>& C)
{if (this != &C) this->~Cola(), copiar(C); return *this; }

template <typename tEle>
inline bool Cola<tEle>::vacia() const { return (inicio==0); }


template <typename tEle>
inline const tEle& Cola<tEle>::frente() const
{ assert(!vacia()); return inicio->elemento; }

template <typename tEle>
inline void Cola<tEle>::pop()
{ assert(!vacia()); nodo* p = inicio; inicio= p->sig;
    if(!inicio) fin = 0; delete p; }

template <typename tEle>
inline void Cola<tEle>::push(const tEle& x)
{nodo* p=new nodo(x); vacia()? inicio=fin=p : fin=fin->sig=p;}

template <typename tEle>
inline Cola<tEle>::~Cola()
{   nodo* p; fin = 0;
    while (inicio)
        p = inicio->sig, delete inicio, inicio = p;
}

template <typename tEle>
void Cola<tEle>::copiar(const Cola<tEle>&C)
{
    assert(!C.vacia());  // tambien vale (if(C.inicio)
    inicio = fin = new nodo (C.inicio->elemento);
    for(nodo *p=C.inicio->sig; p; p = p->sig)
        fin->sig = new nodo(p->elemento),
        fin = fin->sig;
}

template <typename T> void muestraCola(Cola <T> C)
{ while(!C.vacia())
        cout<<C.tope()<<" ", C.pop();
    cout<<endl;

}
#endif

#ifndef Bicola_
#define Bicola_
#include <cassert>
using namespace std;

template <typename tEle> class Bicola
{
public:
    Bicola();
    Bicola(const Bicola<tEle>&); // ctor. de copia
    Bicola<tEle>& operator =(const Bicola<tEle>&); // asignación entre pilas
    bool vacia() const;
    const tEle& topePila() const;
    void popPila();
    void pushPila(const tEle& x);
     const tEle& topeCola() const;
    void popCola();
    void pushCola(const tEle& x);
    ~Bicola(); // destructor
private:
    struct nodo
    {
        tEle elemento;
        nodo *ant, *sig;
        nodo(const tEle& e,nodo* a=nullptr,nodo* s=nullptr):
            elemento(e),ant(a),sig(s){}
    };
    nodo *inicio, *fin;
    void copiar(const Bicola<tEle>&);
};

template <typename tEle> inline Bicola<tEle>::Bicola():inicio(0),fin(0){}

template <typename tEle>
Bicola<tEle>::Bicola(const Bicola<tEle>& bicola):
     inicio(0),fin(0) { copiar(bicola); }

template <typename tEle>
Bicola<tEle>& Bicola<tEle>::operator =(const Bicola<tEle>& bicola)
{ if (this != &bicola) this->~Bicola(), copiar(bicola); return *this; }

template <typename tEle>
inline bool Bicola<tEle>::vacia() const { return (inicio==0); }


template <typename tEle>
inline const tEle& Bicola<tEle>::topePila() const
{ assert(!vacia()); return fin->elemento; }

template <typename tEle>
inline void Bicola<tEle>::popPila()
{ assert(!vacia());
    nodo* p = fin; fin = p->ant; delete p; fin->sig=0;
    if(!fin) inicio = 0; }

template <typename tEle>
inline void Bicola<tEle>::pushPila(const tEle& x)
{vacia()? inicio=fin=new nodo(x) : inicio=inicio->ant=new nodo (x,0,inicio); }


template <typename tEle>
inline const tEle& Bicola<tEle>::topeCola() const
{ assert(!vacia()); return inicio->elemento; }

template <typename tEle>
inline void Bicola<tEle>::popCola()
{ assert(!vacia());
    //system("pause");
    //muestraBicola(*this);
    nodo* p = inicio; inicio = p->sig;
     delete p; if(!inicio) fin = 0;
}

template <typename tEle>
inline void Bicola<tEle>::pushCola(const tEle& x)
{vacia()? inicio=fin=new nodo(x) : fin=fin->sig=new nodo(x,fin);}

template <typename tEle>
inline Bicola<tEle>::~Bicola()
{
    nodo* p; fin = 0;
    while (inicio) p = inicio->sig,
        delete inicio, inicio = p;

}

template <typename tEle>
void Bicola<tEle>::copiar(const Bicola<tEle>& bicola)
{
    if (bicola.inicio)   // bicola no está vacía
   {
    /// Copiar el primer elemento.
    inicio = fin = new nodo(bicola.inicio->elemento);
    /// Copiar el resto de elementos hasta el final de la cola.
    for (nodo *nodoActual = bicola.inicio->sig; nodoActual; )
        {
        fin =fin->sig = new nodo(nodoActual->elemento,nodoActual);

        nodoActual = nodoActual->sig;
        }
   }
}

template <typename tEle> void muestraBicola(Bicola <tEle> bicola)
{
    while(!bicola.vacia())
        cout<<bicola.topeCola()<<" ", bicola.popCola();
    cout<<endl;
}
#endif

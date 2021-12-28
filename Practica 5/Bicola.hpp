#ifndef _BICOLA_
#define _BICOLA_

#include <iostream>
#include <cassert>

template<typename T>
class Bicola
{
public:
    Bicola();
    Bicola(Bicola<T>& B);
    Bicola<T>& operator=(const Bicola<T>& B);
    bool vacia() const;
    T& frente() const;
    T& final() const;
    void pushFinal(const T& x);
    void pushFrente(const T& x);
    void popFrente();
    void popFinal();
    ~Bicola();
private:
    struct nodo
    {
        T elemento;
        nodo* sig;
        nodo(T e, nodo* p = nullptr):elemento(e),sig(p){};
    };

    nodo* inicio;
    nodo* fin;

    void Copiar(const Bicola& B);
};

template<typename T>
void Bicola<T>::Copiar(const Bicola& B)
{
    if(B.inicio != nullptr)
    {
        inicio = fin = new nodo(B.inicio->elemento);
        for (nodo* p = B.inicio->sig; p!= nullptr; p = p->sig)
        {
            fin->sig = new nodo(p->elemento);
            fin = fin->sig;
        }
    }
}

//Constructor
template<typename T>
Bicola<T>::Bicola() : inicio(nullptr), fin(nullptr){}

template<typename T>
Bicola<T>::Bicola(Bicola<T>& B)
{
    Copiar(B);
}

template<typename T>
Bicola<T>& Bicola<T>::operator=(const Bicola<T>& B)
{
    if (this != &B)
    {
        this->~Bicola();
        Copiar (B);
    }

    return* this;
}

template<typename T>
bool Bicola<T>::vacia() const
{
    return (inicio == nullptr);
}

template<typename T>
T& Bicola<T>::frente() const
{
    return inicio->elemento;
}

template<typename T>
T& Bicola<T>::final() const
{
    return fin->elemento;
}

template<typename T>
void Bicola<T>::pushFinal(const T& x)
{
    nodo* p = new nodo(x);
    if (inicio == nullptr)
    {
        fin = p;
        inicio = fin;
    }
    else
    {
        fin->sig = p;
        fin = p;
    }
}

template<typename T>
void Bicola<T>::pushFrente(const T& x)
{
    nodo* p = new nodo(x);
    if (inicio == nullptr) // COLA VACIA
    {
        fin = p;
        inicio = p;
    }
    else
    {
        p->sig = inicio;
        inicio = p;
    }
    
}

template<typename T>
void Bicola<T>::popFrente()
{
    assert(inicio);
    nodo* p = inicio;
    inicio = p->sig;
    if(inicio == nullptr)
    {
        fin = nullptr;
    }
    delete p;
}

template<typename T>
void Bicola<T>::popFinal()
{
    assert(inicio);
    nodo* q = fin;
    nodo* p;
    if (inicio == fin)
    {
        fin = nullptr;
        inicio = nullptr;
    }
    else
    {
        for ( p = inicio; p != fin; p->sig);
        p->sig = nullptr;
        fin = p;
    }
    
    delete q;
}

template<typename T>
Bicola<T>::~Bicola()
{
    nodo* p;
    while (inicio)
    {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    
    fin = nullptr;
}

#endif
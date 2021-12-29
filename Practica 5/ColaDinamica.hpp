#ifndef _COLADINAMICA_
#define _COLADINAMICA_
#include<iostream>
#include<cassert>

template<typename T>
class ColaD
{
public:
    ColaD();
    ColaD(ColaD<T>& C);
    ColaD<T>& operator =(const ColaD<T>& C);
    bool vacia() const;
    T& frente() const;
    T& final() const;
    void push(const T& x);
    void pop();
    ~ColaD();

private:
    struct nodo
    {
        T elemento;
        nodo* sig;
        nodo(T e, nodo* p = nullptr):elemento(e),sig(p){}
    };
    nodo* inicio;
    nodo* fin;
    void Copiar(const ColaD<T>& C);
};

template<typename T>
void ColaD<T>::Copiar(const ColaD<T>& C)
{
    if(C.inicio != nullptr)
    {
        inicio = fin = new nodo(C.inicio->elemento);
        for (nodo* p = C.inicio->sig; p!= nullptr; p = p->sig)
        {
            fin->sig = new nodo(p->elemento);
            fin = fin->sig;
        }
    }
}

template<typename T>
ColaD<T>::ColaD() : inicio(nullptr),fin(nullptr){}

template<typename T>
ColaD<T>::ColaD(ColaD<T>& C)
{
    Copiar(C);
}

template<typename T>
ColaD<T>& ColaD<T>::operator=(const ColaD& C)
{
    if (this != &C)
    {
        this->~ColaD();
        Copiar (C);
    }

    return* this;
    
}

template<typename T>
bool ColaD<T>::vacia() const
{
    return (inicio == nullptr);
}

template<typename T>
T& ColaD<T>::frente() const
{
    assert(!vacia());
    return inicio->elemento;
}

template<typename T>
T& ColaD<T>::final() const
{
    assert(!vacia());
    return fin->elemento;
}

template<typename T>
void ColaD<T>::push(const T& x)
{
    nodo* p = new nodo(x);
    if(inicio == nullptr)
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
void ColaD<T>::pop()
{
    assert(!vacia());
    nodo* p = inicio;
    inicio = p->sig;
    if (inicio==nullptr)
    {
        fin = nullptr;
    }
    
    delete p;
    
}

template<typename T>
ColaD<T>::~ColaD()
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
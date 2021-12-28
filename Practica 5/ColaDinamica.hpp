#ifndef _COLADINAMICA_
#define _COLADINAMICA_
#include<iostream>
#include<cassert>

template<typename T>
class Cola
{
public:
    Cola();
    Cola(Cola<T>& C);
    Cola<T>& operator =(const Cola<T>& C);
    bool vacia() const;
    T& frente() const;
    T& final() const;
    void push(const T& x);
    void pop();
    ~Cola();

private:
    struct nodo
    {
        T elemento;
        nodo* sig;
        nodo(T e, nodo* p = nullptr):elemento(e),sig(p){}
    };
    nodo* inicio;
    nodo* fin;
    void Copiar(const Cola<T>& C);
};

template<typename T>
void Cola<T>::Copiar(const Cola<T>& C)
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
Cola<T>::Cola() : inicio(nullptr),fin(nullptr){}

template<typename T>
Cola<T>::Cola(Cola<T>& C)
{
    Copiar(C);
}

template<typename T>
Cola<T>& Cola<T>::operator=(const Cola& C)
{
    if (this != &C)
    {
        this->~Cola();
        Copiar (C);
    }

    return* this;
    
}

template<typename T>
bool Cola<T>::vacia() const
{
    return (inicio == nullptr);
}

template<typename T>
T& Cola<T>::frente() const
{
    assert(!vacia());
    return inicio->elemento;
}

template<typename T>
T& Cola<T>::final() const
{
    assert(!vacia());
    return fin->elemento;
}

template<typename T>
void Cola<T>::push(const T& x)
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
void Cola<T>::pop()
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
Cola<T>::~Cola()
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
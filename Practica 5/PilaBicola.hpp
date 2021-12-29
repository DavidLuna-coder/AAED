#ifndef _PILA_
#define _PILA_

#include "Bicola.hpp"
#include <cassert>

template<typename T>
class Pila
{

public:
    Pila();
    Pila(Pila<T>& P);
    Pila<T>& operator= (const Pila<T>& P);
    bool vacia() const;
    T& tope() const;
    void push(const T& x);
    void pop();
    ~Pila();
private:
    Bicola<T> B;
};

template<typename T>
Pila<T>::Pila()
{
    Bicola<T> C;
    B = C;
}


template<typename T>
Pila<T>::Pila(Pila<T>& P)
{
    B = P.B;
}

template<typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& P)
{
    if (this != &P)
    {
        B = P.B;
    }
    
    return *this;
}

template<typename T>
bool Pila<T>::vacia() const
{
    return B.vacia();
}

template<typename T>
T& Pila<T>::tope() const
{
    assert(!vacia());
    return B.frente();
}

template<typename T>
void Pila<T>::push(const T& x)
{
    B.pushFrente(x);
}

template<typename T>
void Pila<T>::pop()
{
    assert(!vacia());
    B.popFrente();
}

template<typename T>
Pila<T>:: ~Pila()
{
    B.~Bicola();
}

#endif
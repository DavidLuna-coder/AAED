#ifndef _COLA_
#define _COLA_

template <typename T>
class Cola
{

public:
    Cola(/* args */);
    Cola(Cola<T>& C);
    Cola<T>& operator= (const Cola<T>& C);
    bool vacia() const;
    T& frente() const;
    void push (const T& x);
    void pop();
    ~Cola();
private:
Bicola<T> B;
};


template <typename T>
Cola<T>::Cola()
{
    Bicola<T> C;
    B = C;
}

template <typename T>
Cola<T>::Cola(Cola<T>& C)
{
    B = C.B;
}

template <typename T>
Cola<T>& Cola<T>::operator=(const Cola<T>& C)
{
    if(this != &C)
    {
        B = C.B;
    }

    return *this;
}

template <typename T>
bool Cola<T>::vacia() const
{
    return B.vacia();
}

template <typename T>
T& Cola<T>:: frente() const
{   
    assert(!vacia());
    return B.frente();
}

template <typename T>
void Cola<T>::push(const T& x)
{
    B.pushFinal(x);
}

template <typename T>
void Cola<T>::pop()
{
    assert(!vacia());
    B.popFrente();
}

template <typename T>
Cola<T>::~Cola()
{
    B.~Bicola();
}

#endif
#include <iostream>


template <class T>

class TStack
{
protected:
  int size;
  int count;
  T* data;
public:
  TStack(int);
  TStack(const TStack<T>&);
  ~TStack();
  void Push(T&);
  T Pull();
  int GetCount();
  bool IsFull();
  bool IsEmpty();
};




template <class T>
TStack<T>::TStack(int _size)
{
    if (_size > 0)
    {
        size = _size;
        count = 0;
        data = new T[size];
    }
    else
        throw "invalid size";
}

template <class T>
TStack<T>::TStack(const TStack<T>& p)
{
    size = p.size;
    count = p.count;
    data = new T[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = p.data[i];
    }
}

template <class T>
TStack<T>::~TStack()
{
    delete[] data;
    size = 0;
    count = 0;
}

template <class T>
void TStack<T>::Push(T& p)
{
    if (count < size)
    {
        data[count] = p;
        count++;
    }
    else
        throw "error";
}

template <class T>
T TStack<T>::Pull()
{
    T elem;
    if (count > 0)
    {
        elem = data[count];
        count--;
        return elem;
    }
    else
        throw "error";
}

template <class T>
int TStack<T>::GetCount()
{
    return count;
}

template <class T>
bool TStack<T>::IsEmpty()
{
    if (count == 0)
        return 1;
    else
        return 0;
}

template <class T>
bool TStack<T>::IsFull()
{
    if (count == size)
        return 1;
    else
        return 0;
}

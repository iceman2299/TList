

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

template <class T>

class TQueue
{
protected:
  int size;
  int start, end;
  T* data;
public:
  TQueue(int _size);
  TQueue(const TQueue<T>&p);
  ~TQueue();
  void Push(T&p);
  T Pull();
  int GetCount();
  bool IsFull();
  bool IsEmpty();
};

#endif



template <class T>
inline TQueue<T>::TQueue(int _size)
{
    if (_size > 0)
    {
        size = _size;
        start = 0;
        end = 0;
        data = new T[size];
    }
    else
        throw "invalid size";
}

template <class T>
inline TQueue<T>::TQueue(const TQueue<T>& p)
{
    size = p.size;
    start = p.start;
    end = p.end;
    data = new T[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = p.data[i];
    }
}

template <class T>
inline TQueue<T>::~TQueue()
{
    delete[] data;
    size = 0;
    start = 0;
    end = 0;
}

template <class T>
inline void TQueue<T>::Push(T& p)
{
    if (end < size)
    {
        data[end] = p;
        end++;
    }
    else
        throw "error";
}

template <class T>
inline T TQueue<T>::Pull()
{
    T elem;
    if (start < size && start >= 0)
    {
        elem = data[start];
        start++;
        return elem;
    }
    else
        throw "error";
}

template <class T>
inline int TQueue<T>::GetCount()
{
    return end - start;
}

template <class T>
inline bool TQueue<T>::IsEmpty()
{
    if (start == end)
        return 1;
    else
        return 0;
}

template <class T>
inline bool TQueue<T>::IsFull()
{
    if (end == size)
        return 1;
    else
        return 0;
}

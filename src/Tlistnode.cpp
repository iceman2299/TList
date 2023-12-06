#include <iostream>
#include "Tlistnode.h"

//конструкторы:
template <class T>
TListNode<T>::TListNode()
{
  data = nullptr;
  next = nullptr;
  prev = nullptr;
}

template <class T>
TListNode<T>::TListNode(TListNode<T>* n, TListNode<T>* p, T* d)
{
  data = d;
  next = n;
  prev = p;
}

template <class T>
TListNode<T>::TListNode(const TListNode<T>& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;
}

template <class T>
TListNode<T>::TListNode(TListNode<T>&& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;
  p.next = nullptr;
  p.prev = nullptr;
  delete[] p.data;
}

template <class T>
TListNode<T>::~TListNode()
{
  next = nullptr;
  prev = nullptr;
  delete[] data;
}

//функции:
template <class T>
TListNode<T>* TListNode<T>::GetNext()
{
  return next;
}

template <class T>
TListNode<T>* TListNode<T>::GetPrev()
{
  return prev;
}

template <class T>
T* TListNode<T>::GetData()
{
  return data;
}

template <class T>
void SetNext(TListNode<T>* n)
{
  next = n;
}

template <class T>
void SetPrev(TListNode<T>* p)
{
  prev = p;
}

template <class T>
void SetData(T* d)
{
  data = d;
}

template <class T>
TListNode<T>* TListNode<T>::operator=(const TListNode<T>& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;
  return *this;
}

template <class T>
TListNode<T>* TListNode<T>::operator=(TListNode<T>&& p)
{
  next = p.next;
  prev = p.prev;
  data = p.data;
  p.next = nullptr;
  p.prev = nullptr;
  delete[] p.data;
  return *this;
}










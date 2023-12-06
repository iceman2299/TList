#pragma once
#include <iostream>
#include "Tlistiterator.h"
#include "Tlistnode.h"

template <class T>
TListIterator<T>::~TListIterator()
{
  cur = nullptr
}

template <class T>
TListIterator<T>::TListIterator(TListIterator<T>&& p)
{
  list = p.list;
  cur = p.cur;
  p.list = nullptr;
  p.cur = nullptr;
}

template<class T>
TListIterator<T>::TListIterator(TList<T>& l, TListNode<T>* p): list(l), cur(p)
{
}

template <class T>
TListIterator<T>::TListIterator(const TListIterator<T>& p)
{
  list = p.list;
  cur = p.cur;
}



template <class T>
TListIterator<T> TListIterator<T>::GetBegin()
{
  return TListIterator<T>(*this, begin);
}

template <class T>
TListIterator<T> TListIterator<T>::GetEnd()
{
  return TListIterator<T>(*this, nullptr);
}

#pragma once
#include <iostream>
#include "Tlist.h"

template <class T>
class TListIterator
{
protected:
  TList<T>& list;
  TListNode<T>* cur;
public:
  TListIterator(TList<T>& l, TListNode<T>* p);
  TListIterator(const TListIterator<T>& p);
  TListIterator(TListIterator<T>&& p);
  ~TListIterator();
  TListIterator<T>& operator=(const TListIterator<T>& p);
  TListIterator<T>& operator=(TListIterator<T>&& p);
  TListIterator<T>& operator++();
  TListIterator<T>& operator--();
  bool operator==(const TListIterator& a);
  bool operator!=(const TListIterator& a);
  void PushAfter(T* a);
  void PushBefore(T* a);
  void Delete();
  T* operator*();

  TListIterator<T> GetBegin();
  TListIterator<T> GetEnd();
};


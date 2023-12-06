#include <iostream>
#include "Tlistiterator.h"

template <class T>

class TList
{
protected:
  TListNode<T>* begin;
  TListNode<T>* end;
  int count;
public:
  TList();
  TList(const TList<T>& p);
  TList(TList<T>&& p);
  ~TList();
  void PushBegin(T* d);
  void PushEnd(T* d);
  void DeleteBegin();
  void DeleteEnd();
  TListIterator<T> GetBegin();
  TList<T>& operator=(const TList<T>& p)
};


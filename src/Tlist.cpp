#pragma once
#include <iostream>
#include "Tlist.h"


template <class T>
TList<T>::TList()
{
  count = 0;
  begin = nullptr;
  end = nullptr;
}
template <class T>
TList<T>::TList(const TList<T>& p)
{
  count = p.count;
  if (p.begin == nullptr)
  {
    begin = nullptr;
    end = nullptr;
  }
  else
  {
    begin = new TListNode<T>(p.begin);
    TListNode<T>* temp = begin;
    TListNode<T>* temp2 = p.begin;
    while (temp2->GetNext() != p.begin)
    {
      TListNode<T>* d = new TListNode<T>();
      d->SetPrev(temp);
      d->SetData(new T(*temp2->GetNext()->GetData()));
      temp->SetNext(d);
      temp = temp->GetNext();
      temp2 = temp2->GetNext();
    }
    end = new TListNode<T>(begin, temp, new T* (temp2->GetNext()->GetData()));
    begin->SetPrev(end);
  }
}

/*
template <class T>
TList<T>::TList()
{
  TListNode<T>* tmp;
  int i = 0;
  while (i < count)
  {
    TListNode<T>* tmp2 = tmp;
    tmp = tmp->GetNext();
    delete tmp2;
    i++;
  }
  begin = nullptr;
  end = nullptr;
  count = 0;
}
*/ //ÿ“Œ ≈“¿???
template <class T>
TList<T>::TList(TList<T>&& p)
{
  begin = p.begin;
  end = p.end;
  count - p.count;
  p.begin = nullptr;
  p.end = nullptr;
  count = 0;
}

template <class T>
TList<T>::~TList()
{
  begin = nullptr;
  end = nullptr;
  count = 0;
}
/*
template<class T>
TList<T>::TList(const TList<T>& p)
{
  begin = p.begin;
  end = p.end;
  count = p.count;
}*/

template <class T>
void TList<T>::PushBegin(T* d)
{
  TListNode<T>* a = new TListNode(begin, end, d);
  begin = a;
}


template <class T>
void TList<T>::PushEnd(T* d)
{
  TListNode<T>* a = new TListNode(begin, end, d);
  end = a;
}

template <class T>
void TList<T>::DeleteBegin()
{
  TListNode<T>* a = begin;
  end->SetNext(begin->GetNext());
  begin = begin->GetNext();
  begin->SetPrev(end);
  delete a;
}

template <class T>
void TList<T>::DeleteEnd()
{
  TListNode<T>* a = end;
  begin->SetPrev(end->GetPrev());
  end = end->GetPrev();
  end->SetNext(begin);
  delete a;
}

template <class T>
TList<T>& TList<T>::operator=(const TList<T>&p)
{
  if (p == this)
    return this;
  TList<T>::TList(p);
  return this;
}



template <class T>
void TList<T>::Clear()
{
  TListNode<T> fel = this->begin;
  for (int i = 0; i < count; i++)
  {
    TListNode<T> sel = fel;
    fel = this->next;
    delete sel;
  }
  begin = nullptr;
  end = nullptr;
}
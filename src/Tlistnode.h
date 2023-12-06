#pragma once
#include <iostream>

template <class T>

class TListNode
{
protected:
  TListNode<T>* next;
  TListNode<T>* prev;
  T* data;
public:
  TListNode();
  TListNode(TListNode<T>* h,TListNode<T>* P, T* d);
  TListNode(const TListNode<T>& p);
  TListNode(TListNode<T>&& p);
  ~TListNode();
  TListNode<T>* GetNext();
  TListNode<T>* GetPrev();
  T* GetData();
  void SetNext(TListNode<T>& n);
  void SetPrev(TListNode<T>& p);
  void SetData(T* d);
  TListNode<T>* operator=(const TListNode<T>& p);
  TListNode<T>* operator=(TListNode<T>&& p);
}; 


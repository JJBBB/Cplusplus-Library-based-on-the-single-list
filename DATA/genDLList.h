#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "stdafx.h"

template<class T>
class DLLNode
{
public:
	DLLNode()
	{
		next = prev = 0;
	}
	DLLNode(const T& el, DLLNode *n = 0, DLLNode *p = 0)
	{
		info = el; next = n; prev = p;
	}
	T info;
	DLLNode *next, *prev;
};

template<class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList()
	{
		head = tail = 0;
	}
	void addToDLLTail(const T&);
	T deleteFromDLLTail();
	void Travase()const;
protected:
	DLLNode<T> *head, *tail;
};
 template<class T>
 void DoublyLinkedList<T>::addToDLLTail(const T& el)
 {
	 if (tail != 0)
	 {
		 tail->next = new DLLNode<T>(el, tail->next, tail);
		 tail = tail->next;
		 head->prev = tail;
	 }
	 else
	 {
		 head = tail = new DLLNode<T>(el);
		 tail->next = tail;
		 tail->prev = tail;
	 }
 }

 template<class T>
 T DoublyLinkedList<T>::deleteFromDLLTail()
 {
	 DLLNode<T> *tmp = tail;
	 T res = tail->info;
	 if (head == tail)
	 {
		 delete head;
		 head = tail = 0;
	 }
	 else
	 {
		 tail = tail->prev;
		 delete tail->next;
		 tail->next = head;
		 head->prev = tail;
	 }
	 
	 return res;
 }

 template<class T>
 void DoublyLinkedList<T>::Travase()const
 {
	 DLLNode<T> *tmp;
	 for (tmp = head; tmp != tail; tmp = tmp->next)
	 {
		 cout << tmp->info << endl;
	 }
	 cout << tail->info << endl;
 }

#endif
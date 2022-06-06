#pragma once
#include"Node.h"
#include<iostream>
using namespace std;	
template<class T>
class DoubleLinkedList
{
private:
	Node<T>* Head;
	Node<T>* Tail;
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void insetAtFront(T data);
	void insertAtEnd(T data);
	T RemoveFromFront();
	T RemoveFromEnd();

	T Front();
	T Back();
	bool isEmpty();
	int size();


};

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<class T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
	if (this->Head != nullptr && this->Tail != nullptr)
	{
		Node<T>* Mover = this->Head;
		while (Mover!= nullptr)
		{
			Mover = Mover->Next;
			delete this->Head;
			this->Head = Mover;
		}
	}
}

template<class T>
inline void DoubleLinkedList<T>::insetAtFront(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	if(!this->Tail)
	{
		this->Tail = NewNode;
		this-> Head = NewNode;
	}
	else
	{
		NewNode->Next = this->Head;
		this->Head->Pre = NewNode;
		this->Head = NewNode;
	}

	NewNode = nullptr;
}

template<class T>
inline void DoubleLinkedList<T>::insertAtEnd(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	if (!this->Head)
	{
		this->Tail = NewNode;
		this->Head = NewNode;
	}
	else
	{
		this->Tail->Next = NewNode;
		NewNode->Pre = this->Tail;
		this->Tail = NewNode;
	}
	NewNode = nullptr;
}

template<class T>
inline T DoubleLinkedList<T>::RemoveFromFront()
{
	if (this->Head!=nullptr)
	{
		Node<T>* Del =this->Head;
		T val = Del->data;
		this->Head = this->Head->Next;
		delete Del;
		Del = nullptr;
		if(this->Head!=nullptr)
		this->Head->Pre = nullptr;
		else
		{
			this->Tail = nullptr;
		}

		return val;
	}
	return T();
}

template<class T>
inline T DoubleLinkedList<T>::RemoveFromEnd()
{
	if (this->Head != nullptr)
	{
		Node<T>* Del = this->Tail;
		T val = Del->data;
		this->Tail = this->Tail->Pre;
		delete Del;
		if (this->Tail != nullptr)
		{
			this->Tail->Next = nullptr;
		}
		else
		{
			this->Head = nullptr;
		}
		return val;
	}
	return T();
}

template<class T>
inline T DoubleLinkedList<T>::Front()
{
	if (this->Head!=nullptr)
		return this->Head->data;
	return T();
}

template<class T>
inline T DoubleLinkedList<T>::Back()
{
	if (this->Tail != nullptr)
		return this->Tail->data;
	return T();
}

template<class T>
inline bool DoubleLinkedList<T>::isEmpty()
{
	if (this->Head != nullptr)
		return true;
	return false;
}

template<class T>
inline int DoubleLinkedList<T>::size()
{
	Node<T>* Mover=this->Head;
	int size = 0;
	while (Mover!=nullptr)
	{
		size++;
		Mover = Mover->Next;
	}
	return size;
}


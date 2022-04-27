#pragma once
#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class CircularLinkedList
{
private:
	Node<T>* Head;
	Node<T>* Tail;
public:
	CircularLinkedList();
	~CircularLinkedList();

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
inline CircularLinkedList<T>::CircularLinkedList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<class T>
inline CircularLinkedList<T>::~CircularLinkedList()
{
	if (this->Head != nullptr && this->Tail != nullptr)
	{
		while (this->Head)
		{
		   this->RemoveFromFront()<<" ";
		}
	}
}

template<class T>
inline void CircularLinkedList<T>::insetAtFront(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	NewNode->Next = this->Head;
	if (this->Head == nullptr)
	{
		this->Tail = NewNode;
	}
	this->Head = NewNode;
	this->Tail->Next = this->Head;
	NewNode = nullptr;
}

template<class T>
inline void CircularLinkedList<T>::insertAtEnd(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	if (this->Tail != nullptr)
		this->Tail->Next = NewNode;
	else
		this->Head = NewNode;
	this->Tail = NewNode;
	this->Tail->Next = this->Head;
	NewNode = nullptr;
}

template<class T>
inline T CircularLinkedList<T>::RemoveFromFront()
{
	if (this->Head != nullptr)
	{
		T data = this->Head->data;
		if (this->Head == this->Tail)
		{
			delete this->Head;
			this->Head = nullptr;
			this->Tail = nullptr;
		}
		else
		{
			Node<T>* Del = this->Head;
			this->Head = this->Head->Next;
			delete Del;
			Del = nullptr;
			this->Tail->Next = this->Head;
		}
		return data;
	}
	return T();
}

template<class T>
inline T CircularLinkedList<T>::RemoveFromEnd()
{
	if (this->Head != nullptr)
	{
		T data = this->Tail->data;
		if (this->Head == this->Tail)
		{
			delete this->Head;
			this->Head = nullptr;
			this->Tail = nullptr;
		}
		else
		{
			Node<T>*Mover= this->Head;
			for (; Mover->Next != this->Tail; Mover = Mover->Next);
			Mover->Next = this->Head;
			delete this->Tail;
			this->Tail = Mover;
			Mover = nullptr;
		}
		return data;
	}
	return T();
}

template<class T>
inline T CircularLinkedList<T>::Front()
{
	if (this->Head != nullptr)
		return this->Head->data;
	return T();
}

template<class T>
inline T CircularLinkedList<T>::Back()
{
	if (this->Tail != nullptr)
		return this->Tail->data;
	return T();
}

template<class T>
inline bool CircularLinkedList<T>::isEmpty()
{
	if (this->Head!=nullptr)
	{
		return true;
	}
	return false;
}

template<class T>
inline int CircularLinkedList<T>::size()
{
	if (this->Head!=nullptr)
	{
		int size = 0;
		Node<T>* Mover = this->Head;
		while (Mover!=nullptr)
		{
			size++;
			if (Mover==this->Tail)
			{
				break;
			}

			Mover = Mover->Next;
		}
		return size;
	}

	return 0;
}

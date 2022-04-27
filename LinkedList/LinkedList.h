#pragma once
#include<iostream>
using namespace std;
#include"ADTLinkedList.h"
template<class T>
class LinkedList:public ADTLinkedList<T>
{
public:
	LinkedList();
	~LinkedList();
	
	virtual void insetAtFront(T data);
	virtual void insertAtEnd(T data);
	virtual T RemoveFromFront();
	virtual T RemoveFromEnd();

	void InSertSort(T data);

	T Front();
	T Back();
	bool isEmpty();
	int size();

	void Reverse();

};

template<class T>
inline LinkedList<T>::LinkedList()
{

}

template<class T>
inline LinkedList<T>::~LinkedList() 
{

}

template<class T>
inline void LinkedList<T>::insetAtFront(T data)
{
	Node<T> *NewNode = new Node<T>(data);
	NewNode->Next = this->Head;
	this->Head = NewNode;
	if(!this->Tail)
	{
		this->Tail = NewNode;
	}
	NewNode = nullptr;
}

template<class T>
inline void LinkedList<T>::insertAtEnd(T data)
{
	Node<T> *NewNode = new Node<T>(data);
	if(this->Tail!=nullptr)
	this->Tail->Next= NewNode;
	this->Tail= NewNode;
	if (!this->Head)
	{
		this->Head= NewNode;
	}
	NewNode = nullptr;
}

template<class T>
inline T LinkedList<T>::RemoveFromFront()
{
	if(this->Head!=nullptr)
	{
		T data = this->Head->data;
		Node<T>* Del = this->Head;
		if (this->Head == this->Tail)
		{
			delete this->Head;
			this->Head = nullptr;
			this->Tail = nullptr;
			return data;
		}
		this->Head = this->Head->Next;
		delete Del;
		Del = nullptr;
		return data;
	}
	return T();
}

template<class T>
inline T LinkedList<T>::RemoveFromEnd()
{
	if (this->Head!=nullptr)
	{
		T data = this->Tail->data;
		Node<T>* Mover=this->Head;
		if (this->Head == this->Tail)
		{
			delete this->Head;
			this->Head = nullptr;
			this->Tail = nullptr;
			return data;
		}
		for (;Mover->Next!=this->Tail;Mover=Mover->Next);
		Mover->Next = nullptr;
		delete this->Tail;
		this->Tail = Mover;
		return data;
	}
	return T();
}

template<class T>
inline void LinkedList<T>::InSertSort(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	if (this->Tail != nullptr)
		this->Tail->Next = NewNode;
	this->Tail = NewNode;
	if (!this->Head)
	{
		this->Head = NewNode;
	}
	NewNode = nullptr;

	if(this->Head!=this->Tail)
	{
		Node<T> *Mover1 = this ->Head;
		T Temp = {};
		while (Mover1!=nullptr)
		{
			NewNode = Mover1->Next;
			while(NewNode!=nullptr)
			{
				if(Mover1->data>NewNode->data)
				{
					Temp = Mover1->data;
					Mover1->data= NewNode->data;
					NewNode->data = Temp;
				}
				NewNode = NewNode->Next;
			}
			Mover1 = Mover1->Next;
		}
	}

}

template<class T>
inline T LinkedList<T>::Front()
{
	if(this->Head!=nullptr)
	return this->Head->data;
	return T();
}

template<class T>
inline T LinkedList<T>::Back()
{
	if (this->Tail != nullptr)
	{
		return this->Tail->data;
	}
	return T();
}

template<class T>
inline bool LinkedList<T>::isEmpty()
{
	if (this->Head==nullptr&&this->Tail == nullptr)
	{
		return true;
	}
	return false;
}

template<class T>
inline int LinkedList<T>::size()
{
	int size = 0;
	Node<T>* Mover = this->Head;
	while (Mover!=nullptr)
	{
		++size;
		Mover = Mover->Next;
	}
	return size;
}

template<class T>
inline void LinkedList<T>::Reverse()
{
	Node<T>* Current = this->Head,*Pre=nullptr,*r=nullptr;
	while (Current!=nullptr)
	{
		Pre = Current;
		Current = Current->Next;
		Pre->Next = r;
		r = Pre;
	}
	Current = this->Head;
	Pre = this->Tail;
	this->Head = Pre;
	this->Tail = Current;
}

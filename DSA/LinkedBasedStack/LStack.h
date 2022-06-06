#pragma once
#include"Node.h"
#include<iostream>
using namespace std;


template<class T>
class LStack
{

private:
	Node<T>* Head;
	Node<T>* Tail;
public:
	LStack();
	~LStack();
	

	void Push(T data);
	T Pop();

	bool empty();
	
};

template<class T>
inline LStack<T>::LStack()
{
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<class T>
inline LStack<T>::~LStack()
{
	
}

template<class T>
inline void LStack<T>::Push(T data)
{
	Node<T>* New = new Node<T>(data);
	if (this->Head == nullptr)
	{
		this->Head = New;
	}
	if (this->Tail != nullptr)
		this->Tail->Next = New;
 	this->Tail = New;
}

template<class T>
inline T LStack<T>::Pop()
{
	if (this->Tail != nullptr &&this->Head!=nullptr)
	{
		T dd = this->Tail->data;
		if (this->Tail == this->Head)
		{
			delete this->Tail;
			this->Tail = nullptr;
			this->Head = nullptr;
		}
		else
		{
			Node<T>* Mover = this->Head;
			for (; Mover->Next!= this->Tail; Mover = Mover->Next);
			delete this->Tail;
			this->Tail = Mover;
		}
		return dd;
	}

	return T();
}

template<class T>
inline bool LStack<T>::empty()
{
	if (this->Head==nullptr && this->Tail == nullptr)
		return true;
	return false;
}

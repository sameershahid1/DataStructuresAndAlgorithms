#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<class T>
class LQueue
{
private:
	Node<T>* Head;
	Node<T>* Tail;
public:
	LQueue();
	~LQueue();


	void Enqueue(T data);
	T dequeue();
	T peek();

	bool empty();

};

template<class T>
inline LQueue<T>::LQueue()
{
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<class T>
inline LQueue<T>::~LQueue()
{
	if (this->Head!=nullptr&&this->Tail!=nullptr)
	{
		Node<T>* Mover = this->Head,*Del=nullptr;
		while (Mover!=nullptr)
		{
			Del = Mover;
			cout << Del->data;
			Mover = Mover->Next;
			delete Del;
			Del = nullptr;
		}


	}
}

template<class T>
inline void LQueue<T>::Enqueue(T data)
{
	Node<T>* New=new Node<T>(data);
	if(this->Head==nullptr)
	{
		this->Head = New;
	}
	if(this->Tail!=nullptr)
	{
		this->Tail->Next = New;
	}
	this->Tail = New;
	New = nullptr;
}

template<class T>
inline T LQueue<T>::dequeue()
{
	if (this->Head != nullptr && this->Tail != nullptr)
	{
		T dd = this->Head->data;
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
		}
		return dd;
	}
	return T();
}

template<class T>
inline T LQueue<T>::peek()
{
	if (this->Head != nullptr)
		return this->Head->data;
	return T();
}

template<class T>
inline bool LQueue<T>::empty()
{
	if (this->Head == nullptr && this->Tail == nullptr)
		return true;
	return false;
}

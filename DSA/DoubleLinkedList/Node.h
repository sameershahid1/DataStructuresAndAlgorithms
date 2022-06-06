#pragma once
#include"DoubleLinkedList.h"
template<class T>
class Node
{
template<class T>
friend class DoubleLinkedList;
private:
	T data;
	Node* Next;
	Node* Pre;
public:
	Node(T data);
	~Node();
};

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
	this->Next = nullptr;
	this->Pre= nullptr;
}

template<class T>
inline Node<T>::~Node() {}

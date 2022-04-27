#pragma once
#include"LinkedList.h"
template<class T>
class Node
{
template<class T>
friend class ADTLinkedList;
template<class T>
friend class LinkedList;
private:
	T data;
	Node* Next;
public:
	Node(T data);
	~Node();
};

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
	this->Next = nullptr;
}

template<class T>
inline Node<T>::~Node() {}

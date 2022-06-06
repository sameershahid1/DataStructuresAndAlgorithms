#pragma once
#include"Node.h"

template<class T>
class ADTLinkedList
{
protected:
    Node<T>* Head;
    Node<T>* Tail;
public:
    ADTLinkedList();
    ~ADTLinkedList();

    virtual void insetAtFront(T data)=0;
    virtual void insertAtEnd(T data) = 0;
    virtual T RemoveFromFront() = 0;
    virtual T RemoveFromEnd() = 0;

};

template<class T>
inline ADTLinkedList<T>::ADTLinkedList()
{
    this->Head = nullptr;
    this->Tail = nullptr;
}

template<class T>
inline ADTLinkedList<T>::~ADTLinkedList()
{
    if (this->Head != nullptr && this->Tail != nullptr)
    {
        
    }
}

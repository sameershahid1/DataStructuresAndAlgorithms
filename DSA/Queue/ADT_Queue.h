#pragma once
#include<iostream>
using namespace std;
template<class T>
class ADT_Queue
{
public:
	ADT_Queue();
	~ADT_Queue();
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void initializeQueue() = 0;
	virtual void enQueue(T val) = 0;
	virtual void deQueue()=0;
	virtual void printQueue() = 0;
};

template<class T>
inline ADT_Queue<T>::ADT_Queue()
{

}

template<class T>
inline ADT_Queue<T>::~ADT_Queue()
{

}

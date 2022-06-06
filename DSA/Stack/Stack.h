#pragma once
#include<iostream>
using namespace std;

template<class kin>
class Stack
{
protected:
	kin* stackArray;
	int maxsize;
	int stackTop;
public:
	Stack(int size=0);
	~Stack();
	virtual void Push(kin val) = 0;
	virtual int Pop() = 0;
};



template<class kin>
Stack<kin>::Stack(int size)
{
	this->maxsize = size;
	this->stackTop = -1;
	this->stackArray = new kin[this->maxsize];
}

template<class kin>
Stack<kin>::~Stack()
{
	if (this->stackArray != nullptr)
	{
		delete[] this->stackArray;
	}
}
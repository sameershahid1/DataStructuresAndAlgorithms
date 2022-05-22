#pragma once
#include"Stack.h"
template<class kin>
class myStack:public Stack<kin>
{
public:
	myStack(int size);
	virtual ~myStack();

	virtual void Push(kin val);
	virtual int Pop();
	bool empty();
	bool full();
	int size();
	kin top();

	void dislpay();

};


template<class kin>
myStack<kin>::myStack(int size) :Stack<kin>(size)
{

}

template<class kin>
myStack<kin>::~myStack()
{

}

template<class kin>
void myStack<kin>::Push(kin val)
{
	if (!this->full())
	{
		++this->stackTop;
		this->stackArray[this->stackTop] = val;
	}
	else
	{
		cout << "\nStack Over-Flow\n";
	}
}

template<class kin>
int myStack<kin>::Pop()
{
	int val = 0;
	if (this->stackTop >= 0)
	{
		val = this->stackArray[this->stackTop];
		--this->stackTop;
		return val;
	}
	else
	{
		cout << "\nStack is Under-Flow\n";
	}
	return -1;
}

template<class kin>
bool myStack<kin>::empty()
{
	if (this->stackTop == -1)
	{
		return true;
	}
	return false;
}

template<class kin>
bool myStack<kin>::full()
{
	if (this->stackTop == this->maxsize - 1)
	{
		return true;
	}
	return false;
}

template<class kin>
int myStack<kin>::size()
{
	return this->stackTop + 1;
}

template<class kin>
kin myStack<kin>::top()
{
	return this->stackArray[this->stackTop];
}

template<class kin>
void myStack<kin>::dislpay()
{
	for (int i = 0; i < this->stackTop + 1; i++)
	{
		cout << this->stackArray[i] << " ";
	}
	cout << endl;
}
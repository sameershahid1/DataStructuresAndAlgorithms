#pragma once
#include"ADT_Queue.h"
template<class T>
class Queue
{
private:
	T* Arr;
	int front;
	int rear;
	int maxsize;
public:
	Queue(int size=0);
	Queue(const Queue& Q);
	~Queue();

	virtual bool isEmpty();
	virtual bool isFull();
	virtual void initializeQueue();
	virtual void enQueue(T val);
	virtual void deQueue();
	virtual void printQueue() ;
};

template<class T>
inline Queue<T>::Queue(int size)
{
	this->maxsize = size;
	this->front = -1;
	this->rear = -1;
	this->Arr = new T[this->maxsize]{};
}

template<class T>
inline Queue<T>::Queue(const Queue& Q)
{
	this->maxsize = Q.maxsize;
	this->front = Q.front;
	this->rear = Q.rear;
	this->Arr = new T[this->maxsize];
	for (int i = 0; i <= this->rear; i++)
	{
		this->Arr[i] = Q.Arr[i];
	}
}

template<class T>
inline Queue<T>::~Queue()
{
	if (this->Arr != nullptr)
	{
		delete[] this->Arr;
	}
}

template<class T>
inline bool Queue<T>::isEmpty()
{
	if (this->rear == -1)
		return true;
	return false;
}

template<class T>
inline bool Queue<T>::isFull()
{
	if (!this->isEmpty())
		return true;
	return false;
}

template<class T>
inline void Queue<T>::initializeQueue()
{
	if (this->maxsize == 0)
	{
		cout<< "Enter the size: ";
		cin >> this->maxsize;
		this->Arr = new T[this->maxsize];
	}
	else
	{
		cout << "\nThe size is already defined\n";
	}
}

template<class T>
inline void Queue<T>::enQueue(T val)
{
	if (this->rear<this->maxsize-1)
	{
		if (this->front == -1)
		{
			++this->front;
		}
		++this->rear;
		this->Arr[this->rear] = val;
	}
	else
	{
		cout << "\nThe Queue is full\n";
	}
}

template<class T>
inline void Queue<T>::deQueue()
{
	if (this->rear!=-1)
	{

		for (int i = 0; i <= this->rear; i++)
		{
			if(i+1<=this->rear)
			this->Arr[i]= this->Arr[i + 1];
		}

		--this->rear;
		if(this->rear==-1)
		{
			--this->front;
		}
	}
}

template<class T>
inline void Queue<T>::printQueue()
{
	for (int i = 0; i <= this->rear; i++)
	{
		cout << this->Arr[i]<<" ";
	}
	cout<< endl;
}

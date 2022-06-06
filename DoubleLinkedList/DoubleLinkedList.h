#pragma once
#include"Node.h"

template<class T>
class DoubleLinkedList;

template<class T>
class Node;


template<class T>
class DoubleLinkedList
{
private:
	//Attributes
	Node<T>* Head;
	Node<T>* Tail;

//Helping Function
	int sum_of_list(Node<T>*head);
	bool primeChecker(Node<T>*head,int div);
	int product_of_Prime(Node<T>* head);
	void Display_Even(Node<T>*head);
	int Counter(Node<T>*head,int data);
	void occurance_of_key(Node<T>*head);
	Node<T>*reverse(Node<T>*head);
	void Display(Node<T>*head);
	bool Palindrome_Check(Node<T>*start,Node<T>*End,int time);
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	//Inserting
	void insetAtFront(T data);
	void insertAtEnd(T data);

	//Removing
	T RemoveFromFront();
	T RemoveFromEnd();
	
	//Getter
	T Front();
	T Back();

	//Checker Function
	bool isEmpty();
	int size();
    void Display();


	//Function That performs some functionality
	int sum_of_list();
	int product_of_Prime();
	void Display_Even();
	void occurance_of_key();
	void reverse();
	bool Palindrome_Check();
};

template<class T>
inline int DoubleLinkedList<T>::sum_of_list(Node<T>* head)
{
	if (head == nullptr)
	{
		return 0;
	}

	return head->data+sum_of_list(head->Next);
}

template<class T>
bool DoubleLinkedList<T>::primeChecker(Node<T>* head, int div)
{
	if (head->data == 0 || head->data == 1)
	{
		return false;
	}


	if(!(div<head->data))
	{
		return true;
	}

	if (head->data%div==0)
	{
		return false;
	}
	primeChecker(head,++div);
}

template<class T>
int DoubleLinkedList<T>::product_of_Prime(Node<T>* head)
{
	if (head == nullptr)
	{
		return 1;
	}

	if(primeChecker(head,2)==true)
	{
		return head->data*product_of_Prime(head->Next);
	}
	product_of_Prime(head->Next);
}

template<class T>
inline void DoubleLinkedList<T>::Display_Even(Node<T>* head)
{
	if (head != nullptr)
	{
		if(head->data%2==0)
		cout << head->data << " ";
		Display_Even(head->Next);
	}
}

template<class T>
inline int DoubleLinkedList<T>::Counter(Node<T>* head,int data)
{
	if (head == nullptr)
	{
		return 0;
	}

	if (head->data==data)
	{
	   return 1 + Counter(head->Next,data);
	}
	else
	{
		Counter(head->Next, data);
	}
}

template<class T>
inline void DoubleLinkedList<T>::occurance_of_key(Node<T>* head)
{
	if (head != nullptr)
	{
		cout << "Data: " << head->data << ", occurance: " << Counter(head->Next,head->data)<<endl;
		occurance_of_key(head->Next);
	}
}

template<class T>
inline Node<T>* DoubleLinkedList<T>::reverse(Node<T>* head)
{
	if(head->Next==nullptr)
	{
		return head;
	}
	Node<T>* Connector = reverse(head->Next);
	if (Connector->Next == nullptr)
	{
		Connector->Pre = nullptr;
	}
	if (head->Pre == nullptr)
	{
		head->Next = nullptr;
	}
	Connector->Next = head;
	head->Pre = Connector;
	return head;
}

template<class T>
inline void DoubleLinkedList<T>::Display(Node<T>* head)
{
	if (head != nullptr)
	{
		cout << head->data << " ";
		Display(head->Next);
	}
}

template<class T>
inline bool DoubleLinkedList<T>::Palindrome_Check(Node<T>* start, Node<T>* End, int time)
{
	if (time == 0)
	{
		return true;
	}


	if (start->data == End->data)
	{
		Palindrome_Check(start->Next,End->Pre,--time);
	}
	else
	{
		return false;
	}
}

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
}

template<class T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
	if (this->Head != nullptr && this->Tail != nullptr)
	{
		Node<T>* Mover = this->Head;
		while (Mover!= nullptr)
		{
			Mover = Mover->Next;
			delete this->Head;
			this->Head = Mover;
		}
	}
}

template<class T>
inline void DoubleLinkedList<T>::insetAtFront(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	if(!this->Tail)
	{
		this->Tail = NewNode;
		this-> Head = NewNode;
	}
	else
	{
		NewNode->Next = this->Head;
		this->Head->Pre = NewNode;
		this->Head = NewNode;
	}

	NewNode = nullptr;
}

template<class T>
inline void DoubleLinkedList<T>::insertAtEnd(T data)
{
	Node<T>* NewNode = new Node<T>(data);
	if (!this->Head)
	{
		this->Tail = NewNode;
		this->Head = NewNode;
	}
	else
	{
		this->Tail->Next = NewNode;
		NewNode->Pre = this->Tail;
		this->Tail = NewNode;
	}
	NewNode = nullptr;
}

template<class T>
inline T DoubleLinkedList<T>::RemoveFromFront()
{
	if (this->Head!=nullptr)
	{
		Node<T>* Del =this->Head;
		T val = Del->data;
		this->Head = this->Head->Next;
		delete Del;
		Del = nullptr;
		if(this->Head!=nullptr)
		this->Head->Pre = nullptr;
		else
		{
			this->Tail = nullptr;
		}

		return val;
	}
	return T();
}

template<class T>
inline T DoubleLinkedList<T>::RemoveFromEnd()
{
	if (this->Head != nullptr)
	{
		Node<T>* Del = this->Tail;
		T val = Del->data;
		this->Tail = this->Tail->Pre;
		delete Del;
		if (this->Tail != nullptr)
		{
			this->Tail->Next = nullptr;
		}
		else
		{
			this->Head = nullptr;
		}
		return val;
	}
	return T();
}

template<class T>
inline T DoubleLinkedList<T>::Front()
{
	if (this->Head!=nullptr)
		return this->Head->data;
	return T();
}

template<class T>
inline T DoubleLinkedList<T>::Back()
{
	if (this->Tail != nullptr)
		return this->Tail->data;
	return T();
}

template<class T>
inline bool DoubleLinkedList<T>::isEmpty()
{
	if (this->Head != nullptr)
		return true;
	return false;
}

template<class T>
inline int DoubleLinkedList<T>::size()
{
	Node<T>* Mover=this->Head;
	int size = 0;
	while (Mover!=nullptr)
	{
		size++;
		Mover = Mover->Next;
	}
	return size;
}

template<class T>
inline void DoubleLinkedList<T>::Display()
{
	Display(this->Head);
}

template<class T>
inline int DoubleLinkedList<T>::sum_of_list()
{
	return this->sum_of_list(this->Head);
}

template<class T>
int DoubleLinkedList<T>::product_of_Prime()
{
	int data=this->product_of_Prime(this->Head);
	if (data == 1)
	{
		return data - 1;
	}

	return data;
}

template<class T>
inline void DoubleLinkedList<T>::Display_Even()
{
	this->Display_Even(this->Head);
	cout << endl;
}

template<class T>
inline void DoubleLinkedList<T>::occurance_of_key()
{
	this->occurance_of_key(this->Head);
}

template<class T>
inline void DoubleLinkedList<T>::reverse()
{
	if (this->Head!=nullptr)
	{
		this->Tail = reverse(this->Head);
		Node<T>* Mover = this->Tail;
		for (; Mover->Pre != nullptr; Mover = Mover->Pre);
		this->Head = Mover;
	}
}

template<class T>
inline bool DoubleLinkedList<T>::Palindrome_Check()
{
	if (this->Head == nullptr)return false;
	return Palindrome_Check(this->Head);
}


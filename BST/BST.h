#pragma once

//<--------------------------Node-------------------------->
template<class T>
class Node
{
public:
	T data;
	Node* Right;
	Node* Left;
	Node(T data);
	Node(const Node& N);
	~Node();
};

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
	this->Left = nullptr;
	this->Right = nullptr;
}

template<class T>
inline Node<T>::Node(const Node& N)
{
	this->data = N.data;
	this->Left = N.Left;
	this->Right = N.Right;
}

template<class T>
inline Node<T>::~Node()
{

}


//<--------------------------ADT Binary Search Tree-------------------------->

template<class T>
class ADT_BST
{
protected:
	Node<T>* Root;
public:
	ADT_BST();
	~ADT_BST();

	virtual void insert_node(T data)=0;
	virtual void Print_inOrder() = 0;
	virtual void Print_PostOrder() = 0;
	virtual void Print_PreOrder() = 0;

};

template<class T>
inline ADT_BST<T>::ADT_BST()
{
	this->Root = nullptr;
}

template<class T>
inline ADT_BST<T>::~ADT_BST()
{

}

//<--------------------------Binary Search Tree-------------------------->

template<class T>
class BST:public ADT_BST<T>
{
private:
//Helper Functions

void insert_node(Node<T> *root,T data);
void Print_inOrder(Node<T>* root);
void Print_PostOrder(Node<T>* root);
void Print_PreOrder(Node<T>* root);
public:
	BST();
	~BST();

	virtual void insert_node(T data);
	virtual void Print_inOrder();
	virtual void Print_PostOrder();
	virtual void Print_PreOrder();

};

template<class T>
inline void BST<T>::insert_node(Node<T>* root, T data)
{
	if (root->data<data)
	{
		if (root->Right != nullptr)
		{
			insert_node(root->Right,data);
		}
		else
		{
			root->Right = new Node<T>(data);
		}
	}
	else if (root->data>data)
	{
		if (root->left!= nullptr)
		{
			insert_node(root->left, data);
		}
		else
		{
			root->left = new Node<T>(data);
		}
	}
}

template<class T>
inline void BST<T>::Print_inOrder(Node<T>* root)
{
	if (root != nullptr)
	{
		Print_PreOrder(root->Left);
		cout << root->data << " ";
		Print_PreOrder(root->right);
	}
}

template<class T>
inline void BST<T>::Print_PostOrder(Node<T>* root)
{
	if (root != nullptr)
	{
		Print_PreOrder(root->Left);
		Print_PreOrder(root->right);
		cout << root->data << " ";
	}
}

template<class T>
inline void BST<T>::Print_PreOrder(Node<T>* root)
{
	if (root!=nullptr)
	{
		cout << root->data<<" ";
		Print_PreOrder(root->Left);
		Print_PreOrder(root->right);
	}
}

template<class T>
inline BST<T>::BST()
{

}

template<class T>
inline BST<T>::~BST()
{

}

template<class T>
inline void BST<T>::insert_node(T data)
{
	insert_node(this->Root,data);
}

template<class T>
inline void BST<T>::Print_inOrder()
{
	Print_inOrder(this->Root);
}

template<class T>
inline void BST<T>::Print_PostOrder()
{
	Print_PostOrder(this->Root);
}

template<class T>
inline void BST<T>::Print_PreOrder()
{
	Print_PreOrder(this->Root);
}

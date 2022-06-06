#include "stdafx.h"
#include "BT.h"


BT::BT()
{
	this->root = nullptr;
}


BT::~BT()
{

}

void BT::AddSibling(Node*root, string data)
{
	if(root->Right==nullptr)
	{
		root->Right= new Node(data);
	}
	else 
	{
		AddSibling(root->Right,data);
	}
}

void BT::InsertAtSibling(Node*root, string Source, string data)
{
	if(root!=nullptr)
	{
		if (root->data==Source)
		{
			AddSibling(root,data);
		}
		else
		{
			InsertAtSibling(root->Right,Source, data);
			InsertAtSibling(root->Left, Source, data);
		}
	}
}

void BT::InsertAtSibling(string Source, string data)
{
	if (this->root != nullptr)
	{
		InsertAtSibling(this->root, Source, data);
	}
}

void BT::CreateRoot(string data)
{
	if (this->root == nullptr)
	{
		this->root = new Node(data);
	}
	else
	{
		cout <<endl<< "Root is already created"<<endl;
	}
}



void BT::InsertAtChild(Node*root, string Source, string data)
{
	if (root!=nullptr)
	{
		if (root->data == Source)
		{
			AddChild(root,data);
		}
		else
		{ 
			InsertAtChild(root->Left,Source,data);
			InsertAtChild(root->Right,Source,data);
		}
	}
}

void BT::InsertAtChild(string Source, string data)
{
	if(this->root!=nullptr)
	{
		InsertAtChild(this->root,Source,data);
	}
}

void BT::AddChild(Node*root, string data)
{
	if (root->Left == nullptr)
	{
		root->Left = new Node(data);
	}
	else
	{
		AddSibling(root->Left, data);
	}
}

void BT::InsertingAtRootChild(string data)
{
	if (this->root->Left==nullptr)
	{
		this->root->Left = new Node(data);
	}
}

void BT::Display()
{
	if (this->root != nullptr)
	{
		this->Display(this->root);
		cout << endl;
	}
}
void BT::Display(Node*Root)
{
	if (Root != nullptr)
	{
		cout << Root->data << "  ";
		Display(Root->Left);
		Display(Root->Right);
	}
}
#include "BinaryTree.h"

void BinaryTree::RecrInorder(Node* Root)
{
	if (Root != nullptr)
	{
		RecrInorder(Root->Left);
		cout << Root->data<<" ";
		RecrInorder(Root->Right);
	}
}

void BinaryTree::RecrPreorder(Node* Root)
{
	if (Root != nullptr)
	{
		cout << Root->data << " ";
		RecrInorder(Root->Left);
		RecrInorder(Root->Right);
	}
}

void BinaryTree::RecrPostorder(Node* Root)
{
	if (Root == nullptr)
	{
		return;
	}

	RecrInorder(Root->Left);
	RecrInorder(Root->Right);
	cout << Root->data << " ";
}

BinaryTree::BinaryTree()
{
	this->Root = nullptr;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::CreateRoot(string data)
{
	if (this->Root == nullptr)
	{
		this->Root = new Node(data);
	}
}

void BinaryTree::RecrInorder()
{
	RecrInorder(this->Root);
}

void BinaryTree::RecrPreorder()
{
	this->RecrPreorder(this->Root);
}

void BinaryTree::RecrPostorder()
{
	this->RecrPostorder(this->Root);
}

void BinaryTree::InOrderTriverse()
{
    stack<Node*> S;
	Node* Current = this->Root;
	while (1)
	{
		while (Current!=nullptr)
		{
			S.push(Current);
			Current = Current->Left;
		}
		if (S.empty())break;
		Current = S.top();
		S.pop();
		if(Current!=nullptr)
		{
			cout << Current->data<<" ";
			Current = Current->Right;
		}
	}
	cout << endl;
}

void BinaryTree::PreOrderTriverse()
{
	stack<Node*> S;
	Node* Current = this->Root;
	while (1)
	{
		if (Current != nullptr)
		{
			cout << Current->data << " ";
		}
		while (Current != nullptr)
		{
			S.push(Current);
			Current = Current->Left;
		}
		if (S.empty())break;
		Current = S.top();
		S.pop();
		if (Current != nullptr)
		{
			Current = Current->Right;
		}
	}
	cout << endl;
}

void BinaryTree::PostOrderTriverse()
{
	stack<Node*> S;
	Node* Current = this->Root;
	while (1)
	{
		while (Current != nullptr)
		{
			S.push(Current);
			Current = Current->Left;
		}
		if (S.empty())break;
		Current = S.top();
		S.pop();
		if (Current != nullptr)
		{
			Current = Current->Right;
			cout << Current->data << " ";
		}
	}
	cout << endl;
}



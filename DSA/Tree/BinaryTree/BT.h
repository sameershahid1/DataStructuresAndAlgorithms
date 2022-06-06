#pragma once
#include"Node.h"
class BT
{
private:
	Node*root;

//Helper Funciton
void AddSibling(Node*root,string data);
void AddChild(Node*root, string data);

void InsertAtSibling(Node*root,string Source, string data);
void InsertAtChild(Node*root,string Source, string data);

void Display(Node*Root);
public:
	BT();
	~BT();

	void InsertAtSibling(string Source,string data);
	void InsertAtChild(string Source, string data);
	void InsertingAtRootChild(string data);
	void CreateRoot(string data);//Only use when root does not exist
	void Display();
};


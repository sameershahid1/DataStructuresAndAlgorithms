#pragma once
#include"Node.h"
#include<stack>
#include<queue>
class BinaryTree
{
private:
	//Helper Function
	void RecrInorder(Node*Root);
	void RecrPreorder(Node*Root);
	void RecrPostorder(Node* Root);
public:
	//Construtors
	Node* Root;
	BinaryTree();
	~BinaryTree();

	//Inserting
	void CreateRoot(string data);

	//Recrusing through Triverse
	void RecrInorder();
	void RecrPreorder();
	void RecrPostorder();

	//Iterator through Triverse
	void InOrderTriverse();
	void PreOrderTriverse();
	void PostOrderTriverse();

};


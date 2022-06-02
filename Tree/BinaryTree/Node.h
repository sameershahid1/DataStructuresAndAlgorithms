#pragma once
#include<string>
#include<iostream>
using namespace std;
class Node
{
public:
	string data;
	Node* Right;
	Node* Left;
	Node(string data=0);
	~Node();
};

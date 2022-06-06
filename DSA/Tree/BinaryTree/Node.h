#pragma once
#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
	string data;
	Node*Left;
	Node*Right;
	Node(string data);
	~Node();
};


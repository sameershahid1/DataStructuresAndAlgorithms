#include"LStack.h"
int main() 
{
	LStack<int> arr;
	arr.Push(1);
	arr.Push(2);
	arr.Push(3);
	cout<<arr.Pop()<<" ";
	cout<<arr.Pop()<<" ";
	cout<<arr.Pop()<<" ";

	return 0;
}
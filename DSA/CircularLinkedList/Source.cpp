#include"CircularLinkedList.h"

int main() 
{
	CircularLinkedList<int> q1;
	q1.insetAtFront(1);
	q1.insertAtEnd(2);
	q1.insertAtEnd(3);

	cout << q1.RemoveFromFront();

	return 0;
}
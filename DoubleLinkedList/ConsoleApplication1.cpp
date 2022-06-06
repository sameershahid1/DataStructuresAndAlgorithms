#include"DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<int> list;
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtEnd(5);
	cout<<"TOTAL SUM OF EACH NUMBER: " << list.sum_of_list() << endl;
	cout<<"PRODUCT OF EACH PRIME NUMBER: " << list.product_of_Prime() << endl;
	cout << "DISPLAYING EVEN NUMBERS: ";
	list.Display_Even();
	cout << "DISPLAYING OCCURANCE OF DATA:\n";
	list.occurance_of_key();
	list.reverse();
	list.Display();
	if (list.Palindrome_Check()==true)
	{
		cout << endl << "Palindrome does Exist"<<endl;
	}
	return 0;
}


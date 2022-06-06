#include "stdafx.h"
#include"BT.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BT B;
	B.CreateRoot("MyComputer");
	B.InsertingAtRootChild("C");
	B.InsertAtSibling("C","D");
    B.InsertAtSibling("D","F");
	B.InsertAtSibling("F", "G");
	B.InsertAtChild("C","Document");
	B.InsertAtChild("Document","Download");
	B.Display();

	return 0;
}


#include <iostream>
#include"Class_Tree.h"
using namespace std;

int main()
{
	BinarySearchTree *obj = new BinarySearchTree();
	obj->Insert(5);
	obj->Insert(8);
	obj->Insert(4);
	obj->Insert(6);
	obj->Insert(9);
	obj->Insert(7);


	cout << "Before Deletion " << endl;
	obj->PrintInorder();
	obj->Delete(7);
	cout << "After Deletion " << endl;
	obj->PrintInorder();
	return 0;
}
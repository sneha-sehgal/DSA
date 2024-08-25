#include <iostream>
#include"class_LinkedList.h"
using namespace std;

int main()
{
	LinkedList *obj = new LinkedList;
	obj->add(1);
	obj->add(2, 1);//adds element before 1, if no 0 will add 2 after 1
	obj->add(3, 2);
	obj->add(0,3);
	obj->print();
	return 0;
}
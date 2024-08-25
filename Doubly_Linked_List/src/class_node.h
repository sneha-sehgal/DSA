#include<iostream>
using namespace std;

class Node
{
    public://has to be public to be accessed in the class LinkedList
        int data;
        Node *next;
        Node *prev;
};
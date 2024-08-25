#include<iostream>
#include"class_node.h"
using namespace std;

class LinkedList
{
    private:
        int counter = 0;//counts the number of elements in the Linked List
        Node *start = NULL;//start will be of a pointer to class node

        void add_to_start(Node *new_node)
        {
            if (start == NULL)
            {
                start = new_node;
                new_node->next = NULL;
                new_node->prev = NULL;
            }else//when pos == 0
            {
                new_node->next = start;
                new_node->prev = NULL;
                start->prev = new_node;
                start = new_node;
            }
        }

        void add_to_middle(Node *new_node, Node *cur_node)
        {
            new_node->next = cur_node->next;
            new_node->prev = cur_node;
            (cur_node->next)->prev = new_node;
            cur_node->next = new_node;
        }
    public:

    void add(int new_data, int pos = -1)
    {
        Node *new_node = new Node();
        new_node->data = new_data;
        if (start == NULL || pos == 0)//add node to the beginning
        {
            add_to_start(new_node);
        }else if(pos == -1 || pos >= counter)//add at the end of the Linked List when pos is -1 or greater than number of elements in the Linked List 
        {
            Node *cur_node = start;
            while(cur_node->next != NULL)
            {
                cur_node = cur_node->next;
            }
            cur_node->next = new_node;
            new_node->next = NULL;
            new_node->prev = cur_node;
        }
        else //in the middle
        {
            Node *cur_node = start;
            for(int i = 1; i < pos; i++)
            {
                cur_node = cur_node->next;
            }
            add_to_middle(new_node, cur_node);
            
        }
        cout << "added value : " << new_node->data << endl;
        counter++;
        
    }

    void print()
    {
        Node *cur_node = start;
        while (cur_node->next != NULL)
        {
            cout << cur_node->data << endl;
            cur_node = cur_node->next;
        }
        cout << cur_node->data << endl;
    }
};
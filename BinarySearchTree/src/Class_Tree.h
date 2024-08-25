#include<iostream>
#include<stack>
#include<queue>
#include"class_Node.h"
using namespace std;

class BinarySearchTree
{
    private:
        Node *root = NULL;
        int counter = 0;

        int InorderSuccessor(int key)
        {
            int arr[counter];
            int i = 0;
            stack <Node *> Stack;
            Node *temp = root;
            while (temp != NULL || Stack.empty() == false)
            {
                while (temp != NULL)
                {
                    Stack.push(temp);
                    temp = temp->left;
                }
                temp = Stack.top();
                Stack.pop();
                arr[i] = temp->data;
                i++;
                temp = temp->right;
            }
            for (i = 0; i < counter; i++){
                if (arr[i] == key){
                    break;
                }
            }
            return arr[i+1];
        }

    public:
        
        void Insert(int new_data)
        {
            Node *new_node = new Node();
            new_node -> data = new_data;
            if (root == NULL)
            {
                root = new_node;
                new_node->left = NULL;
                new_node->right = NULL;
            }
            else
            {
                Node *next_ptr = root;
                while (next_ptr != NULL)//tree has more than 1 node(root node)
                {
                    if (new_data < next_ptr->data)
                    {
                        if( next_ptr->left == NULL )
                        {
                            next_ptr->left = new_node;
                            new_node->left = NULL;
                            new_node->right = NULL;
                            break;
                        }
                        else
                        {
                            next_ptr = next_ptr->left;
                        }
                        
                    }
                    else if (new_data > next_ptr->data)
                    {
                        if(next_ptr->right == NULL)
                        {
                            next_ptr->right = new_node;
                            new_node->left = NULL;
                            new_node->right = NULL;
                            break;
                        }
                        else
                        {
                            next_ptr = next_ptr->right;
                        }
                    }
                    else if (new_data == next_ptr->data){
                        cout << "Element Already Exists" << endl;
                        break;
                    }
                }
            }
            counter++;
        }

        void PrintInorder()
        {
            stack <Node *> Stack;
            Node *temp = root;
            while (temp != NULL || Stack.empty() == false)
            {
                while (temp != NULL)
                {
                    Stack.push(temp);
                    temp = temp->left;
                }
                temp = Stack.top();
                Stack.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
            cout << endl;
        }

        void PrintPreorder()
        {
            stack <Node *> Stack;
            Node *temp = root;
            Stack.push(temp);
            while (!Stack.empty())
            {
                temp = Stack.top();
                cout << temp->data << " ";
                Stack.pop();
                
                if (temp->right){
                    Stack.push(temp->right);
                }
                if (temp->left){
                    Stack.push(temp->left);
                }
            }
            cout << endl;
        }

        void PrintPostorder()
        {
            stack <Node *> Stack;
            Stack.push(root);
            while (!Stack.empty()){
                Node *temp = Stack.top();
                cout << temp->data << " ";
                Stack.pop();

                if (temp->left){
                    Stack.push(temp->left);
                }
                if (temp->right){
                    Stack.push(temp->right);
                }
                
            }
            cout << endl;
        }

        void PrintLevelOrder()
        {

            queue<Node *> Queue;
            Queue.push(root);
            Node *temp;
            while(!Queue.empty())
            {
                temp = Queue.front();
                Queue.pop();
                cout << temp->data << " ";
                if (temp->left)
                    Queue.push(temp->left);
                if (temp->right)
                    Queue.push(temp->right);
            }
        }

        Node* Search(int key){
            Node *temp = root;
            while (temp != NULL && temp->data != key)
            {
                if (key > temp->data)
                    temp = temp->right;
                else if(key < temp->data)
                    temp = temp->left;
            }
            cout << "value of temp : " << temp->data << endl; 
            return temp;

        }
        void Delete(int key)
        {
            /*
            Condition 1 -- Root is to be Deleted

            Condition 2 -- Parent with 1 Child is to be Deleted
                Swap the value of the parent with that of the Child
                Value to be Deleted in now at the leaf node
                Delete the leaf node
            
            Condition 3 -- Parent with 2 Children is to be Deleted
                Do an inorder Traversal
                Swap the Parent with its Inorder Successor
                Successor node will be at a leaf node
                Delete the leaf node 

            Condition 4 -- Leaf Node is to be Deleted

            Condition 5 -- Key is not found in any node

            Condition 1 and Condition 3 can be done together as Root too will have Children
            */
            Node *temp = root;
            Node *prev = NULL;
            while (temp != NULL && temp->data != key)
            {
                prev = temp;
                if (key > temp->data)
                {
                    temp = temp->right;
                }
                else if(key < temp->data)
                {
                    temp = temp->left;
                }
            }
            //node has one child or less
            if(temp->left == NULL || temp->right == NULL)
            {
                if (temp->right == NULL && temp->left == NULL)
                {

                    if(prev->right == temp)
                    //if (key > prev->data)
                    {
                        prev->right = NULL;
                    }
                    else
                    {
                        prev->left = NULL;
                    } 
                }
                // node has one child
                else if (key > prev->data)
                {
                    if (temp->left == NULL){
                        prev->right = temp->right;
                    }
                    else if (temp->right == NULL){
                        prev->right = temp->left;
                    }
                }
                else if (key < prev->data)
                {
                    if (temp->left == NULL){
                        prev->left = temp->right;
                    }
                    else if (temp->right == NULL){
                        prev->left = temp->left;
                    }
                }
                free(temp);
            } 

            else if (temp->left != NULL && temp->right != NULL)
            {
                cout << "Inside deletion of node with 2 children" << endl;
                // If the node has 2 children
                int newdata = InorderSuccessor(key);
                temp->data = newdata;

                if (newdata == (temp->right)->data)
                {
                    temp->right = NULL;
                }
                else
                {
                    temp->left = NULL;
                }
                free(Search(newdata));
            }
            counter-- ;
        }
        
};
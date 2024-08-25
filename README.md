#include <iostream>
#include <string>
using namespace std;
template <class T, int s=10> class Stack
{
    private :
        int top;
        int size;
        T *ptr;
    public:
        Stack()
        {
            size = s;
            top = -1;
            ptr = new T[size];
        }
        void push(T new_data)
        {
            if (top == size - 1)
            {
                cout << "stack overflow" << endl;
            }
            else
            {
                top ++;
                ptr[top] = new_data;
            }
        }
        T pop()
        {
            if (top == -1)
            {
                cout << "stack underflow" << endl;
            }
            else
            {
                T val = ptr[top];
                top --;
                return val;
            }
        }   
        void print()
        {
            for (int i = top; i >= 0; i--)
            {
                cout << ptr[i] << endl;
            }
        }
        ~Stack()
        {
            delete[] ptr;
        }
        T peek()
        {
            return ptr[top];
        }
        
};
int main()
{
    Stack <int, 50> int_stack;
    Stack <string> str_stack;
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    int_stack.push(4);
    int_stack.push(5);
    str_stack.push("a");
    str_stack.push("b");
    str_stack.push("c");
    str_stack.pop();
    int_stack.pop();
    int_stack.print();
    str_stack.print();
    return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_SIZE 10
int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

bool isFull(int top)
{
    if (top1 == MAX_SIZE - 1)
    {
        return true;
    }
    return false;
}
bool isEmpty(int top)
{
    if (top == -1)
    {
        return true;
    }
    return false;
}
void push(int *stack, int top, int val)
{
    if (isFull(top))
    {
        cout << "cant add" << endl;
        return;
    }
    stack[++top] = val;
}
void pop(int *stack, int top)
{
    if (isEmpty(top))
    {
        cout << "cant pop " << endl;
        return;
    }
    --top;
}
void display(int *stack, int top)
{
    if (isEmpty(top))
    {
        cout << "STACK IS empty" << endl;
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Choose an operation:\n";
        cout << "1. Push stack1 \n2. Pop stack1 \n3. Display stack1\n";
        cout << "4. Push stack2 \n5. Pop stack2 \n6. Display stack2\n7. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int val1;
            cout << "Enter a value to push: ";
            cin >> val1;
            push(stack1, top1, val1);
            break;
        case 2:
            pop(stack1, top1);
            break;
        case 3:
            display(stack1, top1);
            break;
        case 4:
            int val2;
            cout << "Enter a value to push: ";
            cin >> val2;
            push(stack2, top2, val2);
            break;
        case 5:
            pop(stack2, top2);
            break;
        case 6:
            display(stack2, top2);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
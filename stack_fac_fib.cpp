#include <iostream>
#include <cstdlib>
using namespace std;

int n = 20;
int MAX = n;
int stack[20];
// int stack2[10];
int top = -1;

void push(int n)
{
    if (top == MAX - 1)
    {
        cout << "stack is full" << endl;
        return;
    }
    stack[++top] = n;
}
int pop()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    int a = stack[top];
    top--;
    return a;
}
int fact_loop(int n)
{
    int k = 1;
    if (n == 0)
        return 1;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            k *= i;
            push(k);
        }
        return stack[n - 1];
    }
}
int fact_recur(int n)
{
    int result = 1;

    while (n != 0)
    {
        push(n--);
        result *= pop();
    }
    return result;
}

int fib_loop(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    int a = 0, b = 1;
    push(a);
    push(b);
    for (int i = 2; i < n; i++)
    {
        a = a + b;
        push(a);//
        b = a + b;
        push(b);
    }
    return stack[n];
}

int main()
{
    // cout << fact_loop(5) << endl;
    // cout << fact_recur(5) << endl;
    // cout << fib_loop(5) << endl;
    cout << fib_loop(10) << endl;
}
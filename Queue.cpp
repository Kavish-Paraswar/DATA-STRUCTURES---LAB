#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX_SIZE 10

int queue1[MAX_SIZE];
int queue2[MAX_SIZE];
int front1 = -1;
int rear1 = -1;
int front2 = -1;
int rear2 = -1;

void enq(int *queue, int &front, int &rear, int x)
{
    if (rear == MAX_SIZE - 1)
    {
        cout << "Its full" << endl;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;
}
void delq(int *queue, int &front, int &rear)
{
    if (front == -1)
    {
        cout << "Its empty" << endl;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display(int *queue, int front, int rear)
{
    if (front == -1)
        cout << "Its empty";
    else{
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
    cout << endl;
}

// void enqueueF(queue<int> &p, int x)
// {

//     p.push(x);
// }

int main()
{

    enq(queue1, front1, rear1, 10);
    enq(queue2, front2, rear2, 50);
    enq(queue1, front1, rear1, 20);
    enq(queue2, front2, rear2, 60);
    enq(queue1, front1, rear1, 30);
    enq(queue2, front2, rear2, 70);
    delq(queue1, front1, rear1);
    delq(queue2, front2, rear2);
    display(queue1, front1, rear1);
    display(queue2, front2, rear2);
    return 0;
}
// queue<int> p;
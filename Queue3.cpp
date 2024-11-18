#include <iostream>
using namespace std;
#define MAX_SIZE 10

struct Deque {
    int data[MAX_SIZE];
    int front;
    int rear;
};

void initializeDeque(Deque* p) {
    p->front = -1;
    p->rear = -1;
}

bool isFull(Deque* p) {
    return ((p->front == 0 && p->rear == MAX_SIZE - 1) || (p->front == p->rear + 1));
}

bool isEmpty(Deque* p) {
    return (p->front == -1);
}

void insertFront(Deque* p, int x) {
    if (isFull(p)) {
        cout << "Deque is full\n";
        return;
    }
    if (p->front == -1) {
        p->front = p->rear = 0;
    }
    else if (p->front == 0) {
        p->front = MAX_SIZE - 1;
    }
    else {
        p->front = p->front - 1;
    }
    p->data[p->front] = x;
    cout << "Inserted " << x << " at front\n";
}

void insertRear(Deque* p, int x) {
    if (isFull(p)) {
        cout << "Deque is full\n";
        return;
    }
    if (p->front == -1) {
        p->front = p->rear = 0;
    }
    else if (p->rear == MAX_SIZE - 1) {
        p->rear = 0;
    }
    else {
        p->rear = p->rear + 1;
    }
    p->data[p->rear] = x;
    cout << "Inserted " << x << " at rear\n";
}

void deleteFront(Deque* p) {
    if (isEmpty(p)) {
        cout << "Deque is empty\n";
        return;
    }
    cout << "Deleted " << p->data[p->front] << " from front\n";
    if (p->front == p->rear) {
        p->front = p->rear = -1;
    }
    else if (p->front == MAX_SIZE - 1) {
        p->front = 0;
    }
    else {
        p->front = p->front + 1;
    }
}

void deleteRear(Deque* p) {
    if (isEmpty(p)) {
        cout << "Deque is empty\n";
        return;
    }
    cout << "Deleted " << p->data[p->rear] << " from rear\n";
    if (p->front == p->rear) {
        p->front = p->rear = -1;
    }
    else if (p->rear == 0) {
        p->rear = MAX_SIZE - 1;
    }
    else {
        p->rear = p->rear - 1;
    }
}

void display(Deque* p) {
    if (isEmpty(p)) {
        cout << "Deque is empty\n";
        return;
    }
    cout << "Deque elements: ";
    int i = p->front;
    while (true) {
        cout << p->data[i] << " ";
        if (i == p->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main() {
    Deque dq;
    initializeDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 3);

    display(&dq);

    deleteRear(&dq);
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    insertFront(&dq, 15);
    insertRear(&dq, 25);

    display(&dq);

    return 0;
}

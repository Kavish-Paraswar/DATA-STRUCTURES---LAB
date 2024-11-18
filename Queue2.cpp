#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // ADD operation (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {  // Queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // DELETE operation (dequeue)
    void dequeue() {
        if (front == nullptr) {  // Queue is empty
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;

        if (front == nullptr) {  // Queue is now empty
            rear = nullptr;
        }

        delete temp;
    }

    // Display the elements of the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();  // Attempting to dequeue from an empty queue

    return 0;
}

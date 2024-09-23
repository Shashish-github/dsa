#include <iostream>

using namespace std;

int naam[10];
int N = 10;
int front = -1;
int rear = -1;

bool IsEmpty() {
    if (front == -1 && rear == -1) {
        return true;
    } else {
        return false;
    }
}

bool IsFull() {
    if (rear == N - 1) {
        return true;
    } else {
        return false;
    }99
}

void Enqueue(int x) {
    if (IsFull()) {
        cout << "not available space" << x << endl;
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    naam[rear] = x;
    cout << x << " line me aa gya" << endl;
}

int Dequeue() {
    int x = -1;
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return x;
    } else if (front == rear) {
        x = naam[front];
        front = rear = -1;
    } else {
        x = naam[front];
        front++;
    }
    return x;
}

int main() {
    if (IsEmpty()) {
        cout << "line khali hai" << endl;
    } else {
        cout << "line khali nhi hai" << endl;
    }

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);

    cout << "Dequeued element: " << Dequeue() << endl;
    cout << "Dequeued element: " << Dequeue() << endl;
    cout << "Dequeued element: " << Dequeue() << endl;

    Enqueue(6);
    Enqueue(7);

    cout << "Dequeued element: " << Dequeue() << endl;
    cout << "Dequeued element: " << Dequeue() << endl;
    cout << "Dequeued element: " << Dequeue() << endl;
    cout << "Dequeued element: " << Dequeue() << endl;

    return 0;
}

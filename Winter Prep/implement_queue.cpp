#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    
    Queue() {
        front = NULL;
        rear = NULL;
    }

    
    Node* createNode(int data) {
        return new Node(data);
    }

    
    bool isEmpty() {
        return (front == NULL);
    }

    
    void enqueue(int data) {
        Node* newNode = createNode(data);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return data;
    }

    
    void displayQueue() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }
};

int main() {
    Queue q;

    int choice;
    do {
        cout << "Queue Operations:\n";
        cout << "1. Enqueueu\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Get Front\n";
        cout << "5. Get Rear\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the element to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            }
            case 2: {
                int data = q.dequeue();
                if (data != -1) {
                    cout << "Dequeued element: " << data << "\n";
                }
                break;
            }
            case 3: {
                cout << "Queue: ";
                q.displayQueue();
                break;
            }
            case 4: {
                int data = q.getFront();
                if (data != -1) {
                    cout << "Front element: " << data << "\n";
                }
                break;
            }
            case 5: {
                int data = q.getRear();
                if (data != -1) {
                    cout << "Rear element: " << data << "\n";
                }
                break;
            }
            case 6: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
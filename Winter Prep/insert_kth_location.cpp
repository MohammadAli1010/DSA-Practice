#include <iostream>
using namespace std;


class Node {
private:
    int data;
    Node* next;

public:
    
    Node(int value) : data(value), next(nullptr) {}

    
    int getData() const {
        return data;
    }

    
    Node* getNext() const {
        return next;
    }

    
    void setNext(Node* node) {
        next = node;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    
    void insertAtKthLocation(int data, int k) {
        if (k < 0) {
            cout<< "Invalid k value. k should be greater than or equal to 0." <<endl;
            return;
        }

        
        Node* newNode = new Node(data);

        
        if (k == 0) {
            newNode->setNext(head);
            head = newNode;
        } else {
            Node* current = head;
            int count = 0;

            
            while (current != nullptr && count < k - 1) {
                current = current->getNext();
                count++;
            }

            
            if (current == nullptr) {
                current = head;
                while (current->getNext() != nullptr) {
                    current = current->getNext();
                }
                current->setNext(newNode);
            } else {
                newNode->setNext(current->getNext());
                current->setNext(newNode);
            }
        }
    }

    
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout <<endl;
    }
};

int main() {
    LinkedList list;

    
    list.insertAtKthLocation(10, 0);
    list.insertAtKthLocation(20, 1);
    list.insertAtKthLocation(30, 2);
    list.insertAtKthLocation(5, 0);

    
    cout << "Linked List: ";
    list.printList();

    return 0;
}
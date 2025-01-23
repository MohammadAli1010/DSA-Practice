//Create a singly linked list asking the user to input N elements. Display the single linked list in reverse order.

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


class LinkedList {
private:
    Node* head;

public:
    
    LinkedList() {
        head = NULL;
    }

    
    Node* createNode(int data) {
        return new Node(data);
    }

    
    void insertNode(int data) {
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* lastNode = head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    
    void printReverse() {
        printReverseRecursive(head);
    }

    
    void printReverseRecursive(Node* node) {
        if (node == NULL) {
            return;
        }
        printReverseRecursive(node->next);
        cout << node->data << " ";
    }

    
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        list.insertNode(data);
    }

    cout << "Linked List: ";
    list.printList();

    cout << "Linked List in Reverse Order: ";
    list.printReverse();
    cout << "\n";

    return 0;
}
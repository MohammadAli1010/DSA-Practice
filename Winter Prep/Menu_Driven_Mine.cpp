#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;

public:
    
    LinkedList() {
        head = nullptr;
    }

    
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};


void displayMenu() {
    cout << "\nLinked List Menu:" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Traverse the list" << endl;
    cout << "4. Exit from the program" << endl;
}

int main() {
    LinkedList linkedList;

    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the data to insert at the beginning: ";
                cin >> data;
                linkedList.insertAtBeginning(data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter the data to insert at the end: ";
                cin >> data;
                linkedList.insertAtEnd(data);
                break;
            }
            case 3:
                cout << "Linked List: ";
                linkedList.traverse();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
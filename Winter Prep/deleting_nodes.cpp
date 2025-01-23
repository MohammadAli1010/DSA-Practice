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

    
    void insertNode(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    
    void deleteFirstNode() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "First node deleted successfully." << endl;
        }
    }

    
    void deleteLastNode() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last node deleted successfully." <<endl;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            cout << "Last node deleted successfully." <<endl;
        }
    }

    
    void deleteFirstOccurrence(int value) {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
        } else if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "First occurrence of " << value << " deleted successfully." << endl;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                if (temp->next->data == value) {
                    Node* nodeToDelete = temp->next;
                    temp->next = temp->next->next;
                    delete nodeToDelete;
                    cout << "First occurrence of " << value << " deleted successfully." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Value " << value << " not found in the linked list." << endl;
        }
    }

    
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);

    
    cout << "Linked List: ";
    list.printList();

    
    list.deleteFirstNode();
    cout << "Linked List after deleting the first node: ";
    list.printList();

    
    list.deleteLastNode();
    cout << "Linked List after deleting the last node: ";
    list.printList();

    
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(2);
    cout << "Linked List: ";
    list.printList();
    list.deleteFirstOccurrence(2);
    cout << "Linked List after deleting the first occurrence of 2: ";
    list.printList();

    return 0;
}
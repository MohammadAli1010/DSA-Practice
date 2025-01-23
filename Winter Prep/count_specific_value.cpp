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

    
    int countOccurrences(int value) {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<endl;
    }
};

int main() {
    LinkedList list;

    
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(2);
    list.insertNode(4);
    list.insertNode(2);
    list.insertNode(5);

    
    cout << "Linked List: ";
    list.printList();

    
    int value;
    cout << "Enter the value to count: ";
    cin >> value;
    int count = list.countOccurrences(value);

    
    cout << "The value " << value << " occurs " << count << " times in the linked list." <<endl;

    return 0;
}
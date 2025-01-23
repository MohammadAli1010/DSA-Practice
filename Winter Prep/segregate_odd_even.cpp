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

    
    void segregateEvenOdd() {
        if (head == NULL) {
            cout << "Linked list is empty." <<endl;
            return;
        }

        Node* evenHead = NULL;
        Node* oddHead = NULL;
        Node* evenTail = NULL;
        Node* oddTail = NULL;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            temp = temp->next;
        }

        if (oddHead != NULL) {
            oddTail->next = NULL;
        }

        if (evenHead != NULL) {
            evenTail->next = oddHead;
        } else {
            head = oddHead;
        }

        head = evenHead;
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
    list.insertNode(4);
    list.insertNode(5);
    list.insertNode(6);

    
    cout << "Linked List: ";
    list.printList();

    
    list.segregateEvenOdd();

    
    cout << "Linked List after segregation: ";
    list.printList();

    return 0;
}
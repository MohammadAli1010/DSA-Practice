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

   
    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    
    void mergeLists(LinkedList& list1, LinkedList& list2) {
        Node* temp1 = list1.head;
        Node* temp2 = list2.head;

        while (temp1 && temp2) {
            if (temp1->data < temp2->data) {
                insertNode(temp1->data);
                temp1 = temp1->next;
            } else {
                insertNode(temp2->data);
                temp2 = temp2->next;
            }
        }

        while (temp1) {
            insertNode(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2) {
            insertNode(temp2->data);
            temp2 = temp2->next;
        }
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;
    LinkedList mergedList;

    
    list1.insertNode(1);
    list1.insertNode(3);
    list1.insertNode(5);
    list1.insertNode(7);

    
    list2.insertNode(2);
    list2.insertNode(4);
    list2.insertNode(6);
    list2.insertNode(8);

    cout << "Linked List 1: ";
    list1.displayList();

    
    cout << "Linked List 2: ";
    list2.displayList();

    
    mergedList.mergeLists(list1, list2);

    
    cout << "Merged Linked List: ";
    mergedList.displayList();

    return 0;
}
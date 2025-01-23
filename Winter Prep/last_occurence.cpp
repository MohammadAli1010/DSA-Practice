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

    
    int findLastOccurrence(int n) {
        int position = -1;
        Node* temp = head;
        int index = 0;

        while (temp != NULL) {
            if (temp->data == n) {
                position = index;
            }
            temp = temp->next;
            index++;
        }

        return position;
    }

    
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << std::endl;
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

    
    std::cout << "Linked List: ";
    list.printList();

    
    int n;
    cout << "Enter the value to find: ";
    cin >> n;
    int position = list.findLastOccurrence(n);

    
    if (position != -1) {
        cout << "The last occurrence of the value " << n << " is at position " << position << std::endl;
    } else {
        cout << "The value " << n << " is not found in the linked list." <<endl;
    }

    return 0;
}


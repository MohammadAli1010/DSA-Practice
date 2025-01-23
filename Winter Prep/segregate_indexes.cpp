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

    
    void printList(const char* listName) {
        cout << listName << ": ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    
    void segregateEvenOddNodes() {
        if (head == NULL || head->next == NULL) {
            return;
        }

        Node* evenHead = NULL;
        Node* oddHead = NULL;
        Node* evenTail = NULL;
        Node* oddTail = NULL;

        int index = 0;
        Node* temp = head;
        while (temp) {
            if (index % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = temp;
                    evenTail = evenHead;
                } else {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = temp;
                    oddTail = oddHead;
                } else {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            }
            temp = temp->next;
            index++;
        }

        
        if (evenTail) {
            evenTail->next = NULL;
        }

        
        if (oddTail) {
            oddTail->next = NULL;
        }

       
        cout << "Original List: ";
        temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<< "\n";

        
        cout << "Even-indexed elements: ";
        temp = evenHead;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";

        
        cout << "Odd-indexed elements: ";
        temp = oddHead;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<< "\n";
    }
};

int main() {
    LinkedList list;

    
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);

    
    list.segregateEvenOddNodes();

    return 0;
}
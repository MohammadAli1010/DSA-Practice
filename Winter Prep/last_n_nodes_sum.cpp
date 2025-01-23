#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    int sumOfLastNNodes(int n) {
        if (head == nullptr || n <= 0) {
            return 0; // 
        }

        Node* slow = head;
        Node* fast = head;

        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        
        int sum = 0;
        while (slow != nullptr) {
            sum += slow->data;
            slow = slow->next;
        }

        return sum;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    cout << "Linked List: ";
    list.display();

    int n;
    cout << "Enter the number of last nodes to sum: ";
    cin >> n;

    int sum = list.sumOfLastNNodes(n);
    cout << "Sum of the last " << n << " nodes: " << sum << endl;

    return 0;
}
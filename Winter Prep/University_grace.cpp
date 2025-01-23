#include <iostream>
#include <string>
using namespace std;


struct Student {
    string name;
    int marks;
    bool givenGrace;
};


struct Node {
    Student data;
    Node* next;
};

void addStudent(Node*& head) {
    Node* newNode = new Node;
    cout << "Enter student name: ";
    cin.ignore(); 
    getline(cin, newNode->data.name);
    cout << "Enter student marks: ";
    cin >> newNode->data.marks;
    newNode->data.givenGrace = false; 
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displayStudents(const Node* head) {
    while (head != nullptr) {
        cout << "Name: " << head->data.name << ", Marks: " << head->data.marks;
        if (head->data.givenGrace) {
            cout << " (Given Grace)";
        }
        cout <<endl;
        head = head->next;
    }
}


void provideGrace(Node* head) {
    int passingMarks = 30;
    while (head != nullptr) {
        if (head->data.marks < passingMarks) {
            head->data.marks = passingMarks;
            head->data.givenGrace = true;
        }
        head = head->next;
    }
}


void displayMenu() {
    cout << "Menu:" <<endl;
    cout << "1. Enter student name and marks" <<endl;
    cout << "2. Display student information" <<endl;
    cout << "3. Provide grace to students" <<endl;
    cout << "4. Exit" <<endl;
}

int main() {
    using namespace std;
    Node* head = nullptr;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent(head);
                break;
            case 2:
                displayStudents(head);
                break;
            case 3:
                provideGrace(head);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
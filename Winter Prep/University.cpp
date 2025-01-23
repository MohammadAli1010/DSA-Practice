#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int marks;
    bool givenGrace;
};

struct Node
{
    Student data;
    Node* next;
};

void addStudent(Node*& head){
    Node* newNode = new Node;
    cout <<"Enter student name: ";
    cin.ignore();
    getline(cin, newNode->data.name);
    cout<<"Enter student marks: ";
    cin>> newNode->data.marks;
    newNode->data.givenGrace= false;
    newNode->next = nullptr;
}


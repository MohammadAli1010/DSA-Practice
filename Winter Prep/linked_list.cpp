#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;


        Node(int value){
            data = value;
            next = nullptr;
        }
};


class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }

    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
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

    void traverse(){
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data<<" ";
            current = current->next;
        }
        cout <<endl;
        
    }

    void insetAtPos(Node**head,int k,int val)
    {
        if(*head == NULL)
        {
            cout<<"Cannot be inserted";
            return;
        }

        Node* ptr=new Node(val);
        Node* temp=*head;
        while (k-2>0)
        {
            temp = temp ->next;
            k--;
        }

        ptr->next = temp->next;
        temp->next = ptr;
        
    }

    int countNodes(Node* head){
        if (head == NULL)
        {
            return 0;
        }

        int count = 1;
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        return count;
        
        
    }



    ~LinkedList(){
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        
    }
};

void displayMenu(){
    cout << "\nLinked List Menu:" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Traverse the list" << endl;
    cout << "4. Insert at kth position"<<endl;
    cout << "4. Exit from the program" << endl;
    
}

int main(){
    Node*head = NULL;
    LinkedList LinkedList;

    while (true){
        displayMenu();
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
        case 1: {
            int data;
            cout<<"Enter the data to insert at the beginning: ";
            cin >> data;
            LinkedList.insertAtBeginning(data);
            break;
        }

        case 2:{
            int data;
            cout<<"The total number of nodes:";
            LinkedList.countNodes(&head);
        }

        case 3: {
                int data;
                cout << "Enter the data to insert at the end: ";
                cin >> data;
                LinkedList.insertAtEnd(data);
                break;
        }
        case 4: {
            int data;
            cout<<"Linked List: ";
            LinkedList.traverse();
            break;
        }
        case 5:
            cout<<"Exiting the program: "<<endl;
            return 0;
        default:
            cout<<"Invalid choice. Please try again. "<<endl;
        
    }
    
}
return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Borrower
{
    string name;
    string mobile;
    double borrowedAmount;
    Borrower* next;
};

void addBorrower(Borrower*& head, string name, string mobile, double borrowedAmount){
    Borrower* newBorrower = new Borrower();
    newBorrower->name = name;
    newBorrower->mobile = mobile;
    newBorrower->borrowedAmount = borrowedAmount;
    newBorrower->next = nullptr;

    if (head == nullptr)
    {
        head = newBorrower
    } else {
        Borrower* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newBorrower;
        
    }
    cout<< "Borrower added successfully!\n";
    
}

void recordPayment(Borrower*&head, string mobile, double amountPaid){
    Borrower* temp = head;
    Borrower* prev = nullptr;

    while (/* condition */)
    {
        /* code */
    }
    
}

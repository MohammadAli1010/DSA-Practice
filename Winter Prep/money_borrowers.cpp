//Ques 4 - A Linked list is proposed for storing the name, mobile and the borrowed amount of the borrowers assuming the mobile number is unique. If any borrower pays back any amount, deduct the amount from his node. If the balance is zero, delete his/her Node. Create a menu driven code for the following options: 1) for adding a borrower, 2) for recording the amount paid by the borrower, 3) for displaying the details of the borrowers in the list, 4) for exit

#include <iostream>
#include <string>
using namespace std;


struct Borrower {
    string name;
    string mobile;
    double borrowedAmount;
    Borrower* next;
};


void addBorrower(Borrower*& head, string name, string mobile, double borrowedAmount) {
    Borrower* newBorrower = new Borrower();
    newBorrower->name = name;
    newBorrower->mobile = mobile;
    newBorrower->borrowedAmount = borrowedAmount;
    newBorrower->next = nullptr;

    if (head == nullptr) {
        head = newBorrower;
    } else {
        Borrower* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBorrower;
    }
    cout << "Borrower added successfully!\n";
}


void recordPayment(Borrower*& head, string mobile, double amountPaid) {
    Borrower* temp = head;
    Borrower* prev = nullptr;

    while (temp != nullptr) {
        if (temp->mobile == mobile) {
            temp->borrowedAmount -= amountPaid;
            cout << "Amount paid successfully!\n";

            
            if (temp->borrowedAmount <= 0) {
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Borrower's balance is zero. Node deleted.\n";
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Borrower with mobile number " << mobile << " not found.\n";
}


void displayBorrowers(Borrower* head) {
    if (head == nullptr) {
        cout << "No borrowers in the list.\n";
        return;
    }

    Borrower* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Mobile: " << temp->mobile
             << ", Borrowed Amount: " << temp->borrowedAmount << "\n";
        temp = temp->next;
    }
}


int main() {
    Borrower* head = nullptr;
    int choice;
    string name, mobile;
    double amount;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add a borrower\n";
        cout << "2. Record amount paid by a borrower\n";
        cout << "3. Display all borrowers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter borrower's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter borrower's mobile number: ";
                cin >> mobile;
                cout << "Enter borrowed amount: ";
                cin >> amount;
                addBorrower(head, name, mobile, amount);
                break;

            case 2:
                cout << "Enter borrower's mobile number: ";
                cin >> mobile;
                cout << "Enter amount paid: ";
                cin >> amount;
                recordPayment(head, mobile, amount);
                break;

            case 3:
                displayBorrowers(head);
                break;

            case 4:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
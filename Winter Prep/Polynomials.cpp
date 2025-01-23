#include <iostream>
using namespace std;

class Node {
public:
    int coefficient;
    int power;
    Node* next;

    Node(int coefficient, int power) {
        this->coefficient = coefficient;
        this->power = power;
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

    void append(int coefficient, int power) {
        Node* newNode = new Node(coefficient, power);
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

    void display() const {
        Node* current = head;
        bool firstTerm = true;
        while (current) {
            if (current->coefficient != 0) {
                if (!firstTerm) {
                    if (current->coefficient > 0) {
                        cout << " + ";
                    } else {
                        cout << " - ";
                    }
                }
                if (current->coefficient != 1 || current->power == 0) {
                    cout << abs(current->coefficient);
                }
                if (current->power != 0) {
                    cout << "x";
                    if (current->power != 1) {
                        cout << "^" << current->power;
                    }
                }
                firstTerm = false;
            }
            current = current->next;
        }
        cout << endl;
    }

    LinkedList add(const LinkedList& other) const {
        LinkedList result;
        Node* current1 = head;
        Node* current2 = other.head;
        while (current1 && current2) {
            if (current1->power > current2->power) {
                result.append(current1->coefficient, current1->power);
                current1 = current1->next;
            } else if (current2->power > current1->power) {
                result.append(current2->coefficient, current2->power);
                current2 = current2->next;
            } else {
                int coefficient = current1->coefficient + current2->coefficient;
                result.append(coefficient, current1->power);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        while (current1) {
            result.append(current1->coefficient, current1->power);
            current1 = current1->next;
        }
        while (current2) {
            result.append(current2->coefficient, current2->power);
            current2 = current2->next;
        }
        return result;
    }
};

int main() {
    LinkedList poly1;
    LinkedList poly2;

    cout << "Enter the number of terms in the first polynomial: ";
    int numTerms1;
    cin >> numTerms1;

    cout << "Enter the coefficients and powers of the first polynomial (e.g., 3 2 for 3x^2):" << endl;
    for (int i = 0; i < numTerms1; i++) {
        int coefficient, power;
        cin >> coefficient >> power;
        poly1.append(coefficient, power);
    }

    cout << "Enter the number of terms in the second polynomial: ";
    int numTerms2;
    cin >> numTerms2;

    cout << "Enter the coefficients and powers of the second polynomial (e.g., 3 2 for 3x^2):" << endl;
    for (int i = 0; i < numTerms2; i++) {
        int coefficient, power;
        cin >> coefficient >> power;
        poly2.append(coefficient, power);
    }

    LinkedList result = poly1.add(poly2);

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    cout << "Result: ";
    result.display();

    return 0;
}
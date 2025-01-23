#include <iostream>
using namespace std;

class Node{
    public:
        int coefficient;
        int power;
        Node* next;

        Node(int coefficient, int power){
            this->coefficient = coefficient;
            this->power = power;
            this->next = nullptr;
        }
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = nullptr;
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

        void append(int coefficient, int power){
            Node* newNode = new Node(coefficient, power);
            if (!head)
            {
                head = newNode;
                return;
            }
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }


            
            
        }
}

int main(){
    cout <<"Enter the number of terms in the first polynomial: ";
    int numTerms1;
    cin >> numTerms1;

    cout<<"Enter the coefficient and powers of the first polynomial (e.g., 3 2 for 3x^2):"<<endl;
    for (int i = 0; i < numTerms1; i++)
    {
        int coefficient, power;
        cin >> coefficient >> power;
        poly1.append(coefficient, power);
    }


    cout<<" Enter the number of terms in the second polynomial: ";
    int numTerms2;
    cin >> numTerms2;

    cout<<"Enter the coefficients and powers of the second polynomial(e.g., 3 2 for 3x^2): "<<endl;
    for (int i = 0; i < numTerms2; i++)
    {
        int coefficient, power;
        cin>>coefficient >> power;
        poly2.append(coefficient,power);
    }

    LinkedList result = poly1.add(poly2);

    cout<< "Polynomial 1: ";
    poly1.display();

    cout<<"Polynomial 2: ";
    poly2.display();

    cout<<"Result: ";
    result.display();

    return 0;
    
    
}
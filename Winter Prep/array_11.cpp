#include <iostream>
using namespace std;

int main() {
    
    int numbers[10];
    int searchNumber;

    
    cout << "Enter 10 numbers:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    
    cout << "Enter the number to search for: ";
    cin >> searchNumber;

    
    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (numbers[i] == searchNumber) {
            cout << "The number " << searchNumber << " is found at position " << i + 1 << "." << endl;
            found = true;
            break;
        }
    }

    
    if (!found) {
        cout << "The number " << searchNumber << " is not found in the array." << endl;
    }

    return 0;
}


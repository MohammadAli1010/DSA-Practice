#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10; 
    int numbers[SIZE]; 
    int frequency[SIZE]; 

    
    for (int i = 0; i < SIZE; i++) {
        frequency[i] = 0;
    }

    
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i]; 
    }

    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (numbers[i] == numbers[j]) {
                frequency[i]++;
            }
        }
    }

    
    for (int i = 0; i < SIZE; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            cout << "Number " << numbers[i] << " appears " << frequency[i] << " times." << endl;
        }
    }

    return 0;
}
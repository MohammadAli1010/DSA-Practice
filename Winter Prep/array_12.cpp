#include <iostream>
#include <limits> 
using namespace std;

int main() {
    const int SIZE = 10; 
    int numbers[SIZE]; 

    
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i]; 
    }

    
    int largest = std::numeric_limits<int>::min(); 
    int secondLargest = std::numeric_limits<int>::min(); 

    
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] > largest) {
            secondLargest = largest; 
            largest = numbers[i]; 
        } else if (numbers[i] > secondLargest && numbers[i] < largest) {
            secondLargest = numbers[i]; 
        }
    }

    
    if (secondLargest == std::numeric_limits<int>::min()) {
        cout << "There is no second largest number (all numbers might be the same)." << endl;
    } else {
        cout << "The second largest number is: " << secondLargest << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    const int size = 10;  // Size of the array
    int arr[size];        // Array to store 10 elements
    int sum = 0;          // Variable to store the sum of elements
    double mean;          // Variable to store the mean

    // Input: Reading 10 elements into the array
    cout << "Enter 10 elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
        sum += arr[i];  // Adding each element to the sum
    }

    // Calculating the mean
    mean = static_cast<double>(sum) / size;

    // Output: Displaying the mean
    cout << "The mean of the elements is: " << mean << endl;

    return 0;
}
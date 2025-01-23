#include <iostream>
using namespace std;


void find_values(int arr1[], int arr2[], int m, int n) {
    
    int common_values[100];
    int common_index = 0;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            common_values[common_index] = arr1[i];
            common_index++;
        }
    }

    
    int unique_to_arr1[100];
    int unique_index1 = 0;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique_to_arr1[unique_index1] = arr1[i];
            unique_index1++;
        }
    }

    
    int unique_to_arr2[100];
    int unique_index2 = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique_to_arr2[unique_index2] = arr2[i];
            unique_index2++;
        }
    }

    
    cout << "Values present in both arrays: ";
    for (int i = 0; i < common_index; i++) {
        cout << common_values[i] << " ";
    }
    cout <<endl;

    cout << "Values present in the first array but not in the second array: ";
    for (int i = 0; i < unique_index1; i++) {
        cout << unique_to_arr1[i] << " ";
    }
    cout <<endl;

    cout << "Values present in the second array but not in the first array: ";
    for (int i = 0; i < unique_index2; i++) {
        cout << unique_to_arr2[i] << " ";
    }
    cout <<endl;
}

int main() {
    int m = 5;
    int n = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};

    find_values(arr1, arr2, m, n);

    return 0;
}
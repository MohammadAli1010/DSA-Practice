#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == key)
            return mid;

        
        if (arr[mid] < key)
            low = mid + 1;

        
        else
            high = mid - 1;
    }

    
    return -1;
}

int main(void)
{
    int n;
    cout<<"Which element you want to find"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, n);
    if(result == -1){
        cout << "Element is not present in array";
    } 
    
    else{
        cout << "Element is present at index " << result;
    } 
    return 0;
}
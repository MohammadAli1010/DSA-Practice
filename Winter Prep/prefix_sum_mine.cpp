#include<iostream>
using namespace std;

void prefixSum(int arr[], int n)
{
    int prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    cout<<"Prefix Sum: ";
    for (int i = 0; i < n; i++)
    {
        cout<<prefix[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }

    prefixSum(arr, n);

    return 0;
    
}
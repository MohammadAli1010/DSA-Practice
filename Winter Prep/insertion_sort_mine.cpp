#include <iostream>
using namespace std;

void ins(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key; 
        
    }
    
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the element"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Sorted Array: "<<endl;
    ins(arr,n);
    printArray(arr, n);
    


}


#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;

    int arr[size];

    cout<<"Enter the elements: "<<endl;
    
    
    
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }


    int start = 0;
    int end;
    end = size - 1;

    while (start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    };
    cout<<"The reverse of the array is: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    






 return 0;
}
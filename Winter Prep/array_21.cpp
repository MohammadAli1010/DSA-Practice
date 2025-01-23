#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    int num;
    cout<<"Enter the number"<<endl;
    cin>>num;
    for (int i = 0; i < 10; i++)
    {
        arr[i]= arr[i] + num;

    }
    cout<<"Array after adding the number becomes"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    int k;
    int num;
    cout<<"Enter the posi"<<endl;
    cin>>k;
    cout<<"Enter the number"<<endl;
    cin>>num;
    for (int i = 10; i >=k; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[k-1] = num;
    cout<<"The updated array becomees"<<endl;
    for (int i = 0; i < 11; i++)
    {
        cout<<arr[i]<<" ";
    }
}
#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int k;
    int num;
    cin>>k;
    cin>>num;
    for (int i = 10; i >=k ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[k-1] = num;
    cout<<"The updated array becomes"<<endl;
    for (int i = 0; i < 11; i++)
    {
        cout<<arr[i]<<" ";
    }
}
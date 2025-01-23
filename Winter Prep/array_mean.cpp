#include <iostream>
using namespace std;

int main ()
{
    int i;
    int arr[10];
    int n = sizeof(arr)/sizeof(arr[0]);
    for ( i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    double sum = 0;
    for ( i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    double mean = sum/n;
    cout<<"Mean of the array is: "<<mean<<endl;
    
    
    
    
}
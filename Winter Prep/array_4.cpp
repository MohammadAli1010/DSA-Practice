#include <iostream>
using namespace std;
int main (){
    int i;
    int arr[10];
    int x;
    for (i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    for (i = 0; i < 10; i++)
    {
        if (x = arr[i]%2 !=0)
        {
            cout<<arr[i]<<endl;
        }
        
    }
    if (!x) 
    {
        cout<<"Nothing to display";
    }
    
    
    
}
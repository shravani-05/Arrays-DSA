#include<iostream>
using namespace std;

int main(){
    int arr[5] = { 3,5,6,7,1};
    int length = sizeof(arr)/ sizeof(arr[0]);
      cout<<"Traversed array is: ";
    for (int i = 0; i < length; i++)
    {
      
        cout<<arr[i] << " ";
    }
    
}
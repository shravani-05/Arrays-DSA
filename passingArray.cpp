#include<iostream>
using namespace std;

void passingArrayByPointer(int *ptr , int n)//this means that this pointer is
//passing at the starting pointer of the array ay index 1.
{
    cout<<"The array arguments are: ";
    for (int i = 0; i < n; i++)
    {
        cout<< ptr[i]<<" ";
    }
    cout<<endl;
}

void passingArrayBySize(int arr[5],int n){
    cout<<"The array arguments are: ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void passingArrayByUnSize(int arr[] ,int n){
    cout<<"The array arguments are: ";

    for (int i = 0; i < n; i++)
    {
        cout<< *(arr + i)<<" ";
    }
    cout<<endl;

}
int main(){
    int arr[5] = { 3,5,6,7,1};
   
   passingArrayByPointer(arr , 5);
   passingArrayBySize(arr , 5);
   passingArrayByUnSize(arr , 5);
}
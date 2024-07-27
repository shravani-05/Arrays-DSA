#include<iostream>
using namespace std;

int main(){
   int arr[10],n,i;
   cout<<"Enter the size of the array: ";//taking size of the arr from the 
   cin>>n;
   cout<<"Enter the elements in the array: ";
   for(i=0;i<n;i++){
        cin>> arr[i];
    }

   int x;
   cout<<"Enter the element that should be added in the end: ";
   cin>>x;
  
    arr[i] = x;
    n++;

    cout<<"The elements in the array are: ";
     for(i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
}


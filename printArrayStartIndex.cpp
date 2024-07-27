#include<iostream>
using namespace std;

int main(){
   int arr[7],n,i;
   cout<<"Enter the size of the array: ";//taking size of the array from the user 
   cin>>n;//storing it in the variable
   cout<<"Enter the elements in the array: ";//taking elements from user
   for(i=0;i<n;i++){
        cin>> arr[i];//storing them into an array 
   }
    //insertion of the element code
    int x;//element to be inserted
    cout<<"Enter the element that should be added in the beginning: ";
    cin>>x;//storing the value in a temp variable
    for(i=n;i>0;i--){//when size of i should be equal to n;
    //the indices should be form 1 to 4 as element is to be inserted at the beginning;
    //and keep on decrementing the value
    arr[i] = arr[i-1];//a[5]= a[4] and so onn
    }
    arr[0] = x;//insert the value at arr[0]
    n++;//increment the size of the arrat
    //returning the array after inserting the value
    cout<<"The elements in the array are: ";
     for(i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
}


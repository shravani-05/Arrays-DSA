#include<iostream>
using namespace std;
void solve(int arr[], int length){
    int temp = arr[0];
    for(int i; i<length-1 ; i++){
        arr[i] = arr[i+1];
    }
    arr[length-1]=temp;
    for (int i = 0; i < length; i++)
    {      
        cout<<arr[i] << " ";
    }
}
int main(){
    int arr[5] = { 3,5,6,7,1};
    int length = 5;
    cout<<"\nArray after rotating by 1: ";
    solve(arr,length);
    
}
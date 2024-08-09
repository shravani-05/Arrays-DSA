#include<iostream>
using namespace std;
void moveZeros(int arr[] , int n){
    int j =-1;
    for(int i = 0; i<n ;i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    for(int i = j+1; i< n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    int arr[7] = { 3,0,5,6,0,7,1};
    int n = 7;
    cout<<"Updated array is: ";
    moveZeros(arr,n);
    for (int i = 0; i < n; i++)
    {
      
        cout<<arr[i] << " ";
    }
    
}
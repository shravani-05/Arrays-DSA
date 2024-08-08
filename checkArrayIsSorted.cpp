#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[] ,int n){

    for(int i =1;i<n;i++){
        for(int j = i +1; j < n; j++){
            arr[j]<arr[i];
            return true;
        }
    }
    return false;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 5;

    bool ans =  isSorted(arr,n);

    if(ans == true){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        arr[i]>arr[i-1];
        return true;
    }
    return false;
    
}
int main(){
    int arr[5] = {2,4,5,6,7};
    int n;

    bool ans = isSorted(arr,n);

    cout<<ans;    
}


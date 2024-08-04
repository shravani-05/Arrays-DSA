#include<bits/stdc++.h>
using namespace std;

void merge(long long nums1[], long long nums2[], int n, int m) {
        int left = n - 1;
        int right = 0;
        //In this loop left will go towards 0 and right will go towards m
        while(left >= 0 && right < m){
            if(nums1[left] >= nums2[right]){
                swap(nums1[left],nums2[right]);
                left--,right++;
            }
            else{
                break;
            }

        }

        sort(nums1 , nums1 + n);
        sort(nums2 , nums2 + m);
    }  

int main(){
    long long nums1[] = {1,4,8,10};
    long long nums2[] = {2,3,9};
    int n = 4, m = 3;
    merge(nums1, nums2 , n ,m);
    cout<<"The merged arrays are : nums1[] =  ";
    for(int i = 0; i< n;i++){
        cout << nums1[i] <<" ";
    }
    cout << "\narr2[] = ";
    for(int i = 0; i< m;i++){
        cout << nums2[i] <<" ";
    }
    cout<< endl;

    return 0;
}
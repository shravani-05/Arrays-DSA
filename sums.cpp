#include<bits/stdc++.h>
using namespace std;
bool isSubset(vector<int>& nums ,int n, int target){
    //base cases
    if(target == 0) return true;
    if(n ==0 && target!=0) return false;

    // Check if the sum can be obtained by including or excluding the last element
    return isSubset(nums, n - 1, target) ||
           isSubset(nums, n - 1, target - nums[n - 1]);

}
int main(){
    vector<int> nums = {2,5,9,1,4};
    int target = 9;
    int n = nums.size();

    if(isSubset(nums,n,target)){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    
    return 0;
}
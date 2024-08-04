#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (int i = 0; i < k; ++i) {
        maxHeap.push(nums[i]);
    }

    for (int i = k; i < nums.size(); ++i) {
        if (nums[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(nums[i]);
        }
    }
    return maxHeap.top();
}
int kthlargestElement(vector<int> &nums, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < k; i++){
        minHeap.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++){
        if(nums[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
    
}
int main(){
    vector <int> nums = {1,4,5,7,8,3};//1,3,4,5,7,8
    int k=2;
    cout<< "The " << k << "-th Largest element is "<< kthlargestElement(nums,k) <<endl;
    // int kthSmallest = findKthSmallest(nums, k);
    cout << "The " << k << "-th smallest element is " << findKthSmallest << endl;

}
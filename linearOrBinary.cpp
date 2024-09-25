#include <iostream>
using namespace std;

// Recursive Linear Search
int recursiveLinearSearch(int arr[], int size, int target, int index, int &comparisons) {
    if (index >= size) {
        return -1;  
    }
    
    comparisons++;
    if (arr[index] == target) {
        return index;
    }

    return recursiveLinearSearch(arr, size, target, index + 1, comparisons);
}

int recursiveBinarySearch(int arr[],int low, int high,int target, int &comparions){
    if(low>high){
        return -1;
    }

    comparions++;
    int mid = low +(high -low)/2;

    if(mid == target){
        return mid;
    }
    else if(mid > target){//10 20 30 40 50 60 70 
        return recursiveBinarySearch(arr,mid-1,high,target,comparions);
    }
    else{
        return recursiveBinarySearch(arr,mid+1,high,target,comparions);
    }


}
int main() {
    int size, target, option;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements (sorted for binary search): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element: ";
    cin >> target;

    cout << "Choose search method: \n1. Recursive Linear Search\n2. Recursive Binary Search\n";
    cin >> option;

    int comparisons = 0;
    int result;

    if (option == 1) {
        result = recursiveLinearSearch(arr, size, target, 0, comparisons);
    } 
    else if (option == 2) {
        result = recursiveBinarySearch(arr, 0, size - 1, target, comparisons);
    } else {
        cout << "Invalid option selected." << endl;
        return 1;
    }

    if (result != -1) {
        cout << "Element found at index " << result << " with " << comparisons << " comparisons." << endl;
    } else {
        cout << "Element not found after " << comparisons << " comparisons." << endl;
    }

    return 0;
}



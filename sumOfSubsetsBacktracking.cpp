#include <iostream>
#include <vector>
using namespace std;

// Recursive function to determine if there is a subset that sums to the target
bool isSubsetSum(const vector<int>& set, int n, int targetSum) {
    // Base cases
    if (targetSum == 0) return true;  // Found a subset with the desired sum
    if (n == 0 && targetSum != 0) return false;  // No elements left, but target is not reached

    // If the last element is greater than the sum, ignore it
    if (set[n - 1] > targetSum) {
        return isSubsetSum(set, n - 1, targetSum);
    }

    // Check if the sum can be obtained by including or excluding the last element
    return isSubsetSum(set, n - 1, targetSum) ||
           isSubsetSum(set, n - 1, targetSum - set[n - 1]);
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    int n = set.size();

    if (isSubsetSum(set, n, targetSum)) {
        cout << "A subset with the given sum exists" << endl;
    } else {
        cout << "No subset with the given sum exists" << endl;
    }

    return 0;
}

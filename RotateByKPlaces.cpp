#include <iostream>
using namespace std;

void solve(int arr[], int length, int d) {
    // Create a temporary array to store the first 'd' elements
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Shift the remaining elements to the left by 'd' positions
    for (int i = 0; i < length - d; i++) {
        arr[i] = arr[i + d];
    }

    // Move the elements from the temporary array to the end of the original array
    for (int i = 0; i < d; i++) {
        arr[length - d + i] = temp[i];
    }

    // Print the array after rotation
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {3, 5, 6, 7, 1, 9};
    int length = 6;
    int d = 3;

    cout << "Array after rotating d = " << d << " places: ";
    solve(arr, length, d);

    return 0;
}

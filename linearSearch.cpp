#include<iostream>
using namespace std;

void search(int arr[], int n, int value) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Value " << value << " found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Value " << value << " not found in the array." << endl;
    }
}

int main() {
    int arr[5] = {3, 5, 6, 7, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int value = 5; 
    search(arr, length, value);
    cout << "Array elements: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

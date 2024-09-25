#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MobilePhone {
    string model;
    int ram;
    int storage;
    double price;
};

void merge(vector<MobilePhone>& phones, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<MobilePhone> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = phones[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = phones[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].ram <= R[j].ram) {
            phones[k] = L[i];
            i++;
        } else {
            phones[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        phones[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        phones[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<MobilePhone>& phones, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(phones, left, mid);
        mergeSort(phones, mid + 1, right);

        merge(phones, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of mobile phones: ";
    cin >> n;

    vector<MobilePhone> phones(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter details for mobile phone " << i + 1 << ":\n";
        cout << "Model: ";
        cin >> phones[i].model;
        cout << "RAM (in GB): ";
        cin >> phones[i].ram;
        cout << "Storage (in GB): ";
        cin >> phones[i].storage;
        cout << "Price (in USD): ";
        cin >> phones[i].price;
    }

    mergeSort(phones, 0, n - 1);

    cout << "\nMobile phones sorted by RAM capacity:\n";
    for (int i = 0; i < n; i++) {
        cout << "Model: " << phones[i].model 
             << ", RAM: " << phones[i].ram << " GB"
             << ", Storage: " << phones[i].storage << " GB"
             << ", Price: $" << phones[i].price << endl;
    }

    return 0;
}

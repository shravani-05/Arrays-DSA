#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;      // Job ID
    int deadline; // Job deadline
    int profit;   // Job profit
};

// Define the compare function above jobSequencing
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs) {
    // Step 1: Sort the jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();

    // Step 2: Initialize an array to track available slots
    vector<int> slot(n, -1); // -1 indicates the slot is free

    // Step 3: Place jobs in the latest possible available slot
    vector<char> jobSequence(n, '-');

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job, start from the last possible slot
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) { // If the slot is free
                slot[j] = i;     // Place this job in the slot
                jobSequence[j] = jobs[i].id;
                break;
            }
        }
    }

    // Step 4: Print the result
    cout << "Job sequence to maximize profit: ";
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (jobSequence[i] != '-') {
            cout << jobSequence[i] << " ";
            totalProfit += jobs[slot[i]].profit;
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};

    jobSequencing(jobs);

    return 0;
}

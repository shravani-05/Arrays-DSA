#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

// A utility function to find the smallest color
int findSmallestAvailableColor(const vector<int>& colors, const vector<bool>& availableColors, int V) {
    for (int color = 0; color < V; color++) {
        if (availableColors[color] == true) {
            return color;
        }
    }
    return -1;
}

void graphColoring(const vector<list<int>>& adj, int V) {
    // Initialize all vertices as uncolored
    vector<int> result(V, -1); // result[i] will store the color of vertex i

    // Assign the first color to the first vertex
    result[0] = 0;

    // A temporary array to store the available colors. False value of available[color]
    // would mean that the color color is assigned to one of its adjacent vertices
    vector<bool> availableColors(V, true);

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Process all adjacent vertices and mark their colors as unavailable
        for (auto i : adj[u]) {
            if (result[i] != -1) { // If the adjacent vertex is colored
                availableColors[result[i]] = false; // Mark that color as unavailable
            }
        }

        // Find the first available color
        int color = findSmallestAvailableColor(result, availableColors, V);

        // Assign the found color
        result[u] = color;

        // Reset the values back to true for the next iteration
        fill(availableColors.begin(), availableColors.end(), true);
    }

    // Print the result
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

int main() {
    int V = 5;
    vector<list<int>> adj(V);

    // Add edges
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[4].push_back(2);

    graphColoring(adj, V);

    return 0;
}

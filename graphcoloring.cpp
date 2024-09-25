#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c) {  // Check adjacency and color
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color c to vertex v

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(const vector<vector<int>>& graph, int m) {    vector<int> color(graph.size(), 0);

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    cout << "Solution Exists: Following are the assigned colors:" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }
    return true;
}

int main() {
    int V = 4;

    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;  
    graphColoring(graph, m);

    return 0;
}

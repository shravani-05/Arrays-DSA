#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1, N))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0, N)) {
        printBoard(board, N);
    } else {
        cout << "Solution does not exist for " << N << " queens." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N (number of queens): ";
    cin >> N;

    solveNQueens(N);

    return 0;
}

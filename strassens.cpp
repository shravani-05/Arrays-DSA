#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add two matrices
Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
Matrix subtract(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Matrix Multiplication function
Matrix strassenMultiply(Matrix A, Matrix B) {
    int n = A.size();
    
    // Base case when matrix size is 1x1
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Dividing the matrices into submatrices
    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's formula
    Matrix M1 = strassenMultiply(add(A11, A22), add(B11, B22));   // M1 = (A11 + A22)(B11 + B22)
    Matrix M2 = strassenMultiply(add(A21, A22), B11);             // M2 = (A21 + A22)B11
    Matrix M3 = strassenMultiply(A11, subtract(B12, B22));        // M3 = A11(B12 - B22)
    Matrix M4 = strassenMultiply(A22, subtract(B21, B11));        // M4 = A22(B21 - B11)
    Matrix M5 = strassenMultiply(add(A11, A12), B22);             // M5 = (A11 + A12)B22
    Matrix M6 = strassenMultiply(subtract(A21, A11), add(B11, B12)); // M6 = (A21 - A11)(B11 + B12)
    Matrix M7 = strassenMultiply(subtract(A12, A22), add(B21, B22)); // M7 = (A12 - A22)(B21 + B22)

    // Calculating C submatrices
    Matrix C11 = add(subtract(add(M1, M4), M5), M7); // C11 = M1 + M4 - M5 + M7
    Matrix C12 = add(M3, M5);                        // C12 = M3 + M5
    Matrix C21 = add(M2, M4);                        // C21 = M2 + M4
    Matrix C22 = add(subtract(add(M1, M3), M2), M6); // C22 = M1 + M3 - M2 + M6

    // Combining submatrices into one
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

void printMatrix(Matrix M) {
    int n = M.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (power of 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    Matrix C = strassenMultiply(A, B);

    cout << "Resultant matrix C:\n";
    printMatrix(C);

    return 0;
}

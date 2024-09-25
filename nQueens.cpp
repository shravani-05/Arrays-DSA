#include<bits/stdc++.h>
using namespace std;
isSafeBoard()
int solveNQueensUtil(vector<vector<int>> board, int row,int n){
    if(row>=n){
        return true;
    }
    for(int col = 0;col<n;col++){
        if(isSafeBoard(board,row,col,n)){
            board[row][col] = 1;
        }
    }
}
int printBoard(vector<vector<int>> board, int n){

}
int nQueens(int n){
    vector<vector<int>> board(n, vector<int>(n,0));

    if(solveNQueensUtil(board, 0 ,n)){
        printBoard(board, n);
    }
    else{
        cout<<"Solution does not exist for"<<n<<"queens.";
    }
}
int main(){
    int n;
    cout<<"Enter the values of N queens: ";
    cin>>n;
    nQueens(n);
    return 0;
}
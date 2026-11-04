#include <bits/stdc++.h>
using namespace std;

int N;

class NQueen{
    int n;
    int r,c;
    vector<vector<int>> board;

    public :

    NQueen(int size,int row,int col){
        n = size;
        r = row;
        c = col;
        board.resize(n,vector<int>(n,0));
        board[r][c] = 1;
    }


    bool isSafe(int row,int col){


    for(int i=0;i<row;i++){
        if(board[i][col] == 1) return false;
    }


    // upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 1) return false;
    }

    // upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++){
        if(board[i][j] == 1) return false;
    }

    return true;
}

bool solve(int row){
    if(row == N) return true;

    for(int col=0;col<N;col++){
        if(isSafe(row,col) == true){
            board[row][col] = 1;
            if(solve(row+1)) return true;
            board[row][col] = 0;
        }
    }

    return false;

}

    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }

};

int main(){
    cout<<"Enter the value of N :";
    cin>>N;

    vector<vector<int>> board(N,vector<int>(N,0));

    int r,c;

    cout << "Enter first queen position (row col): ";
    cin >> r >> c;

    if(r < 0 || r >= N || c < 0 || c >= N) {
        cout << "Invalid position";
        return 0;
    }
    
    NQueen q(N,r,c);

    if(q.solve(0)){
        cout << "\nSolution Exists:\n";
        q.display();
    }
      else {
        cout << "\nNo Solution Exists";
    }
}
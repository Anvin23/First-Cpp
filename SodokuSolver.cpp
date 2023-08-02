#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    for(int i=0;i<9;i++) {
        if(board[row][i] == num)
        {
            return false;
        }
        if(board[i][col] == num)
        {
            return false;
        }
    }

    int Rstart = row - (row%3);
    int Cstart = col - (col%3);

    for(int r=Rstart;r<Rstart+3;r++)
    {
        for(int c=Cstart;c<Cstart+3;c++)
        {
            if(board[r][c] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    int row=-1;
    int col=-1;
    bool filled=true;
    for(int i=0;i<board.size();i++) {
        for (int j = 0; j<9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                filled = false;
                break;
            }
        }
        if (!filled) {
            break;
        }
    }
        if(filled) {
            return true;
            // sudoku solved
        }
        for(int number=1;number<=9;number++) {
            if(isSafe(board,row,col,number)) {
                board[row][col]=number;
                if(solve(board)) {
                    return  true;
                }
                else {
                    // backtrack
                    board[row][col]=0;
                }
            }
        }
    return false;
}

void display(vector<vector<int>>& board) {
    for(int p=0;p<9;p++)
        {
            for(int q=0;q<9;q++)
            {
                cout<<board[p][q]<<" ";
                if(q==2 || q==5)
                {
                    cout<<"  ";
                }
                if((p==2 || p==5) && q==8)
                {
                    cout<<endl;
                }
            }
            cout<<endl;
        }
}

int main() {
    vector<vector<int>> board = {
        {0,9,1,0,0,8,0,3,0},
        {0,0,8,0,0,9,2,0,6},
        {0,0,0,0,0,4,9,8,1},
        {0,8,0,9,0,5,4,6,7},
        {0,1,0,0,0,2,0,0,0},
        {0,7,9,0,0,0,1,2,0},
        {0,0,0,0,4,0,0,0,0},
        {0,0,7,2,0,0,6,0,9},
        {0,6,0,0,0,1,0,0,0}
    };

    if(solve(board)) {
        cout<<endl;
        display(board);
        cout<<endl;
    }
    else {
        cout<<"Couldn't Solve"<<endl;
    }

    return 0;
}
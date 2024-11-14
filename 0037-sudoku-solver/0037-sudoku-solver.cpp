class Solution {
public:
    bool solve(vector<vector<char>> &board, vector<vector<char>> &currBoard, int row, int col) {
        if(row>=9 && col==0) {
            board = currBoard;
            return true;
        }
        bool stop = false;
        if(board[row][col]!='.'){
            if(col<8) {
                stop = solve(board, currBoard, row, col+1) || false;
            }
            else {
                stop = solve(board, currBoard, row+1, 0) || false;
            }
        }
        else {
            for(char c='1'; c<='9'; c++) {
                int currGStartRow = (row/3)*3;
                int currGStartCol = (col/3)*3;
                bool invalid = false;
                for(int i=currGStartRow; i<currGStartRow+3; i++) {
                    for(int j=currGStartCol; j<currGStartCol+3; j++) {
                        if(currBoard[i][j]!='.' && currBoard[i][j]==c) {
                            invalid = true;
                            break;
                        }
                    }
                    if(invalid) {
                        break;
                    }
                }
                if(invalid==false) {
                    for(int i=0; i<9; i++) {
                        if((currBoard[row][i]!='.' && currBoard[row][i]==c) || (currBoard[i][col]!='.' && currBoard[i][col]==c)) {
                            invalid=true;
                            break;
                        }
                    }
                }
                if(!invalid) {
                    currBoard[row][col] = c;
                    if(col<8) {
                        stop = solve(board, currBoard, row, col+1) || false;
                    }
                    else {
                        stop = solve(board, currBoard, row+1, 0) || false;
                    }
                    if(stop) {
                        return stop;
                    }
                    currBoard[row][col] = '.';
                    
                }
            }
        }
        return stop;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> currBoard{board};
        solve(board, currBoard, 0, 0);
    }
};
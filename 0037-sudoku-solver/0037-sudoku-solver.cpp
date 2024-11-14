class Solution {
public:
    void solve(vector<vector<char>> &board, int row, int col) {
        if (row == 9) return;  // Completed board
        if (board[row][col] != '.') {
            // Move to the next cell
            if (col < 8) solve(board, row, col + 1);
            else solve(board, row + 1, 0);
            return;
        }

        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                // Move to the next cell
                if (col < 8) solve(board, row, col + 1);
                else solve(board, row + 1, 0);

                // Stop if the board is fully filled (solution found)
                if (isSolved(board)) return;
                
                board[row][col] = '.';  // Backtrack
            }
        }
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        int gridRow = (row / 3) * 3;
        int gridCol = (col / 3) * 3;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c || board[i][col] == c || 
                board[gridRow + i / 3][gridCol + i % 3] == c) return false;
        }
        return true;
    }

    bool isSolved(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
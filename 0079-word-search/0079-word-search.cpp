class Solution {
public:
    void solve(int row, int col, vector<vector<char>> &board, string &word, int current, vector<vector<bool>> &visited, bool &result) {
        if(current!=0 && current>=word.length()-1) {
            result = true;
            return;
        }
        if(row==board.size()) {
            return;
        }
        if(current==0) {
            if(board[row][col]==word[0]) {
                if(word.length()==1) {
                    result = true;
                    return;
                }
                if(col-1>=0 && !visited[row][col-1] && board[row][col-1]==word[current+1] ) {
                    visited[row][col] = true;
                    solve(row, col-1, board, word, current+1, visited, result);
                    visited[row][col] = false;
                }
                if(col+1<board[0].size() && !visited[row][col+1] && board[row][col+1]==word[current+1]) {
                    visited[row][col] = true;
                    solve(row, col+1, board, word, current+1, visited, result);
                    visited[row][col] = false;
                }
                if(row-1>=0 && !visited[row-1][col] && board[row-1][col]==word[current+1]) {
                    visited[row][col] = true;
                    solve(row-1, col, board, word, current+1, visited, result);
                    visited[row][col] = false;
                }
                if(row+1<board.size() && !visited[row+1][col] && board[row+1][col]==word[current+1]) {
                    visited[row][col] = true;
                    solve(row+1, col, board, word, current+1, visited, result);
                    visited[row][col] = false;
                }
            }
            if(result) {
                return;
            }
            if(col<board[0].size()-1) {
                solve(row, col+1, board, word, current, visited, result);
            }
            else {
                solve(row+1, 0, board, word, current, visited, result);
            }
        }
        else {
            if(col-1>=0 && !visited[row][col-1] && board[row][col-1]==word[current+1] ) {
                visited[row][col] = true;
                solve(row, col-1, board, word, current+1, visited, result);
                visited[row][col] = false;
            }
            if(col+1<board[0].size() && !visited[row][col+1] && board[row][col+1]==word[current+1]) {
                visited[row][col] = true;
                solve(row, col+1, board, word, current+1, visited, result);
                visited[row][col] = false;
            }
            if(row-1>=0 && !visited[row-1][col] && board[row-1][col]==word[current+1]) {
                visited[row][col] = true;
                solve(row-1, col, board, word, current+1, visited, result);
                visited[row][col] = false;
            }
            if(row+1<board.size() && !visited[row+1][col] && board[row+1][col]==word[current+1]) {
                visited[row][col] = true;
                solve(row+1, col, board, word, current+1, visited, result);
                visited[row][col] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        solve(0, 0, board, word, 0, visited, result);
        return result;
    }
};
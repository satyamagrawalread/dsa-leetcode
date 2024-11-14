class Solution {
public:
    void solve(int n, int row, int col, int count, vector<string> &current, vector<vector<string>> &result) {
        if(row>=n) {
            if(count==n) {
                result.push_back(current);
            }
            return;
        }
        for(int i=col; i<n; i++) {
            if(isValid(current, row, i, n)) {
                current[row][i] = 'Q';
                solve(n, row+1, 0, count+1, current, result);
                current[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string> & current, int row, int col, int n) {
        for(int i=0; i<n; i++) {
            if(current[row][i]=='Q' || current[i][col]=='Q') {
                return false;
            }
        }
        int currRow = row;
        int currCol = col;
        while(currRow>=0 && currCol>=0) {
            if(current[currRow][currCol]=='Q') return false;
            currRow--;
            currCol--;
        }
        currRow = row;
        currCol = col;
        while(currRow<n && currCol<n) {
            if(current[currRow][currCol]=='Q') return false;
            currRow++;
            currCol++;
        }
        currRow = row;
        currCol = col;
        while(currRow<n && currCol>=0) {
            if(current[currRow][currCol]=='Q') return false;
            currRow++;
            currCol--;
        }
        currRow = row;
        currCol = col;
        while(currRow>=0 && currCol<n) {
            if(current[currRow][currCol]=='Q') return false;
            currRow--;
            currCol++;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> current(n, string(n, '.'));
        solve(n, 0, 0, 0, current, result);
        return result;
    }
};
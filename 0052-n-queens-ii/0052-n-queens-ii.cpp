class Solution {
public:
    void solve(int n, int row, vector<bool> &cols, vector<bool> &mainDiag, vector<bool> &antiDiag, int &result) {
        if(row>=n) {
            result++;
            return;
        }
        for(int col=0; col<cols.size(); col++) {
            int mainDiagIndex = col - row + n -1;
            int antiDiagIndex = row + col;
            if(!cols[col] && !mainDiag[mainDiagIndex] && !antiDiag[antiDiagIndex]) {
                cols[col] = true;
                mainDiag[mainDiagIndex] = true;
                antiDiag[antiDiagIndex] = true;
                solve(n, row+1, cols, mainDiag, antiDiag, result);
                cols[col] = false;
                mainDiag[mainDiagIndex] = false;
                antiDiag[antiDiagIndex] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        int result = 0;
        vector<bool> cols(n, false);
        vector<bool> mainDiag(2*n-1, false);
        vector<bool> antiDiag(2*n-1, false);
        solve(n, 0, cols, mainDiag, antiDiag, result);
        return result;
    }
};
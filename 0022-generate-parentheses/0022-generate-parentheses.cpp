class Solution {
public:
    void solve(int n, int left, int right, string &current, vector<string> &result) {
        if(left>right) {
            return;
        }
        if(left==0 && right==0) {
            result.push_back(current);
            return;
        }
        if(left>0) {
            current+='(';
            solve(n, left-1, right, current, result);
            current.pop_back();
        }
        if(right>0) {
            current+=')';
            solve(n, left, right-1, current, result);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        solve(n, n, n, current, result);
        return result;
    }
};
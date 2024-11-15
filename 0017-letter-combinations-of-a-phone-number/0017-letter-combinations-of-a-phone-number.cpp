class Solution {
public:
    void solve(string &digits, string &currCombination, int currIndex, vector<string> &result) {
        if(digits.length()<=currIndex) {
            result.push_back(currCombination);
            return;
        }
        if(digits[currIndex]=='7') {
            for( int i=1; i<=4; i++) {
                currCombination+=((digits[currIndex]-50)*3+96+i);
                solve(digits, currCombination, currIndex+1, result);
                currCombination.pop_back();
            }
        }
        else if(digits[currIndex]=='8') {
            for(int i=1; i<=3; i++) {
                currCombination+=((digits[currIndex]-50)*3+96+i+1);
                solve(digits, currCombination, currIndex+1, result);
                currCombination.pop_back();
            }
        }
        else if(digits[currIndex]=='9') {
            for(int i=1; i<=4; i++){
                currCombination+=((digits[currIndex]-50)*3+96+i+1);
                solve(digits, currCombination, currIndex+1, result);
                currCombination.pop_back();
            }
        }
        else {
            for(int i=1; i<=3; i++) {
                currCombination+=((digits[currIndex]-50)*3+96+i);
                solve(digits, currCombination, currIndex+1, result);
                currCombination.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        if(digits.length()==0) {
            return result;
        }
        string currCombination;
        solve(digits, currCombination, 0, result);
        return result;
    }
};
class Solution {
public:
    void solve(vector<int> &candidates, int target, int index, vector<int> &current, int currSum, vector<vector<int>> &result) {
        if(currSum==target) {
            result.push_back(current);
            return;
        }
        if(index>=candidates.size() || currSum > target) {
            return;
        }
        int count = 0;
        while(currSum<target) {
            currSum+=candidates[index];
            current.push_back(candidates[index]);
            solve(candidates, target, index+1, current, currSum, result);
            count++;
        }
        while(count>0) {
            currSum-=candidates[index];
            current.pop_back();
            count--;
        }
        solve(candidates, target, index+1, current, currSum, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        solve(candidates, target, 0, current, 0, result);
        return result;
    }
};
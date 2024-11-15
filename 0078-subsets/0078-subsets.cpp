class Solution {
public:
    void solve(vector<int> &nums, int start, vector<int> current, vector<vector<int>> &result) {
        if(start==nums.size()) return;
        for(int i=start; i<nums.size(); i++) {
            current.push_back(nums[i]);
            result.push_back(current);
            solve(nums, i+1, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        vector<int> current;
        solve(nums, 0, current, result);
        return result;
    }
};
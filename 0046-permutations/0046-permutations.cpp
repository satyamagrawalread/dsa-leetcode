class Solution {
public:
    void solve(vector<int> &nums, int currIndex, vector<vector<int>> &result) {
        if(currIndex==nums.size()-1) {
            result.push_back(nums);
            return;
        }
        int temp;
        for(int i=currIndex; i<nums.size(); i++) {
           temp = nums[currIndex];
           nums[currIndex] = nums[i];
           nums[i] = temp;
            solve(nums, currIndex+1, result);
            temp = nums[i];
            nums[i] = nums[currIndex];
            nums[currIndex] = temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};
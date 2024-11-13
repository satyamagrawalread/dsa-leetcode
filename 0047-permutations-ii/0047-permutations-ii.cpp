class Solution {
public:
    void solve(vector<int> &nums, int currIndex, vector<vector<int>> &result) {
        if(currIndex==nums.size()-1) {
            result.push_back(nums);
            return;
        }
        int temp;
        map<int, int> mp;
        for(int i=currIndex; i<nums.size(); i++) {
            if(mp.count(nums[i]) > 0) {
                continue;
            }
            mp[nums[i]] = 1;
            temp = nums[currIndex];
            nums[currIndex] = nums[i];
            nums[i] = temp;
            solve(nums, currIndex+1, result);
            temp = nums[i];
            nums[i] = nums[currIndex];
            nums[currIndex] = temp;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};
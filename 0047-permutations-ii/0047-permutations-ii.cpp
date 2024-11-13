class Solution {
public:
    void solve(vector<int> &comb, map<int, int> &counter, int N, vector<vector<int>> &result) {
        if(comb.size() == N) {
            result.push_back(comb);
            return;
        }
        for (auto item : counter) {
            int num = item.first;
            int count = item.second;
            if(count==0) continue;
            comb.push_back(num);
            counter[num]--;
            solve(comb, counter, N, result);
            comb.pop_back();
            counter[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> counter;
        vector<int> comb;
        for(int num : nums) counter[num]++;
        solve(comb, counter, nums.size(), result);
        return result;
    }
};
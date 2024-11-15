class Solution {
public:
    void solve(map<int, int>::iterator currIt, map<int, int>::iterator endIt, vector<int> &current, vector<vector<int>> &result) {
        if(currIt==endIt) {
            return;
        }
        map<int, int>::iterator it;
        for(int i=0; i<currIt->second; i++) {
            current.push_back(currIt->first);
            result.push_back(current);
            it = currIt;
            solve(++it, endIt, current, result);
        }
        for(int i=0; i<currIt->second; i++) {
            current.pop_back();
        }
        it = currIt;
        solve(++it, endIt, current, result);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        vector<int> current;
        map<int, int> mp;
        for(auto i : nums) {
            if(mp.count(i) > 0) {
                mp[i]++;
            }
            else {
                mp[i] = 1;
            }
        }
        solve(mp.begin(), mp.end(), current, result);
        return result;
    }
};
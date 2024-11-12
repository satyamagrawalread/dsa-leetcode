class Solution {
public:
    void solve(vector<int> &uniqueCandidates, map<int, int> &mp, int target, int index, vector<int> &current, int currSum, vector<vector<int>> &result) {
        if(currSum==target) {
            result.push_back(current);
            return;
        }
        if(index>=uniqueCandidates.size() || currSum > target) {
            return;
        }
        int count = 0;
        while(currSum<target && count<mp[uniqueCandidates[index]]) {
            currSum+=uniqueCandidates[index];
            current.push_back(uniqueCandidates[index]);
            solve(uniqueCandidates, mp, target, index+1, current, currSum, result);
            count++;
        }
        while(count>0) {
            currSum-=uniqueCandidates[index];
            current.pop_back();
            count--;
        }
        solve(uniqueCandidates, mp, target, index+1, current, currSum, result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        map<int, int> mp;
        vector<int> uniqueCandidates;
        for(int i=0; i<candidates.size(); i++) {
            if(mp.count(candidates[i]) > 0) {
                mp[candidates[i]]+=1;
            }
            else {
                mp[candidates[i]] = 1;
                uniqueCandidates.push_back(candidates[i]);
            }
        }
        solve(uniqueCandidates, mp, target, 0, current, 0, result);
        return result;
    }
};
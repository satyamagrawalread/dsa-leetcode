class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && st.top()<nums2[i]){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size(); i++) {
            if(mp.find(nums1[i])==mp.end()) result.push_back(-1);
            else result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};
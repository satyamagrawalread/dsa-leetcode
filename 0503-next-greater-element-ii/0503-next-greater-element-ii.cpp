class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                result[st.top()] = nums[i];
                st.pop();
            }
            
            st.push(i);
        }
        int i=0;
        while(!st.empty() && i<nums.size()) {
            if(nums[st.top()]<nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            else {
                i++;
            }
        }
        return result;
    }
};
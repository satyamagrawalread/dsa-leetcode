class Solution {
public:
    bool isValid(vector<int>& piles, int h, int val) {
        int count = 0;
        for(int i=0; i<piles.size(); i++) {
            if(piles[i]%val == 0) {
                count += piles[i]/val;
            }
            else {
                count += piles[i]/val + 1;
            }
        }
        if(count <= h) {
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        long long sum = piles[0];
        int min = piles[0];
        for(int i=1; i<piles.size(); i++) {
            if(max < piles[i]) {
                max = piles[i];
            }
            if(min > piles[i]) {
                min = piles[i];
            }
            sum += piles[i];
        }
        int start = sum/(long)h;
        // int start = min;
        int end = max;
        while(start<end) {
            int mid = start + (end - start) / 2;
            if(mid > 0 && isValid(piles, h, mid)) {
                // cout<<mid<<endl;
                end = mid;
            }
            else {
                start = mid+1;
            }
        }
        return end;
    }
};
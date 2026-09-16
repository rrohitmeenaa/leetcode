// in this question i have to find the maxm length of the subarray which has atmost k 0's 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = nums.size();
        int maxlen = INT_MIN;
        for(int r = 0;r<n;r++){
            if(nums[r]==0){
                cnt++;
            }
                while(cnt>k){
                    if(nums[l]==0){
                        cnt--;
                    }
                    l++;
                }
            int len = r-l+1;
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};
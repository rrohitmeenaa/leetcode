// in this question we have to find the length of the longest subarray which is a good subarray 
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> mp;
        int maxi = 0;
        int len =0;
        while(l<=r && r<n){
            
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            
            len = r-l+1;
            maxi = max(maxi,len);
            r++;
        }
        return maxi;
    }
};
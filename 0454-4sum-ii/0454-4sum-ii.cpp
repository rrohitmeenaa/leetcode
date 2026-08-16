class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int sum1 = nums1[i] + nums2[j];
                mp[sum1]++;
            }
        }
        for(int k = 0;k<n;k++){
            for(int l = 0;l<n;l++){
                int sum2 = nums3[k]+nums4[l];
                int rem = 0 - sum2;
                if(mp.find(rem) != mp.end()){
                    ans+=mp[rem];
                }
            }
        }
        return ans;
    }
};
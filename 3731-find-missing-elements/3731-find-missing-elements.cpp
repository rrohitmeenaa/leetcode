class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans = {};
        sort(nums.begin(),nums.end());
        int k = 0;
        for(int i=1;i<nums.size();i++){
            k = 1;
            while(nums[i]!=nums[i-1]+k){
                ans.push_back(nums[i-1]+k);
                k++;
            }
        }
        return ans;
    }
};
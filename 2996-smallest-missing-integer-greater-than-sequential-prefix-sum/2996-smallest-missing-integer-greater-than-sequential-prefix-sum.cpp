class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixsum = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                prefixsum+=nums[i];
            }
            else{
                break;
            }
        }
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==prefixsum){
                prefixsum++;
            }
        }
        return prefixsum;
    }
};
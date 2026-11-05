// contiguous subarray whose lentgh is equal to k , fixed length sliding window .. maximum average value .. 

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = k-1;
        double sum = 0;

        for(int i = 0;i<=r;i++){
            sum+=nums[i];
        }
        double maxavg = INT_MIN;
        maxavg = max(maxavg,sum/k);
        r++;
        while(r<n){
            sum-=nums[l];
            sum+=nums[r];
            maxavg = max(maxavg,sum/k);
            l++;
            r++;
        }
        return maxavg;
    }
};
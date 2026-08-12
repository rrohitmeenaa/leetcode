class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int> ans;
        int res = 0;
        for(int i =0;i<n;i++){
            if(grumpy[i]==0){
                res+=customers[i];
            }
            ans.push_back(customers[i]*grumpy[i]);
        }
        int l = 0;
        int r = 0;
        int len = 0;
        int maxi = 0;
        int ma = 0;
        while(r<n){
            len = r-l+1;
            if(len>minutes){
                maxi -= ans[l];
                l++;
            }
            maxi += ans[r];
            ma = max(ma,maxi);
            r++;
        }
        return res+ma;
    }
};
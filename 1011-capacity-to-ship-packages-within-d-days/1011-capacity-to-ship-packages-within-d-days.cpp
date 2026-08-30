class Solution {
public:
    bool ispossible(vector<int>& weights,int days, int k){
        int x = 0;
        int n = weights.size();

        int cnt = 1;
        for(int i = 0;i<n;i++){
            if(x+weights[i]>k){
                cnt++;
                x = weights[i];
            }
            else{
                x+=weights[i];
            }
        }

        if(cnt>days){
            return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        // in this question i have to return the answer which is the minimum weight capacity . 
        // so this is a question of binary search on answers 
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }

        int l = *max_element(weights.begin(),weights.end());
        int h = sum;

        while(l<h){
            int mid = l + (h-l)/2;

            if(ispossible(weights,days,mid)){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l ;
    }
};
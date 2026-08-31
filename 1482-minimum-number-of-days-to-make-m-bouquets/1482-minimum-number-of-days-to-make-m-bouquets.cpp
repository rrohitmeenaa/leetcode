// in this question i have to return the minimum number of days . 
// so i have to apply binary search on answer and the answer is no. of days .
class Solution {
public:
    bool ispossible(int mid,vector<int>& bloomDay, int m, int k,bool xx){
        int n = bloomDay.size();
        int noofb = 0;
        int cntbloom = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cntbloom++;
                if(cntbloom==k){
                    noofb++;
                    cntbloom = 0;
                }
            }
            else{
                cntbloom = 0;
            }
        }

        if(noofb<m){
            xx = false;
            return false;
        }
        return true;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k>n){
            return -1;
        }
        int l = 1;
        int h = *max_element(bloomDay.begin(),bloomDay.end());
        bool xx = true;
        while(l<h){
            int mid = l + (h-l)/2;

            if(ispossible(mid,bloomDay,m,k,xx)){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(xx == false){
            return -1;
        }
        return l;
    }
};
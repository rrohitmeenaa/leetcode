class Solution {
public:
    bool ifpossible(int mid,vector<int>& piles,int h){
        long long x = 0;
        int n = piles.size();
        for(int i = 0;i<n;i++){
            x += (piles[i]+mid-1)/mid;
        }
        if(x>h){
            return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int hi = *max_element(piles.begin(),piles.end());
        while(l<hi){
            int mid = l + (hi-l)/2;

            if(ifpossible(mid,piles,h)){
                hi = mid;
                
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
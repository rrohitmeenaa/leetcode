// i have to find the maximum number of fruits that can fit in two baskets 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        unordered_map<int,int> mp;
        while(r<n){
                mp[fruits[r]]++;
                r++;
           
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;
                }
            
            int len = r-l;

            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        int maxi1 = 0;
        int maxi2 = 0;
        int smax1 = 0;
        int smax2 = 0;
        int ele1 = -1;
        int ele2 = -1;

        for(int i=0;i<n;i+=2){
            mp1[nums[i]]++;
        }

        for(int i =1;i<n;i+=2){
            mp2[nums[i]]++;
        }

        for(auto &[x,freq] : mp1){
            if(freq>maxi1){
                smax1 = maxi1 ;
                ele1 = x;
                maxi1 = freq;
            }
            else if(freq>smax1){
                smax1 = freq;
            }
        }

        for(auto &[x,freq] : mp2){
            if(freq>maxi2){
                smax2 = maxi2;
                ele2 = x;
                maxi2 = freq;
            }
            else if(freq>smax2){
                smax2 = freq;
            }
        }



        int rem = maxi1 + maxi2;
        if(ele1 == ele2){
            rem = max(maxi1+smax2,maxi2+smax1);
        }

        int res = n - rem;

        return res;
        
    }
};
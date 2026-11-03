class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        int maxi = arr[0];
        for(int i = 0;i<n;i++){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            count+= maxi-arr[i];
        }
        return count;
    }
};
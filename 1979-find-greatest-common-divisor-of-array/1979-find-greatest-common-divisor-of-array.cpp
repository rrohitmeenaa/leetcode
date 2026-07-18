class Solution {
public:
    int findGCD(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int a = arr[0];
        int b = arr[n-1];
        int gcd = 1;
        for(int i = 2;i<=b;i++){
            if(a%i==0 && b%i==0){
                gcd = i;
            }
        }
        return gcd;
    }
};
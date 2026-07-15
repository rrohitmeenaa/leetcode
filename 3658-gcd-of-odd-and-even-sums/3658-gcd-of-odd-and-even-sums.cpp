class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0;
        int odd = 1;
        int even = 2;
        int sumeven = 0;
        for(int i = 0;i<n;i++){
            sumodd+=odd;
            sumeven+=even;
            odd+=2;
            even+=2;
        }
        return gcd(sumodd,sumeven);
    }
};
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;

        int l = 0;
        int r = 0;
        int len = 0;
        int maxi = 0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }

            len = r - l + 1;
            maxi = max(maxi,len);
            r++;


        }
        return maxi ;
    }
};
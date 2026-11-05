class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int ansmax = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ans++;
            }
        }
        ansmax = ans;
        for(int r = k;r<n;r++){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                ans++;
            }
            if(s[r-k]=='a' || s[r-k]=='e' || s[r-k]=='i' || s[r-k]=='o' || s[r-k]=='u'){
                ans--;
            }
            ansmax = max(ansmax,ans);
        }
        return ansmax;
    }
};
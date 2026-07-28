class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string demo = "";
        for(int i=0;i<n/2;i++){
            demo+=s[i];
        }
        string ans = "";
        sort(demo.begin(),demo.end());
        if(n%2==0){
            ans+=demo;
            reverse(demo.begin(), demo.end());
            ans+=demo;
        }
        if(n%2!=0){
            ans+=demo;
            ans+=s[n/2];
            reverse(demo.begin(), demo.end());
            ans+=demo;
        }
        return ans;
    }
};
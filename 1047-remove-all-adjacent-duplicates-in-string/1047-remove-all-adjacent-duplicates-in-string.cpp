class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n=s.length();
        for(int i = 0;i<n;i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            char t = st.top();
            ans+=t;
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
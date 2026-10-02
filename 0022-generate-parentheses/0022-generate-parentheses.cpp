class Solution {
public:
    vector<string> result;
    bool isvalid(string& curr){
        stack<char> st;
        for(int i =0;i<curr.length();i++){
            if(curr[i]=='('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    void solve(string& curr,int n,int open,int close){
        
        if(curr.length()==2*n){
            if(isvalid(curr)){
                result.push_back(curr);
            }
            return ;
        }
        if(open<n){
            open++;
        curr.push_back('(');
        solve(curr,n,open,close);
        open--;
        curr.pop_back();
        }
        
        if(close<n && open>close){
        close++;
        curr.push_back(')');
        solve(curr,n,open,close);
        close--;
        curr.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr,n,0,0);
        return result;
    }
};
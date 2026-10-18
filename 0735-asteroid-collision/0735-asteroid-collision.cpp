class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();

        stack<int> st;

        for(int i = 0;i<n;i++){
            bool alive = true;

            while(alive && a[i]<0 && !st.empty() && st.top()>0){
                if(abs(st.top())>abs(a[i])){
                    alive = false;
                }
                else if(abs(st.top()==abs(a[i]))){
                    alive = false;
                    st.pop();
                }
                else{
                    st.pop();
                }
            }
            if(alive){
                st.push(a[i]);
            }
        }
        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
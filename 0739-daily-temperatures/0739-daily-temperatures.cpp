// to solve this question find the next greater element index and then find the difference bw the two indices and then return it 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
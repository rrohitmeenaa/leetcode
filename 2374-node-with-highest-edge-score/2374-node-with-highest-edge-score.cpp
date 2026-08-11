class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n,0);
        long long maxi = -1;
        int res = 0;
        for(int i = 0;i<n;i++){
            score[edges[i]]+=i;
            if(score[edges[i]]>maxi){
                maxi = score[edges[i]];
                res = edges[i];
            }
            else if(score[edges[i]]==maxi){
                res = min(res,edges[i]);
            }
        }
        return res;
    }
};
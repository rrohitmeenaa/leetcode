// i have to solve this question using dfs and backtracking 

class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& path){
       if(node == graph.size()-1){
        ans.push_back(path);
        return;
       }

       for(int adjnode : graph[node]){
        path.push_back(adjnode);
        dfs(adjnode,graph,ans,path);
        path.pop_back();
       }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);

        dfs(0,graph,ans,path);
        return ans;
    }
};
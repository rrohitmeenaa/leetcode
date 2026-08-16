class Solution {
public:
    void bfs(vector<vector<int>> & adj, int node , int& ans,int n){
        vector<int> dist(n,-1);
        vector<int> parent(n,-1);

        queue<int> q;
        q.push(node);
        dist[node]=0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v : adj[u]){
                
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }

                else if(parent[u]!=v){
                    int len = dist[u] + dist[v] + 1;
                    ans = min(ans,len);
                }
            }
        }
    }


    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,-1);
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            bfs(adj,i,ans,n);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
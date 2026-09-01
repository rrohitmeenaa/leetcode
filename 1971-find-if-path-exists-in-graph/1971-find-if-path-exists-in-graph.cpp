class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // apply bfs on this to find that can we reach at the destination node or not 

        queue<int> q;
        q.push(source);
        vector<int> vis(n,-1);
        vis[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination){
                        return true;
                    }

            for(int adjnode : adj[node]){
                if(vis[adjnode]==-1){
                    
                    vis[adjnode] = 1;
                    q.push(adjnode);
                }
            }
        }  
        return false;  
    }
};
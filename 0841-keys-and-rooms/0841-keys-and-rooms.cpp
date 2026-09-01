// in this question i have to traverse the whole graph and then at last i have to check that is there any room left which is not yet visited . if there is any room present then return false otherwise return true;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int adjnode : rooms[node]){
                if(vis[adjnode]==0){
                    vis[adjnode] = 1;
                    q.push(adjnode);
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};
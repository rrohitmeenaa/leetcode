class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                        q.push({i,j}); 
                        grid[i][j] = 0;
                        
                    } 
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int dx = x + dir[k].first;
                int dy = y + dir[k].second;

                if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1){
                    q.push({dx,dy});
                    grid[dx][dy] = 0;
                    
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }


       return ans;
    }
};
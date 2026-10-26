class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};

     void dfs(int i,int j,vector<vector<int>>& grid, long long& sum){
        int n = grid.size();
        int m = grid[0].size();
        sum+=grid[i][j];
        grid[i][j] = 0;
        
        for(int k=0;k<4;k++){
            int dx = i + dir[k].first;
            int dy = j + dir[k].second;
            if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]>0){
                dfs(dx,dy,grid,sum);
            }
        }

     }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        long long sum = 0;
        int cnt = 0;
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]>0){
                    sum = 0;
                    dfs(i,j,grid,sum);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
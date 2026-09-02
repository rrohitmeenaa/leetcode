class Solution {
public:
    int n,m;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return ;
        }

        grid[i][j] = '0';

        for(int k = 0;k<4;k++){
            int dx = i + dir[k].first;
            int dy = j + dir[k].second;

            dfs(dx,dy,grid);
        }

        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
// to solve this question i have to apply dfs to all the non visited 0's present in the grid . and then i have to check that wether this island is touched with the boundary or not . if it is touched with the boundary then it is not considered as to be closed 

class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    bool dfs(int i,int j,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>m-1 || j>n-1){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }

        grid[i][j] = 1;

        bool res = true;

        for(int k=0;k<4;k++){
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];

            if(!dfs(dx,dy,grid)){
                res = false;
            }
        }
        return res;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
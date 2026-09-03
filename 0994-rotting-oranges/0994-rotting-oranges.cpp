class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int mintime = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            mintime = time;
            q.pop();

            for(int k=0;k<4;k++){
                int dx = x + dir[k].first;
                int dy = y + dir[k].second;

                if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1){
                    q.push({{dx,dy},time+1});
                    grid[dx][dy]=2;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return mintime;
    }
};
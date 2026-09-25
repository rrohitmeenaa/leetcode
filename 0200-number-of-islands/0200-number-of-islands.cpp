class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int i = 0;i<4;i++){
                        int dx = dir[i][0] + x;
                        int dy = dir[i][1] + y;

                        if(dx>=0 && dy>=0 && dx<m && dy<n && grid[dx][dy]=='1'){
                            q.push({dx,dy});
                            grid[dx][dy] = '0';
                        }
                    }       
                    }
                }
            }
        }
        return cnt;
    }
};
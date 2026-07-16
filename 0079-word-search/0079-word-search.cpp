class Solution {
public:
    vector<pair<int,int>> dir = {
        {-1,0},{1,0},{0,-1},{0,1}
    };

    bool solve(vector<vector<char>>& board,string& word,int i,int j,int idx,vector<vector<int>>& vis){
        if(idx==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return false;
        }
        if(vis[i][j] == 1){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        vis[i][j] = 1;

        for(int k = 0;k<4;k++){
            int u = dir[k].first;
            int v = dir[k].second;
            if(solve(board,word,i+u,j+v,idx+1,vis)){
                return true;
            }
        }

        vis[i][j] = -1;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,i,j,0,vis)){
                    return true;
                    }
                }
                
            }
        }
        return false;
    }
};
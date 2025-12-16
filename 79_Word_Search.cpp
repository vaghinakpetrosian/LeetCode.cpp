class Solution {
public:
    int row;
    int col;
    bool dfs(vector<vector<char>>& board,string& tar,int i , int j , int ind){
        if(ind == tar.length())return true;
        if( i < 0 || j < 0 || i >= row || j >= col || board[i][j] != tar[ind]){
            return false;
        }
        char tmp = board[i][j];
        board[i][j] = '#';
        bool res = 
            dfs(board, tar, i + 1, j, ind + 1)||
            dfs(board, tar, i - 1, j, ind + 1)||
            dfs(board, tar, i, j + 1, ind + 1)||
            dfs(board, tar, i, j - 1, ind + 1);
        board[i][j] = tmp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string tar) {
        row = board.size();
        col = board[0].size();
        for(int i = 0 ; i < row ; ++i){
            for(int j = 0 ; j < col; ++j){
                if(dfs(board, tar, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

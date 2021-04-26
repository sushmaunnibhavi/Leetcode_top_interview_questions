/*Question Link: https://leetcode.com/problems/game-of-life/*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>ans(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count_of_ones=0;
                if(i-1 >=0 && board[i-1][j]==1){
                    count_of_ones++;
                }
                if(i+1 <board.size() && board[i+1][j]==1){
                    count_of_ones++;
                }
                if(j-1 >=0 && board[i][j-1]==1){
                    count_of_ones++;
                }
                if(j+1 <board[0].size() && board[i][j+1]==1){
                    count_of_ones++;
                }
                if(i+1 <board.size() && j+1<board[0].size() && board[i+1][j+1]==1){
                    count_of_ones++;
                }
                if(i-1 <board.size() && j-1<board[0].size() && board[i-1][j-1]==1){
                    count_of_ones++;
                }
                if(i+1 <board.size() && j-1<board[0].size() && board[i+1][j-1]==1){
                    count_of_ones++;
                }
                if(i-1 <board.size() && j+1<board[0].size() && board[i-1][j+1]==1){
                    count_of_ones++;
                }
                
                
                
                if(board[i][j]==1 && count_of_ones<2){
                    ans[i][j]=0;
                }
                else if(board[i][j]==1 && count_of_ones>=2 && count_of_ones<=3){
                    ans[i][j]=1;
                }
                else if(board[i][j]==1 && count_of_ones>3){
                    ans[i][j]=0;
                }
                else if(board[i][j]==0 && count_of_ones==3){
                    ans[i][j]=1;
                }
            }
        }
        
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};
/*Question Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/*/

class Solution {
public:
    int dirx[4]={0,1,0,-1};
    int diry[4]={1,0,-1,0};
    int cache[300][300];
    int dfs(vector<vector<int>>& matrix,int i,int j){
    
    if(cache[i][j]!=-1){
        return cache[i][j];
    }
    int max_sum=1;
    
    for(int k=0;k<4;k++){
        int x=i+dirx[k];
        int y=j+diry[k];
        if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size() || matrix[x][y]<=matrix[i][j])
            continue;
        else{
            int len=1+dfs(matrix,x,y);
            max_sum=max(max_sum,len);
        }
    }
    return cache[i][j]=max_sum;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        memset(cache,-1,sizeof(cache));
        int max_sum=1;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int sum=dfs(matrix,i,j);
                max_sum=max(max_sum,sum);
            }
        }
        
        return max_sum;
    }
};





/*

Time complexity:
O(nm)

*/
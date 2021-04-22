/*QUestion Link: https://leetcode.com/problems/rotate-image/*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Find transpose
        
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[0].size();j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        //Reverse each row
        
        for(int i=0;i<matrix.size();i++){
            int j=0,k=matrix[0].size()-1;
            while(j<k){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][k];
                matrix[i][k]=temp;
                j++,k--;
            }
        }
    }
};
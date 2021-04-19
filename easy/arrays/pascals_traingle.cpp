/*Question Link: https://leetcode.com/problems/pascals-triangle/*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==0){
            return ans;
        }
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        
        for(int i=1;i<numRows;i++){
            temp.clear();
            temp.push_back(1);
            
            for(int j=1;j<i;j++){
                temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            
            temp.push_back(1);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};
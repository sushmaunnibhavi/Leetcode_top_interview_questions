/*Question Link: https://leetcode.com/problems/excel-sheet-column-number/*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0,j=0;
       
        for(int i=columnTitle.length()-1;i>=0;i--){
            res+=(pow(26,j)*(columnTitle[i]-'A'+1));
            j++;
        }
        return res;
    }
};
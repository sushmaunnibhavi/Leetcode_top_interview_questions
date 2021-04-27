/*Question Link: https://leetcode.com/problems/factorial-trailing-zeroes/*/

class Solution {
public:
    int trailingZeroes(int n) {
        //find number of fives
        
        int count=0;
        for(int i=5;i<=n;i++){
            int j=i;
            while(j%5==0){
                count++;
                j=j/5;
            }
        }
        
        return count;
    }
};
/*Question Link: https://leetcode.com/problems/climbing-stairs/*/

class Solution {
public:
    int cache[46]={0};
    int climbStairs(int n) {
        if(n==0 || n==1){
            return cache[n]=1;
        }
        if(cache[n]!=0){
            return cache[n];
        }
        return cache[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};
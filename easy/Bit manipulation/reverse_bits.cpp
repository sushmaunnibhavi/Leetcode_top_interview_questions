/*Question Link: https://leetcode.com/problems/reverse-bits/*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int a=0;
        for(int i=0;i<31;i++){
            a=a | (n&1);
            a<<=1;
            n>>=1;
        }
        
        a=a | (n&1);
        return a;
    }
};
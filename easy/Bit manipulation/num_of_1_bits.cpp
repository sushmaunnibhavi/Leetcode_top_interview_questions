/*Question Link: https://leetcode.com/problems/number-of-1-bits/*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_of_1_bits=0;
        while(n){
            if(n & 1 == 1){
                num_of_1_bits+=1;
            }
            n>>=1;
        }
        
        return num_of_1_bits;
    }
};
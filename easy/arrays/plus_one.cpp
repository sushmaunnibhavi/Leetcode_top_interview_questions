/*Question Link: https://leetcode.com/problems/plus-one/*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum=0,carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            sum=carry+digits[i];
            digits[i]=sum%10;
            carry=sum/10;
        }
        
        if(carry>0){
            digits.insert(digits.begin(),carry);
        }
        
        return digits;
    }
};
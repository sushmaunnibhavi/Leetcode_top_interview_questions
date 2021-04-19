/*Question Link: https://leetcode.com/problems/missing-number/*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Find sum from 0 to nums.size()
        
        int sum=0;
        for(int i=0;i<=nums.size();i++){
            sum+=i;
        }
        
        int missing_num=sum;
        for(int i=0;i<nums.size();i++){
            missing_num-=nums[i];
        }
        
        return missing_num;
    }
};
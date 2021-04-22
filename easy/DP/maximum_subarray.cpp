/*https://leetcode.com/problems/maximum-subarray/*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN,sum_till_now=0;
        
        for(int i=0;i<nums.size();i++){
            sum_till_now+=nums[i];
            if(sum_till_now<nums[i]){
                sum_till_now=nums[i];
            }
            max_sum=max(max_sum,sum_till_now);
        }
        
        return max_sum;
    }
};
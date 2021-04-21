/*Question Link: https://leetcode.com/problems/product-of-array-except-self/*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left_prefix_mul(nums.size(),1);
        vector<int>right_prefix_mul(nums.size(),1);
        vector<int>ans;
        if(nums.size()==0){
            return ans;
        }
        
        left_prefix_mul[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            left_prefix_mul[i]=left_prefix_mul[i-1]*nums[i];
        }
        right_prefix_mul[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            right_prefix_mul[i]=right_prefix_mul[i+1]*nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            int left_mul= i==0 ? 1 : left_prefix_mul[i-1];
            int right_mul= i==(nums.size()-1) ? 1 : right_prefix_mul[i+1];
            
            ans.push_back(left_mul*right_mul);
        }
        
        return ans;
    }
};
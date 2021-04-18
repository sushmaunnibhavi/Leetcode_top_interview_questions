/*Question Link: https://leetcode.com/problems/subsets/*/

class Solution {
public:
    void findSubsets(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int idx){
        ans.push_back(temp);
        if(idx>=nums.size()){
            return;
        }
        
        
        
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            findSubsets(nums,temp,ans,i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        findSubsets(nums,temp,ans,0);
        return ans;
    }
};

/*

Time complexity: O(n^2)

*/
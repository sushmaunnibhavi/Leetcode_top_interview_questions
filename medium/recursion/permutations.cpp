/*Question link: https://leetcode.com/problems/permutations/*/

class Solution {
public:
    void findPermutations(vector<int>& nums,vector<vector<int>>& ans,vector<bool>& isChosen,vector<int>& temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(isChosen[i]==false){
                temp.push_back(nums[i]);
                isChosen[i]=true;
                findPermutations(nums,ans,isChosen,temp);
                isChosen[i]=false;
                temp.pop_back();
            }
        }
        
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>isChosen(nums.size(),false);
        
        findPermutations(nums,ans,isChosen,temp);
        return ans;
    }
};

/*
    Time complexity:
    O(n^n) because we have n choices for each
*/
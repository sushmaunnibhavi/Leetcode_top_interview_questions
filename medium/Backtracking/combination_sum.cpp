/*Question Link: https://leetcode.com/problems/combination-sum/*/

class Solution {
public:
    void findCombinationSum(vector<int>& candidates, int target,vector<vector<int>> &res,vector<int> &temp,int sum,int idx){
        if(sum>target){
            return;
        }
        if(sum==target){
            res.push_back(temp);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            findCombinationSum(candidates,target,res,temp,sum+candidates[i],i);
            temp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int sum=0;
        findCombinationSum(candidates,target,res,temp,sum,0);
        return res;
    }
};
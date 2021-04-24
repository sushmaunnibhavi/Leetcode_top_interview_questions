/*Question Link: https://leetcode.com/problems/two-sum/*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        vector<pair<int,int>>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            if(temp[i].first+temp[j].first==target){
                res.push_back(temp[i].second);
                res.push_back(temp[j].second);
                return res;
            }
            else if(temp[i].first+temp[j].first<target){
                i++;
            }
            else{
                j--;
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
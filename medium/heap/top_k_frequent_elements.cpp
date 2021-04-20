/*Question link: https://leetcode.com/problems/top-k-frequent-elements/*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
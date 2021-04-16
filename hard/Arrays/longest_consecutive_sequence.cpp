/*Question Link: https://leetcode.com/problems/longest-consecutive-sequence/*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        int curr_len=0,max_len=1,curr_num;
        
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1) == s.end()){
                curr_len=1;
                curr_num=nums[i];
                while(s.find(curr_num+1)!=s.end()){
                    s.erase(curr_num+1);
                    curr_len+=1;
                    curr_num+=1;
                }
                
            }
            
            max_len=max(max_len,curr_len);
        }
        
        return max_len;
    }
};

/*

Time Complexity:
For inserting n elements into set->nlogn
For finding element in set->logn
We erase elements that we search so that we dont keep searching for it again,hence
reducing time complexity

Hence for loop has time complexity of nlogn

=>Time Complexity is nlogn

*/
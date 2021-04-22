/*Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,i=0;
        while(i<nums.size()){
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                i++;
            }
            
            if(i<nums.size()){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        
        return j;
    }
};
/*Question Link: https://leetcode.com/problems/majority-element/*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        
        int i=0;
        while(i<nums.size()){
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[i]){
                j++;
            }
            int len=j-i;
            if(len>(nums.size()/2)){
                return nums[i];
            }
            i=j;
        }
        return 0;
    }
};

/*

Time Complexity:
Sorting: O(nlogn)
while loop is O(n)
Total=O(nlogn)

*/
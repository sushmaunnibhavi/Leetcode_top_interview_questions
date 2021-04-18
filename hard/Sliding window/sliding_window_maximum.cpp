/*Question Link: https://leetcode.com/problems/sliding-window-maximum/*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        int i=0,j=0;
        while(j<nums.size()){
            while(!dq.empty() && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            k--;
            if(k==0){
                res.push_back(dq.front());
                if(nums[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                k++;
            }
            j++;
        }
        
        return res;
    }
};


/*

Time Complexity: O(n)

*/
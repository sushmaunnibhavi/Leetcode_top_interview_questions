/*Question link: https://leetcode.com/problems/trapping-rain-water/*/


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        //Find largest ht towards left and right;
        
        //largest ht from left->right
        
        vector<int>lt(height.size(),0);
        int curr_max=height[0];
        for(int i=1;i<height.size();i++){
            lt[i]=curr_max;
            curr_max=max(curr_max,height[i]);
        }
        
        //largest ht from right->left
        
        vector<int>rt(height.size(),0);
        curr_max=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            rt[i]=curr_max;
            curr_max=max(curr_max,height[i]);
        }
        
        
        int water=0;
        
        for(int i=1;i<height.size()-1;i++){
            int val=min(lt[i],rt[i]);
            
            if(height[i]>=val)
                continue;
            else{
                water+=(val-height[i]);
            }
        }
        
        return water;
    }
};


/*

Time Complexity:
O(n)

*/


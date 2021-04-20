/*Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        
        int buy=INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            buy=min(buy,prices[i]);
            
            if(prices[i]>buy){
                profit=max(profit,prices[i]-buy);
            }
        }
        
        return profit;
    }
};
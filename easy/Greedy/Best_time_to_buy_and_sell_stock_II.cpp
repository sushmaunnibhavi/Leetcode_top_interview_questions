/*Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        We can have only BSBS
        buy when price less, sell when you reach a peak, collect profit
        */
        
        int i=0,j=0,max_profit=0;
        while(j+1 < prices.size()){
            if(prices[j]<prices[j+1]){
                j++;
            }
            else if(prices[j]>prices[j+1]){
                //collect profit
                
                max_profit+=(prices[j]-prices[i]);
                j++;
                i=j;
            }
            else{
                j++;
            }
        }
        max_profit+=(prices[j]-prices[i]);
        return max_profit;
    }
};


/*

Time Complexity: O(n)

*/
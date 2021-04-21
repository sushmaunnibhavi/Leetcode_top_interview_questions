/*Question Link: https://leetcode.com/problems/happy-number/*/

class Solution {
public:
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        if(n==4){
            return false;
        }
        
        while(n!=1){
            if(n==4){
                return false;
            }
            int sum=0;
            while(n){
                int rem=n%10;
                rem=rem*rem;
                sum+=rem;
                n=n/10;
            }
            
            n=sum;
        }
        
        return true;
    }
};
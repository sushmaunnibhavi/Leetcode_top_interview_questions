/*Question Link: https://leetcode.com/problems/fizz-buzz/*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        
        string div_by_3="Fizz",div_by_5="Buzz",div_by_3_and_5="FizzBuzz";
        
        for(int i = 1 ; i <= n; i++){
            if(i % 3 == 0 && i % 5 == 0){
                ans.push_back(div_by_3_and_5);
            }
            else if(i % 3 == 0){
                ans.push_back(div_by_3);
            }
            else if(i % 5 == 0){
                ans.push_back(div_by_5);
            }
            else{
                ans.push_back(to_string(i));
            }
        }
        
        return ans;
    }
};